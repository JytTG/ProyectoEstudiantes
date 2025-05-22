#include <iostream>
#include <string>
#include <vector>
#include "EloquentORM.h"
#include "MySQLConexion.h"

using namespace std;

// Colores para consola (Windows CMD)
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// Clase Curso
class Curso {
public:
    int id;
    string nombre;

    Curso() {}

    void crear() {
        cout << "Nombre del curso: ";
        getline(cin, nombre);
        EloquentORM::insert("cursos", { {"nombre", nombre} });
        cout << GREEN << "Curso agregado con éxito.\n" << RESET;
    }

    static void listar() {
        auto cursos = EloquentORM::select("cursos", "*");
        cout << YELLOW << "== Lista de Cursos ==\n" << RESET;
        for (auto& curso : cursos) {
            cout << curso["id"] << " - " << curso["nombre"] << endl;
        }
    }

    void actualizar() {
        listar();
        cout << "ID del curso a editar: ";
        cin >> id; cin.ignore();
        cout << "Nuevo nombre: ";
        getline(cin, nombre);
        EloquentORM::update("cursos", id, { {"nombre", nombre} });
        cout << GREEN << "Curso actualizado.\n" << RESET;
    }

    void eliminar() {
        listar();
        cout << "ID del curso a eliminar: ";
        cin >> id; cin.ignore();
        EloquentORM::del("cursos", id);
        cout << RED << "Curso eliminado.\n" << RESET;
    }
};

// Clase Estudiante
class Estudiante {
public:
    int id, curso_id;
    string nombre;

    Estudiante() {}

    void crear() {
        cout << "Nombre del estudiante: ";
        getline(cin, nombre);
        Curso::listar();
        cout << "ID del curso: ";
        cin >> curso_id; cin.ignore();
        EloquentORM::insert("estudiantes", {
            {"nombre", nombre},
            {"curso_id", to_string(curso_id)}
        });
        cout << GREEN << "Estudiante agregado.\n" << RESET;
    }

    static void listar() {
        auto ests = EloquentORM::query("SELECT estudiantes.id, estudiantes.nombre, cursos.nombre AS curso FROM estudiantes LEFT JOIN cursos ON estudiantes.curso_id = cursos.id;");
        cout << YELLOW << "== Lista de Estudiantes ==\n" << RESET;
        for (auto& est : ests) {
            cout << est["id"] << " - " << est["nombre"] << " | Curso: " << est["curso"] << endl;
        }
    }

    void actualizar() {
        listar();
        cout << "ID del estudiante a editar: ";
        cin >> id; cin.ignore();
        cout << "Nuevo nombre: ";
        getline(cin, nombre);
        Curso::listar();
        cout << "Nuevo curso ID: ";
        cin >> curso_id; cin.ignore();
        EloquentORM::update("estudiantes", id, {
            {"nombre", nombre},
            {"curso_id", to_string(curso_id)}
        });
        cout << GREEN << "Estudiante actualizado.\n" << RESET;
    }

    void eliminar() {
        listar();
        cout << "ID del estudiante a eliminar: ";
        cin >> id; cin.ignore();
        EloquentORM::del("estudiantes", id);
        cout << RED << "Estudiante eliminado.\n" << RESET;
    }
};

// Menú principal
void mostrar_menu() {
    int opcion;
    Curso curso;
    Estudiante estudiante;

    do {
        cout << "\n" << YELLOW << "== Menú Principal ==" << RESET << endl;
        cout << "1. Crear curso\n";
        cout << "2. Listar cursos\n";
        cout << "3. Editar curso\n";
        cout << "4. Eliminar curso\n";
        cout << "5. Crear estudiante\n";
        cout << "6. Listar estudiantes\n";
        cout << "7. Editar estudiante\n";
        cout << "8. Eliminar estudiante\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion; cin.ignore();

        switch(opcion) {
            case 1: curso.crear(); break;
            case 2: Curso::listar(); break;
            case 3: curso.actualizar(); break;
            case 4: curso.eliminar(); break;
            case 5: estudiante.crear(); break;
            case 6: Estudiante::listar(); break;
            case 7: estudiante.actualizar(); break;
            case 8: estudiante.eliminar(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << RED << "Opción inválida\n" << RESET;
        }
    } while(opcion != 0);
}

int main() {
    MySQLConexion::conectar("localhost", "root", "", "sistema_estudiantes");
    mostrar_menu();
    return 0;
}
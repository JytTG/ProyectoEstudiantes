#include <iostream>
#include <windows.h> // Para colores en consola de Windows
using namespace std;

// incluir clases
#include "Cliente.h"
#include "Producto.h"
#include "Orden.h"  
#include "DetalleOrden.h"

// Función para establecer color en consola
void set_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Función para mostrar el menú principal
void mostrar_menu() {
    set_color(11); // Azul claro
    cout << "\n==============================\n";
    cout << "     SISTEMA DE CLIENTES\n";
    cout << "==============================\n";
    set_color(15); // Blanco
    cout << "1. Gestionar Clientes\n";
    cout << "2. Gestionar Productos\n";
    cout << "3. Gestionar Ordenes\n";
    cout << "4. Gestionar Detalles de Orden\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
}

// Submenú genérico para CRUD
void mostrar_submenu(const string &entidad) {
    set_color(10); // Verde claro
    cout << "\n--- CRUD de " << entidad << " ---\n";
    set_color(15);
    cout << "1. Crear\n";
    cout << "2. Leer\n";
    cout << "3. Actualizar\n";
    cout << "4. Eliminar\n";
    cout << "0. Volver al menu principal\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    int opcionMenu = -1;

    while (opcionMenu != 0) {
        mostrar_menu();
        cin >> opcionMenu;
        int opcionCRUD;

        switch (opcionMenu) {
            case 1: // Clientes
                do {
                    mostrar_submenu("Clientes");
                    cin >> opcionCRUD;
                    switch (opcionCRUD) {
                        case 1:
                            // cliente.crear();
                            break;
                        case 2:
                            // cliente.leer();
                            break;
                        case 3:
                            // cliente.actualizar();
                            break;
                        case 4:
                            // cliente.eliminar();
                            break;
                    }
                } while (opcionCRUD != 0);
                break;

            case 2: // Productos
                do {
                    mostrar_submenu("Productos");
                    cin >> opcionCRUD;
                    switch (opcionCRUD) {
                        case 1:
                            // producto.crear();
                            break;
                        case 2:
                            // producto.leer();
                            break;
                        case 3:
                            // producto.actualizar();
                            break;
                        case 4:
                            // producto.eliminar();
                            break;
                    }
                } while (opcionCRUD != 0);
                break;

            case 3: // Ordenes
                do {
                    mostrar_submenu("Ordenes");
                    cin >> opcionCRUD;
                    switch (opcionCRUD) {
                        case 1:
                            // orden.crear();
                            break;
                        case 2:
                            // orden.leer();
                            break;
                        case 3:
                            // orden.actualizar();
                            break;
                        case 4:
                            // orden.eliminar();
                            break;
                    }
                } while (opcionCRUD != 0);
                break;

            case 4: // Detalle de Orden
                do {
                    mostrar_submenu("Detalle de Orden");
                    cin >> opcionCRUD;
                    switch (opcionCRUD) {
                        case 1:
                            // detalleOrden.crear();
                            break;
                        case 2:
                            // detalleOrden.leer();
                            break;
                        case 3:
                            // detalleOrden.actualizar();
                            break;
                        case 4:
                            // detalleOrden.eliminar();
                            break;
                    }
                } while (opcionCRUD != 0);
                break;

            case 0:
                set_color(12); // Rojo
                cout << "\nSaliendo del sistema...\n";
                break;

            default:
                set_color(14); // Amarillo
                cout << "\nOpcion no valida. Intente de nuevo.\n";
                break;
        }
    }

    return 0;
}

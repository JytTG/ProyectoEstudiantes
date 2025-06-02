#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include "EloquentORM.h"

using namespace std;

class Producto : public EloquentORM {
public:
    Producto() {
        table = "productos";
    }

    void crear() {
        string nombre;
        double precio;
        cin.ignore();
        cout << "Ingrese nombre del producto: ";
        getline(cin, nombre);
        cout << "Ingrese precio: ";
        cin >> precio;

        insert({
            {"nombre", nombre},
            {"precio", to_string(precio)}
        });

        cout << "Producto creado exitosamente.\n";
    }

    void leer() {
        vector<map<string, string>> registros = getAll();

        for (auto& fila : registros) {
            cout << fila["id"] << " | " << fila["nombre"] << " | Q" << fila["precio"] << endl;
        }
    }

    void actualizar() {
        int id;
        string nombre;
        double precio;
        cout << "Ingrese ID del producto: ";
        cin >> id;
        cin.ignore();
        cout << "Nuevo nombre: ";
        getline(cin, nombre);
        cout << "Nuevo precio: ";
        cin >> precio;

        updateById(to_string(id), {
            {"nombre", nombre},
            {"precio", to_string(precio)}
        });

        cout << "Producto actualizado.\n";
    }

    void eliminar() {
        int id;
        cout << "Ingrese ID del producto a eliminar: ";
        cin >> id;

        removeById(to_string(id));
        cout << "Producto eliminado.\n";
    }
};

#endif

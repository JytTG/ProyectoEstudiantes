#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include "EloquentORM.h"

using namespace std;

class Cliente : public EloquentORM {
public:
    Cliente() {
        table = "clientes";
    }

    void crear() {
        string nombres, apellidos;
        cin.ignore();
        cout << "Ingrese nombres: ";
        getline(cin, nombres);
        cout << "Ingrese apellidos: ";
        getline(cin, apellidos);

        insert({
            {"nombres", nombres},
            {"apellidos", apellidos}
        });

        cout << "Cliente creado exitosamente.\n";
    }

    void leer() {
        vector<map<string, string>> registros = getAll();

        for (auto& fila : registros) {
            cout << fila["id"] << " | " << fila["nombres"] << " " << fila["apellidos"] << endl;
        }
    }

    void actualizar() {
        int id;
        string nombres, apellidos;
        cout << "Ingrese ID del cliente: ";
        cin >> id;
        cin.ignore();
        cout << "Nuevo nombre: ";
        getline(cin, nombres);
        cout << "Nuevo apellido: ";
        getline(cin, apellidos);

        updateById(to_string(id), {
            {"nombres", nombres},
            {"apellidos", apellidos}
        });

        cout << "Cliente actualizado.\n";
    }

    void eliminar() {
        int id;
        cout << "Ingrese ID del cliente a eliminar: ";
        cin >> id;

        removeById(to_string(id));
        cout << "Cliente eliminado.\n";
    }
};

#endif

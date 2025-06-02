#ifndef ORDEN_H
#define ORDEN_H

#include <iostream>
#include <string>
#include "EloquentORM.h"

using namespace std;

class Orden : public EloquentORM {
public:
    Orden() {
        table = "ordenes";
    }

    void crear() {
        int clienteId;
        string fecha;
        cout << "Ingrese ID del cliente: ";
        cin >> clienteId;
        cin.ignore();
        cout << "Ingrese fecha (YYYY-MM-DD): ";
        getline(cin, fecha);

        insert({
            {"cliente_id", to_string(clienteId)},
            {"fecha", fecha}
        });

        cout << "Orden creada exitosamente.\n";
    }

    void leer() {
        vector<map<string, string>> registros = getAll();

        for (auto& fila : registros) {
            cout << fila["id"] << " | Cliente ID: " << fila["cliente_id"] << " | Fecha: " << fila["fecha"] << endl;
        }
    }

    void actualizar() {
        int id, clienteId;
        string fecha;
        cout << "Ingrese ID de la orden: ";
        cin >> id;
        cout << "Nuevo ID del cliente: ";
        cin >> clienteId;
        cin.ignore();
        cout << "Nueva fecha (YYYY-MM-DD): ";
        getline(cin, fecha);

        updateById(to_string(id), {
            {"cliente_id", to_string(clienteId)},
            {"fecha", fecha}
        });

        cout << "Orden actualizada.\n";
    }

    void eliminar() {
        int id;
        cout << "Ingrese ID de la orden a eliminar: ";
        cin >> id;

        removeById(to_string(id));
        cout << "Orden eliminada.\n";
    }
};

#endif

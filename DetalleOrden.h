#ifndef DETALLEORDEN_H
#define DETALLEORDEN_H

#include <iostream>
#include <string>
#include "EloquentORM.h"

using namespace std;

class DetalleOrden : public EloquentORM {
public:
    DetalleOrden() {
        table = "detalle_orden";
    }

    void crear() {
        int ordenId, productoId, cantidad;
        cout << "Ingrese ID de la orden: ";
        cin >> ordenId;
        cout << "Ingrese ID del producto: ";
        cin >> productoId;
        cout << "Ingrese cantidad: ";
        cin >> cantidad;

        insert({
            {"orden_id", to_string(ordenId)},
            {"producto_id", to_string(productoId)},
            {"cantidad", to_string(cantidad)}
        });

        cout << "Detalle de orden creado exitosamente.\n";
    }

    void leer() {
        vector<map<string, string>> registros = getAll();

        for (auto& fila : registros) {
            cout << "ID: " << fila["id"] 
                 << " | Orden ID: " << fila["orden_id"] 
                 << " | Producto ID: " << fila["producto_id"] 
                 << " | Cantidad: " << fila["cantidad"] << endl;
        }
    }

    void actualizar() {
        int id, ordenId, productoId, cantidad;
        cout << "Ingrese ID del detalle a actualizar: ";
        cin >> id;
        cout << "Nuevo ID de la orden: ";
        cin >> ordenId;
        cout << "Nuevo ID del producto: ";
        cin >> productoId;
        cout << "Nueva cantidad: ";
        cin >> cantidad;

        updateById(to_string(id), {
            {"orden_id", to_string(ordenId)},
            {"producto_id", to_string(productoId)},
            {"cantidad", to_string(cantidad)}
        });

        cout << "Detalle de orden actualizado.\n";
    }

    void eliminar() {
        int id;
        cout << "Ingrese ID del detalle a eliminar: ";
        cin >> id;

        removeById(to_string(id));
        cout << "Detalle de orden eliminado.\n";
    }
};

#endif

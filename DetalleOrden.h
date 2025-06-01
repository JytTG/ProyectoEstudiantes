#ifndef DETALLE_ORDEN_H
#define DETALLE_ORDEN_H

#include <iostream>
using namespace std;

class DetalleOrden {
private:
    int id;
    int ordenId;
    int productoId;
    int cantidad;

public:
    DetalleOrden() {}
    DetalleOrden(int id, int ordenId, int productoId, int cantidad) {
        this->id = id;
        this->ordenId = ordenId;
        this->productoId = productoId;
        this->cantidad = cantidad;
    }

    void set_id(int id) { this->id = id; }
    int get_id() const { return id; }

    void set_orden_id(int ordenId) { this->ordenId = ordenId; }
    int get_orden_id() const { return ordenId; }

    void set_producto_id(int productoId) { this->productoId = productoId; }
    int get_producto_id() const { return productoId; }

    void set_cantidad(int cantidad) { this->cantidad = cantidad; }
    int get_cantidad() const { return cantidad; }

    void crear();
    void leer();
    void actualizar();
    void eliminar();
};

#endif

#ifndef ORDEN_H
#define ORDEN_H

#include <iostream>
#include <string>
using namespace std;

class Orden {
private:
    int id;
    int clienteId;
    string fecha;

public:
    Orden() {}
    Orden(int id, int clienteId, string fecha) {
        this->id = id;
        this->clienteId = clienteId;
        this->fecha = fecha;
    }

    void set_id(int id) { this->id = id; }
    int get_id() const { return id; }

    void set_cliente_id(int clienteId) { this->clienteId = clienteId; }
    int get_cliente_id() const { return clienteId; }

    void set_fecha(string fecha) { this->fecha = fecha; }
    string get_fecha() const { return fecha; }

    void crear();
    void leer();
    void actualizar();
    void eliminar();
};

#endif

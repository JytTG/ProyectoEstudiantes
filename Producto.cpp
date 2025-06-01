#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
using namespace std;

class Producto {
private:
    int id;
    string nombre;
    double precio;

public:
    Producto() {}
    Producto(int id, string nombre, double precio) {
        this->id = id;
        this->nombre = nombre;
        this->precio = precio;
    }

    void set_id(int id) { this->id = id; }
    int get_id() const { return id; }

    void set_nombre(string nombre) { this->nombre = nombre; }
    string get_nombre() const { return nombre; }

    void set_precio(double precio) { this->precio = precio; }
    double get_precio() const { return precio; }

    void crear();
    void leer();
    void actualizar();
    void eliminar();
};

#endif

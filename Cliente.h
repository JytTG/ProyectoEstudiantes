#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
    int id;
    string nombre;
    string correo;

public:
    // Constructor
    Cliente() {}

    Cliente(int id, string nombre, string correo) {
        this->id = id;
        this->nombre = nombre;
        this->correo = correo;
    }

    // Getters y Setters
    void set_id(int id) { this->id = id; }
    int get_id() const { return id; }

    void set_nombre(string nombre) { this->nombre = nombre; }
    string get_nombre() const { return nombre; }

    void set_correo(string correo) { this->correo = correo; }
    string get_correo() const { return correo; }

    // Métodos CRUD
    void crear();
    void leer();
    void actualizar();
    void eliminar();
};

#endif

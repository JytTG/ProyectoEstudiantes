#include <iostream>
#include "Cliente.h"
#include "Producto.h"
#include "Orden.h"
#include "DetalleOrden.h"
#include "MySQLConexion.h"
#include "EloquentORM.h"

using namespace std;

void menu_cliente(Cliente &cliente) {
    int opcion;
    do {
        cout << "\n-- Menu Cliente --\n";
        cout << "1. Crear cliente\n2. Ver clientes\n3. Actualizar cliente\n4. Eliminar cliente\n5. Volver\n";
        cout << "Elija opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: cliente.crear(); break;
            case 2: cliente.leer(); break;
            case 3: cliente.actualizar(); break;
            case 4: cliente.eliminar(); break;
        }
    } while (opcion != 5);
}

void menu_producto(Producto &producto) {
    int opcion;
    do {
        cout << "\n-- Menu Producto --\n";
        cout << "1. Crear producto\n2. Ver productos\n3. Actualizar producto\n4. Eliminar producto\n5. Volver\n";
        cout << "Elija opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: producto.crear(); break;
            case 2: producto.leer(); break;
            case 3: producto.actualizar(); break;
            case 4: producto.eliminar(); break;
        }
    } while (opcion != 5);
}

void menu_orden(Orden &orden) {
    int opcion;
    do {
        cout << "\n-- Menu Orden --\n";
        cout << "1. Crear orden\n2. Ver ordenes\n3. Actualizar orden\n4. Eliminar orden\n5. Volver\n";
        cout << "Elija opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: orden.crear(); break;
            case 2: orden.leer(); break;
            case 3: orden.actualizar(); break;
            case 4: orden.eliminar(); break;
        }
    } while (opcion != 5);
}

void menu_detalle_orden(DetalleOrden &detalle) {
    int opcion;
    do {
        cout << "\n-- Menu Detalle Orden --\n";
        cout << "1. Crear detalle\n2. Ver detalles\n3. Actualizar detalle\n4. Eliminar detalle\n5. Volver\n";
        cout << "Elija opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: detalle.crear(); break;
            case 2: detalle.leer(); break;
            case 3: detalle.actualizar(); break;
            case 4: detalle.eliminar(); break;
        }
    } while (opcion != 5);
}

int main() {

    MySQLConexion conn("root", "150305", "sistema_clientes");

    if (!conn.open()) {
        cerr << "No se pudo conectar a la base de datos." << endl;
        return 1;
    } else {
        cout << "Conexión establecida con la base de datos.\n";
    }

    Cliente cliente;
    Producto producto;
    Orden orden;
    DetalleOrden detalle;

    int opcion;
    do {
        cout << "\n=== Sistema de Clientes y Órdenes ===\n";
        cout << "1. Clientes\n2. Productos\n3. Ordenes\n4. Detalle de Orden\n5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1: menu_cliente(cliente); break;
            case 2: menu_producto(producto); break;
            case 3: menu_orden(orden); break;
            case 4: menu_detalle_orden(detalle); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }

    } while (opcion != 5);

    return 0;
}

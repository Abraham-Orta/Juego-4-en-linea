#include "negocio/Jugador.h"

Jugador::Jugador(int id, const std::string& nombre) : id(id), nombre(nombre) {}

int Jugador::getId() const {
    return id;
}

std::string Jugador::getNombre() const {
    return nombre;
}

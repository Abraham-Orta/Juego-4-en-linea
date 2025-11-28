#include "negocio/JugadorHumano.h"

JugadorHumano::JugadorHumano(int id, const std::string& nombre) : Jugador(id, nombre) {}

int JugadorHumano::obtenerMovimiento(const Tablero& t) {
    // La lógica real se maneja en la InterfazConsola
    return -1; // Placeholder
}

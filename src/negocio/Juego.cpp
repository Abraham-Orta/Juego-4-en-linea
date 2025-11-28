#include "negocio/Juego.h"
#include "negocio/JugadorHumano.h" // Añadido para dynamic_cast
#include <string>
#include <sstream>

Juego::Juego(Jugador* j1, Jugador* j2, int filas, int columnas)
    : tablero(filas, columnas), jugador1(j1), jugador2(j2), turnoActual(1), modoFinalizacion(0) {}

Juego::~Juego() {
    delete jugador1;
    delete jugador2;
}

bool Juego::ejecutarTurno(int columna) {
    int fila = tablero.insertarFicha(columna, turnoActual);
    if (fila != -1) {
        if (tablero.cuatroEnLinea(fila, columna, turnoActual)) {
            modoFinalizacion = turnoActual;
        }
        return true;
    }
    return false;
}

int Juego::obtenerGanador() {
    return modoFinalizacion;
}

void Juego::cambiarTurno() {
    turnoActual = (turnoActual == 1) ? 2 : 1;
}

const Tablero& Juego::getTablero() const {
    return tablero;
}

int Juego::getTurnoActual() const {
    return turnoActual;
}

Jugador* Juego::getJugadorActual() const {
    return (turnoActual == 1) ? jugador1 : jugador2;
}

std::string Juego::serializar() const {
    std::stringstream ss;
    // Serializar datos del juego
    ss << turnoActual << "\n";
    ss << modoFinalizacion << "\n";
    // Serializar tipo de jugadores (simplificado)
    ss << (dynamic_cast<JugadorHumano*>(jugador1) ? "H" : "A") << "\n";
    ss << (dynamic_cast<JugadorHumano*>(jugador2) ? "H" : "A") << "\n";
    // Serializar tablero
    ss << tablero.serializar();
    return ss.str();
}
#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"
#include "Jugador.h"
#include <string>

class Juego {
private:
    Tablero tablero;
    Jugador* jugador1;
    Jugador* jugador2;
    int turnoActual;
    int modoFinalizacion;

public:
    Juego(Jugador* j1, Jugador* j2, int filas = 6, int columnas = 7);
    ~Juego();

    Juego(const Juego&) = delete;
    Juego& operator=(const Juego&) = delete;

    bool ejecutarTurno(int columna);
    int obtenerGanador();
    void cambiarTurno();
    const Tablero& getTablero() const;
    int getTurnoActual() const;
    Jugador* getJugadorActual() const;

    // Re-introduciendo serialización
    std::string serializar() const;
    // La deserialización es más compleja, la dejaremos para Persistencia
};

#endif // JUEGO_H

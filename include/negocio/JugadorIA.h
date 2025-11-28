#ifndef JUGADORIA_H
#define JUGADORIA_H

#include "Jugador.h"
#include <string>

class Tablero;

class JugadorIA : public Jugador {
private:
    int profundidad;
    int minimax(const Tablero& t, int profundidad, int alfa, int beta, bool max);
    int evaluarTablero(const Tablero& t) const;
    int jugadaGanadoraInmediata(const Tablero& t) const;

public:
    JugadorIA(int id, const std::string& nombre, int profundidad = 5);
    int obtenerMovimiento(const Tablero& t) override;
};

#endif // JUGADORIA_H

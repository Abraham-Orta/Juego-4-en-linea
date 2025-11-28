#ifndef JUGADORHUMANO_H
#define JUGADORHUMANO_H

#include "Jugador.h"
#include <string>

class JugadorHumano : public Jugador {
public:
    JugadorHumano(int id, const std::string& nombre);
    int obtenerMovimiento(const Tablero& t) override;
};

#endif // JUGADORHUMANO_H

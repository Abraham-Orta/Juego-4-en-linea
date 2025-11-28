#ifndef JUGADOR_H
#define JUGADOR_H

#include <string> // Permitir std::string

class Tablero;

class Jugador {
protected:
    int id;
    std::string nombre; // Revertido a std::string

public:
    Jugador(int id, const std::string& nombre);
    virtual ~Jugador() = default; // El destructor por defecto es suficiente

    virtual int obtenerMovimiento(const Tablero& t) = 0;
    int getId() const;
    std::string getNombre() const;
};

#endif // JUGADOR_H

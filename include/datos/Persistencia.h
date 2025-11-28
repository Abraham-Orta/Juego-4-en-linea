#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <string>

class Juego;

class Persistencia {
public:
    static bool guardarPartida(const Juego& j, const std::string& ruta);
    
    // Devuelve un puntero a un nuevo juego creado en el heap
    static Juego* cargarPartida(const std::string& ruta);
};

#endif // PERSISTENCIA_H

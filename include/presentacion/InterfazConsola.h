#ifndef INTERFAZCONSOLA_H
#define INTERFAZCONSOLA_H

#include <iostream>
#include <string>

class Tablero;

class InterfazConsola {
public:
    void mostrarMenuPrincipal();
    int mostrarMenuNuevoJuego();
    void mostrarTablero(const Tablero& tablero);
    int solicitarColumna(int idJugador);
    void mostrarMensaje(const std::string& msg);
    bool preguntarGuardar();
    std::string preguntarCargar(); // Revertido a std::string
};

#endif // INTERFAZCONSOLA_H

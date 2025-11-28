#include "presentacion/InterfazConsola.h"
#include "negocio/Juego.h"
#include "negocio/JugadorHumano.h"
#include "negocio/JugadorIA.h"
#include "datos/Persistencia.h"
#include <iostream>
#include <string>

// Función para gestionar el bucle principal de una partida
void cicloDeJuego(Juego& juego, InterfazConsola& interfaz) {
    int ganador = 0;
    while (ganador == 0 && !juego.getTablero().tableroLleno()) {
        interfaz.mostrarTablero(juego.getTablero());
        Jugador* jugadorActual = juego.getJugadorActual();
        int columna = -1;

        if (dynamic_cast<JugadorHumano*>(jugadorActual)) {
            columna = interfaz.solicitarColumna(jugadorActual->getId());
        } else {
            interfaz.mostrarMensaje("Turno de la IA...");
            columna = jugadorActual->obtenerMovimiento(juego.getTablero());
            interfaz.mostrarMensaje("La IA ha jugado en la columna " + std::to_string(columna));
        }

        if (juego.ejecutarTurno(columna)) {
            ganador = juego.obtenerGanador();
            if (ganador == 0) {
                juego.cambiarTurno();
            }
        } else {
            interfaz.mostrarMensaje("Columna llena o inválida. Intente de nuevo.");
        }
    }

    interfaz.mostrarTablero(juego.getTablero());
    if (ganador != 0) {
        interfaz.mostrarMensaje("¡El jugador " + std::to_string(ganador) + " ha ganado!");
    } else {
        interfaz.mostrarMensaje("¡Empate! El tablero está lleno.");
    }
    
    if(interfaz.preguntarGuardar()){
        std::string ruta = "partida.txt";
        if(Persistencia::guardarPartida(juego, ruta)){
            interfaz.mostrarMensaje("Partida guardada en " + ruta);
        } else {
            interfaz.mostrarMensaje("No se pudo guardar la partida.");
        }
    }
}

int main() {
    InterfazConsola interfaz;
    int opcion = 0;

    do {
        interfaz.mostrarMenuPrincipal();
        std::cin >> opcion;
        std::cin.ignore(10000, '\n'); // Limpiar buffer

        if (opcion == 1) { // Nuevo Juego
            int modo = interfaz.mostrarMenuNuevoJuego();
            Jugador *j1 = nullptr, *j2 = nullptr;

            if (modo == 1) { // H vs H
                j1 = new JugadorHumano(1, "Humano 1");
                j2 = new JugadorHumano(2, "Humano 2");
            } else if (modo == 2) { // H vs IA
                j1 = new JugadorHumano(1, "Humano");
                j2 = new JugadorIA(2, "IA");
            } else if (modo == 3) { // IA vs IA
                j1 = new JugadorIA(1, "IA 1");
                j2 = new JugadorIA(2, "IA 2");
            } else {
                interfaz.mostrarMensaje("Modo inválido.");
                continue;
            }
            
            Juego juego(j1, j2);
            cicloDeJuego(juego, interfaz);

        } else if (opcion == 2) { // Cargar Partida
            std::string ruta = interfaz.preguntarCargar();
            if (ruta.empty()){
                interfaz.mostrarMensaje("No se especificó ruta.");
                continue;
            }
            Juego* juegoCargado = Persistencia::cargarPartida(ruta);
            if (juegoCargado) {
                interfaz.mostrarMensaje("Partida cargada.");
                cicloDeJuego(*juegoCargado, interfaz);
                delete juegoCargado; // Liberar memoria
            } else {
                interfaz.mostrarMensaje("No se pudo cargar la partida desde " + ruta);
            }
        }
    } while (opcion != 3);

    interfaz.mostrarMensaje("Gracias por jugar.");

    return 0;
}

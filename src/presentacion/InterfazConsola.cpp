#include "presentacion/InterfazConsola.h"
#include "negocio/Tablero.h"

void InterfazConsola::mostrarMenuPrincipal() {
    std::cout << "=== 4 EN LÍNEA ===" << std::endl;
    std::cout << "1. Juego Nuevo" << std::endl;
    std::cout << "2. Cargar Partida" << std::endl;
    std::cout << "3. Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
}

int InterfazConsola::mostrarMenuNuevoJuego() {
    std::cout << "\n--- Nuevo Juego ---" << std::endl;
    std::cout << "1. Humano vs Humano" << std::endl;
    std::cout << "2. Humano vs IA" << std::endl;
    std::cout << "3. IA vs IA" << std::endl;
    std::cout << "Seleccione modo de juego: ";
    int modo;
    std::cin >> modo;
    std::cin.ignore(10000, '\n');
    return modo;
}

void InterfazConsola::mostrarTablero(const Tablero& tablero) {
    std::cout << "\n--- TABLERO ---" << std::endl;
    for (int j = 0; j < tablero.getColumnas(); ++j) {
        std::cout << " " << j << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < tablero.getFilas(); ++i) {
        for (int j = 0; j < tablero.getColumnas(); ++j) {
            std::cout << "[";
            int celda = tablero.obtenerCelda(i, j);
            if (celda == 0) {
                std::cout << " ";
            } else {
                std::cout << celda;
            }
            std::cout << "]";
        }
        std::cout << std::endl;
    }
    std::cout << "---------------" << std::endl;
}

int InterfazConsola::solicitarColumna(int idJugador) {
    int col;
    std::cout << "Jugador " << idJugador << ", ingrese columna: ";
    std::cin >> col;
    std::cin.ignore(10000, '\n');
    return col;
}

void InterfazConsola::mostrarMensaje(const std::string& msg) {
    std::cout << msg << std::endl;
}

bool InterfazConsola::preguntarGuardar() {
    char respuesta;
    std::cout << "¿Desea guardar la partida? (s/n): ";
    std::cin >> respuesta;
    std::cin.ignore(10000, '\n');
    return (respuesta == 's' || respuesta == 'S');
}

std::string InterfazConsola::preguntarCargar() {
    std::string ruta;
    std::cout << "Ingrese la ruta del archivo a cargar: ";
    std::getline(std::cin, ruta);
    return ruta;
}

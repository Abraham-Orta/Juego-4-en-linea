#include "negocio/Tablero.h"
#include <string>
#include <sstream> // Para serializar

// Constructor
Tablero::Tablero(int filas, int columnas) : filas(filas), columnas(columnas) {
    celdas = new int*[filas];
    for (int i = 0; i < filas; ++i) {
        celdas[i] = new int[columnas];
        for (int j = 0; j < columnas; ++j) {
            celdas[i][j] = 0; // Inicializar a 0
        }
    }
}

// Destructor
Tablero::~Tablero() {
    for (int i = 0; i < filas; ++i) {
        delete[] celdas[i];
    }
    delete[] celdas;
}

// Constructor de copia
Tablero::Tablero(const Tablero& other) : filas(other.filas), columnas(other.columnas) {
    celdas = new int*[filas];
    for (int i = 0; i < filas; ++i) {
        celdas[i] = new int[columnas];
        for (int j = 0; j < columnas; ++j) {
            celdas[i][j] = other.celdas[i][j];
        }
    }
}

// Operador de asignación
Tablero& Tablero::operator=(const Tablero& other) {
    if (this == &other) {
        return *this;
    }
    // Liberar memoria existente
    for (int i = 0; i < filas; ++i) {
        delete[] celdas[i];
    }
    delete[] celdas;

    // Copiar datos
    filas = other.filas;
    columnas = other.columnas;
    celdas = new int*[filas];
    for (int i = 0; i < filas; ++i) {
        celdas[i] = new int[columnas];
        for (int j = 0; j < columnas; ++j) {
            celdas[i][j] = other.celdas[i][j];
        }
    }
    return *this;
}


bool Tablero::columnaLlena(int col) const {
    if (col < 0 || col >= columnas) {
        return true;
    }
    return celdas[0][col] != 0;
}

int Tablero::insertarFicha(int col, int idJugador) {
    if (col < 0 || col >= columnas) {
        return -1;
    }
    for (int i = filas - 1; i >= 0; --i) {
        if (celdas[i][col] == 0) {
            celdas[i][col] = idJugador;
            return i;
        }
    }
    return -1;
}

void Tablero::retirarFicha(int fila, int col) {
    if (fila >= 0 && fila < filas && col >= 0 && col < columnas) {
        celdas[fila][col] = 0;
    }
}

int Tablero::obtenerCelda(int fila, int col) const {
    if (fila < 0 || fila >= filas || col < 0 || col >= columnas) {
        return -1;
    }
    return celdas[fila][col];
}

bool Tablero::cuatroEnLinea(int fila, int col, int idJugador) const {
    return false;
}

int Tablero::contarSecuenciasDeCuatro(int idJugador) const {
    return 0;
}

bool Tablero::tableroLleno() const {
    for (int j = 0; j < columnas; ++j) {
        if (celdas[0][j] == 0) {
            return false;
        }
    }
    return true;
}

std::string Tablero::serializar() const {
    std::stringstream ss;
    ss << filas << " " << columnas << "\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            ss << celdas[i][j] << " ";
        }
        ss << "\n";
    }
    return ss.str();
}

Tablero Tablero::deserializar(const std::string& texto) {
    std::stringstream ss(texto);
    int f, c;
    ss >> f >> c;
    Tablero t(f, c);
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            ss >> t.celdas[i][j];
        }
    }
    return t;
}


void Tablero::mostrar() const {
    for (int j = 0; j < columnas; ++j) {
        std::cout << " " << j << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::cout << "[";
            if (celdas[i][j] == 0) {
                std::cout << " ";
            } else {
                std::cout << celdas[i][j];
            }
            std::cout << "]";
        }
        std::cout << std::endl;
    }
}

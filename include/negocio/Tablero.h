#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <string> // Re-añadido

class Tablero {
private:
    int filas;
    int columnas;
    int** celdas;

public:
    Tablero(int filas, int columnas);
    ~Tablero();

    Tablero(const Tablero& other);
    Tablero& operator=(const Tablero& other);

    bool columnaLlena(int col) const;
    int insertarFicha(int col, int idJugador);
    void retirarFicha(int fila, int col);
    int obtenerCelda(int fila, int col) const;
    bool cuatroEnLinea(int fila, int col, int idJugador) const;
    int contarSecuenciasDeCuatro(int idJugador) const;
    bool tableroLleno() const;
    
    // Re-introduciendo serialización
    std::string serializar() const;
    static Tablero deserializar(const std::string& texto);

    void mostrar() const;
    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }
};

#endif // TABLERO_H

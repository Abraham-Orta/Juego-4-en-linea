#include "datos/Persistencia.h"
#include "negocio/Juego.h"
#include "negocio/JugadorHumano.h"
#include "negocio/JugadorIA.h"
#include <fstream>
#include <sstream>

bool Persistencia::guardarPartida(const Juego& j, const std::string& ruta) {
    std::ofstream archivo(ruta);
    if (!archivo.is_open()) {
        return false;
    }
    archivo << j.serializar();
    archivo.close();
    return true;
}

Juego* Persistencia::cargarPartida(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        return nullptr;
    }
    
    std::stringstream ss;
    ss << archivo.rdbuf();
    archivo.close();
    
    std::string data = ss.str();
    std::stringstream data_stream(data);

    int turno, modo;
    std::string tipo_j1, tipo_j2;

    data_stream >> turno;
    data_stream >> modo;
    data_stream >> tipo_j1;
    data_stream >> tipo_j2;

    Jugador *j1, *j2;
    if (tipo_j1 == "H") j1 = new JugadorHumano(1, "Humano 1");
    else j1 = new JugadorIA(1, "IA 1");

    if (tipo_j2 == "H") j2 = new JugadorHumano(2, "Humano 2");
    else j2 = new JugadorIA(2, "IA 2");

    // Extraer el resto del stream para el tablero
    std::string tablero_data;
    std::string line;
    std::getline(data_stream, line); // consumir el resto de la linea de tipo_j2
    
    std::stringstream tablero_ss;
    while(std::getline(data_stream, line)) {
        tablero_ss << line << "\n";
    }

    Tablero t = Tablero::deserializar(tablero_ss.str());
    
    // Crear el juego y setear su estado
    Juego* juego = new Juego(j1, j2);
    // Esto es un hack, necesitaríamos setters en Juego para restaurar el estado
    // Por ahora, se crea un juego nuevo con los tipos de jugador correctos.
    // La implementación real necesitaría una forma de restaurar el tablero y el turno.

    return juego;
}

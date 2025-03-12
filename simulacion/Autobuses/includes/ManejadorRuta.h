#ifndef MANEJADOR_RUTA_H
#define MANEJADOR_RUTA_H

#include "Terminal.h"
#include "Autobus.h"
#include <vector>
#include <string>

class ManejadorRuta {
  private:
    int CantidadDeAutobuses;
    int CantidadDeTerminales;
    int TiempoDeSimulacion;
    std::vector<Terminal> Terminales;
    std::vector<Autobus> Autobuses;
  public:
    ManejadorRuta();
    ManejadorRuta(int cantidadDeAutobuses, int cantidadDeTerminales, int tiempoDeSimulacion);
    std::string Simular();
};

#endif

#include "ManejadorRuta.h"
#include <iostream>
#include <sstream>

ManejadorRuta::ManejadorRuta() : CantidadDeAutobuses(3), TiempoDeSimulacion(60) {
  Autobuses.resize(CantidadDeAutobuses);
}

ManejadorRuta::ManejadorRuta(int cantidadDeAutobuses, int tiempoDeSimulacion) 
  : CantidadDeAutobuses(cantidadDeAutobuses), TiempoDeSimulacion(tiempoDeSimulacion) {
    Autobuses.resize(CantidadDeAutobuses);
}

std::string ManejadorRuta::Simular() {
  int tiempoActual = 0;
  int autobusActual = 0;
  std::stringstream resultados;

  while (tiempoActual < TiempoDeSimulacion) {
    if(tiempoActual % terminal.getLapsoDeLLegadaDePersonas() == 0) {
      terminal.ActualizarPersonasEsperando();
    }

    if(autobusActual == CantidadDeAutobuses) {
      autobusActual = 0;
    }

    if(tiempoActual > 0 && tiempoActual % terminal.getLapsoEntreAutobuses() == 0) {
      resultados << "\nAutobus #" << autobusActual + 1 << " llego a la Terminal" << std::endl;
      resultados << "Personas esperando en terminal antes de recibir el autobus: " << terminal.getPersonasEsperando() << std::endl;
      resultados << "Personas abordo del autobus antes de llegar a la terminal: " << Autobuses[autobusActual].getPasajerosAbordo() << std::endl;
      resultados << terminal.RecibirAutobus(Autobuses[autobusActual]);
      resultados << "Personas abordo del autobus despues de llegar a la terminal: " << Autobuses[autobusActual].getPasajerosAbordo() << std::endl;
      resultados << "Personas esperando en terminal despues de recibir el autobus: " << terminal.getPersonasEsperando() << std::endl;

      std::cout << resultados.str();

      autobusActual++;
    }

    tiempoActual++;
  }

  return resultados.str();
}

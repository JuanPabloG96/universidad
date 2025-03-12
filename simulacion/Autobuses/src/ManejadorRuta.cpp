#include "ManejadorRuta.h"
#include <iostream>
#include <sstream>

ManejadorRuta::ManejadorRuta() : CantidadDeAutobuses(8), CantidadDeTerminales(3), TiempoDeSimulacion(60) {
  Autobuses.resize(CantidadDeAutobuses);
  Terminales.resize(CantidadDeTerminales);
}

ManejadorRuta::ManejadorRuta(int cantidadDeAutobuses, int cantidadDeTerminales, int tiempoDeSimulacion) 
  : CantidadDeAutobuses(cantidadDeAutobuses), CantidadDeTerminales(cantidadDeTerminales), TiempoDeSimulacion(tiempoDeSimulacion) {
    Autobuses.resize(CantidadDeAutobuses);
    Terminales.resize(CantidadDeTerminales);
}

std::string ManejadorRuta::Simular() {
  int tiempoActual = 0;
  std::stringstream resultados;
  
  // Vector para rastrear en qué terminal se encuentra cada autobús
  std::vector<int> posicionesAutobuses(CantidadDeAutobuses, 0);
  std::vector<int> nuevasPosiciones(CantidadDeAutobuses, 0);

  // Posicionar autobuses en los Terminales
  for (int i = 0; i < CantidadDeAutobuses; i++) {
    posicionesAutobuses[i] = (i % CantidadDeTerminales);
    nuevasPosiciones[i] = posicionesAutobuses[i];
  }

  while (tiempoActual < TiempoDeSimulacion) {
    for (int i = 0; i < CantidadDeTerminales; i++) {
      // Actualizar Personas en la terminal
      if (tiempoActual % Terminales[i].getLapsoDeLLegadaDePersonas() == 0) {
        Terminales[i].ActualizarPersonasEsperando();
      }
    }
    
    // Procesar llegada de autobuses sin moverlos aún
    for (int j = 0; j < CantidadDeAutobuses; j++) {
      int terminalActual = posicionesAutobuses[j];
      if (tiempoActual > 0 && tiempoActual % Terminales[terminalActual].getLapsoEntreAutobuses() == 0) {
        resultados << "\nTiempo: " << tiempoActual << std::endl;
        resultados << "Autobus " << j + 1 << " llega a la terminal " << terminalActual + 1 << std::endl;
        resultados << "Personas esperando en terminal: " << Terminales[terminalActual].getPersonasEsperando() << std::endl;
        resultados << "Personas abordo del autobus antes de recibir: " << Autobuses[j].getPasajerosAbordo() << std::endl;
        resultados << Terminales[terminalActual].RecibirAutobus(Autobuses[j]);
        resultados << "Personas abordo del autobus despues de recibir: " << Autobuses[j].getPasajerosAbordo() << std::endl;
        resultados << "Personas esperando en terminal: " << Terminales[terminalActual].getPersonasEsperando() << std::endl;
        
        // Marcar la nueva posición sin modificar la actual aún
        nuevasPosiciones[j] = (terminalActual + 1) % CantidadDeTerminales;
      }
    }
    
    // Aplicar el cambio de posición después de procesar todos los autobuses
    posicionesAutobuses = nuevasPosiciones;
    
    tiempoActual++;
  }
  
  return resultados.str();
}


#include "Terminal.h"
#include "GeneradorRandom.h"
#include <sstream>

Terminal::Terminal() : LapsoEntreAutobuses(15), LapsoDeLLegadaDePersonas(5), PersonasEsperando(0) {}
Terminal::Terminal(int lapsoEntreAutobuses) : LapsoEntreAutobuses(lapsoEntreAutobuses), LapsoDeLLegadaDePersonas(5), PersonasEsperando(0) {}

std::string Terminal::RecibirAutobus(Autobus& autobus) {
  int pasajerosBajados = autobus.BajarPasajeros();
  int pasajerosSubidos = autobus.SubirPasajeros(PersonasEsperando);
  std::stringstream resultados;

  PersonasEsperando -= pasajerosSubidos;

  resultados << "Personas bajadas: " << pasajerosBajados << std::endl;
  resultados << "Personas subidas: " << pasajerosSubidos << std::endl;

  return resultados.str();
}

void Terminal::ActualizarPersonasEsperando() {
  GeneradorRandom random;
  PersonasEsperando += random.Generar(0, 10);
}

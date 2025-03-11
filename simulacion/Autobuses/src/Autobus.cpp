#include "Autobus.h"
#include "GeneradorRandom.h"

Autobus::Autobus() : CapacidadMaxima(80), PasajerosAbordo(0) {}

int Autobus::SubirPasajeros(int pasajeros) {
  if(PasajerosAbordo + pasajeros <= CapacidadMaxima) {
    PasajerosAbordo += pasajeros;
    return pasajeros;
  } else {
    int PasajerosSubidos = CapacidadMaxima - PasajerosAbordo;
    PasajerosAbordo = CapacidadMaxima;
    return PasajerosSubidos;
  }
}

int Autobus::BajarPasajeros() {
  GeneradorRandom random;
  int PasajerosBajados = random.Generar(0, 10);

  if(PasajerosAbordo - PasajerosBajados >= 0) {
    PasajerosAbordo -= PasajerosBajados;
    return PasajerosBajados;
  }
  else {
    PasajerosBajados = PasajerosAbordo;
    PasajerosAbordo = 0;
    return PasajerosBajados;
  }

}

int Autobus::getPasajerosAbordo() { return PasajerosAbordo; }

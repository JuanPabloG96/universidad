#include "Banco.h"

Banco::Banco() : cantidadCajasNormales(3), tiempoSimulacion(60) {
  cajasNormales.resize(cantidadCajasNormales);
  cajasNormales[0].setEstaAbierta(true);
  cajaPremier.setEstaAbierta(true);
}

Banco::Banco(int normales, int tiempoSimulacion)
    : cantidadCajasNormales(normales), tiempoSimulacion(tiempoSimulacion) {
  cajasNormales.resize(cantidadCajasNormales);
  cajasNormales[0].setEstaAbierta(true);
  cajaPremier.setEstaAbierta(true);
}

void Banco::Simular() {}

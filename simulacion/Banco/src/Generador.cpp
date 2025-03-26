#include "Generador.h"
#include <math.h>
#include <random>

Generador::Generador() {}

float Generador::distribucionExponencial(int media) {
  float lamda = 1.0 / media;
  float u = valorRandom();
  valor = -log(1 - u) / lamda;
  return valor;
}

float Generador::distribucionPoisson(int media, int tiempoSimulacion) {
  float lambda = (1.0 / media) * tiempoSimulacion;
  float tiempoAcumulado = 1.0;
  int numeroEventos = 0;

  while (tiempoAcumulado < tiempoSimulacion) {
    tiempoAcumulado += distribucionExponencial(lambda);
    numeroEventos++;
  }

  return numeroEventos;
}

int Generador::distribucionUniforme(int vmin, int vmax) {
  valor = (valorRandom() * vmax) + vmin;
  return valor;
}

float Generador::valorRandom() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0);
  return dis(gen);
}

#include "Generador.h"
#include <math.h>
#include <random>

Generador::Generador() {}

float Generador::distribucionExponencial(int media) {
    float lambda = 1.0 / media;
    float u = valorRandom();
    return -log(1.0 - u) / lambda;
}

float Generador::distribucionPoisson(int media, int tiempoSimulacion) {
    float lambda = media * tiempoSimulacion;
    float probabilidadSinEventos = exp(-lambda);
    int numeroEventos = 0;
    float probabilidadAcumulada = probabilidadSinEventos;
    float u = valorRandom();

    while (u > probabilidadAcumulada) {
        numeroEventos++;
        probabilidadSinEventos *= lambda / numeroEventos;
        probabilidadAcumulada += probabilidadSinEventos;
    }
    return numeroEventos;
}

int Generador::distribucionUniforme(int vmin, int vmax) {
  return vmin + floor((vmax - vmin + 1) * valorRandom());
}

float Generador::valorRandom() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0);
  return dis(gen);
}

int Generador::factorial(int k) {
  long long fact = 1;
  for (int i = 1; i <= k; ++i) {
    fact *= i;
  }
  return fact;
}

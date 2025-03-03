#include "GeneradorRandom.h"
#include <random>
#include <math.h>

GeneradorRandom::GeneradorRandom() {}

int GeneradorRandom::Generar(int min, int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(min, max + 1);

  valor = dis(gen);
  valor = std::floor(valor);
  return valor;
}

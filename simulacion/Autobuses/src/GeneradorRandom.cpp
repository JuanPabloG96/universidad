#include "GeneradorRandom.h"
#include <random>
#include <math.h>

GeneradorRandom::GeneradorRandom() : valor(0) {}

int GeneradorRandom::Generar(int min, int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(min, max + 1);

  valor = std::floor((dis(gen)));

  return valor;
}

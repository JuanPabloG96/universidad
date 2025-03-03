#include "Dado.h"
#include "GeneradorRandom.h"

Dado::Dado() {}

int Dado::LanzarDado() {
  GeneradorRandom generar;
  valor = generar.Generar(1, 6);
  return valor;
}

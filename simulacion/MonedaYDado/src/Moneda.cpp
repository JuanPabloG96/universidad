#include "Moneda.h"
#include "GeneradorRandom.h"

Moneda::Moneda() {}

std::string Moneda::LanzarMoneda() {
  GeneradorRandom generar;
  valor = generar.Generar(1, 2);
  valor == 1 ? cara = "Cara" : cara = "Sello";
  return cara;
}

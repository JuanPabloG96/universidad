#ifndef BANCO_H
#define BANCO_H

#include "Caja.h"
#include "Cola.h"
#include <vector>
#include <string>

class Banco {
private:
  int cantidadCajasNormales;
  int tiempoSimulacion;
  std::vector<Caja> cajasNormales;
  Caja cajaPremier;
  Cola colaNormal;
  Cola colaPremier;

public:
  Banco();
  Banco(int normales, int tiempoSimulacion);
  std::string Simular();
};

#endif

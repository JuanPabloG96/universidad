#ifndef MANEJADOR_H
#define MANEJADOR_H

#include <string>

class Manejador {
private:
  int corridas;
  int numLanzamientos;
public:
  Manejador();
  std::string LanzarMonedas();
  std::string LanzarDados();
};

#endif

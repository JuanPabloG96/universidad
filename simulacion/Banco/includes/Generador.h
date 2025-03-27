#ifndef GENERADOR_H
#define GENERADOR_H

class Generador {
private:
  float valor;

public:
  Generador();
  float distribucionExponencial(int media);
  float distribucionPoisson(int media, int tiempoSimulacion);
  int distribucionUniforme(int vmin, int vmax);
  float valorRandom();
  int factorial(int k);
};

#endif

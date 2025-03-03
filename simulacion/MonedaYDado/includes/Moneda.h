#ifndef MONEDA_H
#define MONEDA_H

#include <string>

class Moneda {
  private:
    int valor;
    std::string cara;
  public:
    Moneda();
    std::string LanzarMoneda();

    int getValor() { return valor; }
};

#endif

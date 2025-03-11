#ifndef TERMINAL_H
#define TERMINAL_H

#include "Autobus.h"
#include <string>

class Terminal {
  private:
    int LapsoEntreAutobuses;
    int LapsoDeLLegadaDePersonas;
    int PersonasEsperando;

  public:
    Terminal();
    Terminal(int lapsoEntreAutobuses);
    std::string RecibirAutobus(Autobus& autobus);
    void ActualizarPersonasEsperando();

    int getPersonasEsperando() { return PersonasEsperando; }
    int getLapsoEntreAutobuses() { return LapsoEntreAutobuses; }
    int getLapsoDeLLegadaDePersonas() { return LapsoDeLLegadaDePersonas; }
};

#endif

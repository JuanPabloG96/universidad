#ifndef AUTOBUS_H
#define AUTOBUS_H

class Autobus {
  private:
    int CapacidadMaxima;
    int PasajerosAbordo;
  public:
    Autobus();
    int SubirPasajeros(int pasajeros);
    int BajarPasajeros();

    int getPasajerosAbordo();
};

#endif

#ifndef CAJA_H
#define CAJA_H

class Caja {
private:
  bool estaOcupada;
  bool estaAbierta;
  int tiempoServicio;

public:
  Caja();
  bool getEstaOcupada() const;
  void setEstaOcupada(bool ocupada);
  bool getEstaAbierta() const;
  void setEstaAbierta(bool abierta);
  int getTiempoServicio() const;
  void setTiempoServicio(int tiempo);
};

#endif

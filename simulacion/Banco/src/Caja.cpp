#include "Caja.h"

Caja::Caja() : estaOcupada(false), estaAbierta(false), tiempoServicio(0) {}

bool Caja::getEstaOcupada() const { return estaOcupada; }
bool Caja::getEstaAbierta() const { return estaAbierta; }
int Caja::getTiempoServicio() const { return tiempoServicio; }

void Caja::setEstaOcupada(bool ocupada) { estaOcupada = ocupada; }
void Caja::setEstaAbierta(bool abierta) { estaAbierta = abierta; }
void Caja::setTiempoServicio(int tiempo) { tiempoServicio = tiempo; }

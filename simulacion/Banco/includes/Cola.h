#ifndef COLA_H
#define COLA_H

#include "Cliente.h"
#include <vector>

class Cola {
private:
  int maximoClientes;
  int clientesActuales;
  std::vector<Cliente> clientes;

public:
  Cola();
  Cola(int cantidadClientes, int tiempoEspera);
  void agregarCliente(Cliente cliente);
  Cliente quitarCliente();
  int getClientesActuales();
};

#endif

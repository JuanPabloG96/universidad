#include "Cola.h"

Cola::Cola() : maximoClientes(20), clientesActuales(0) {
  clientes.resize(maximoClientes);
}

void Cola::agregarCliente(Cliente cliente) {
  clientes[clientesActuales] = cliente;
  clientesActuales++;
}

Cliente Cola::quitarCliente() {
  Cliente clienteAServir = clientes[0];
  clientesActuales--;
  for (int i = 0; i < clientesActuales; i++) {
    clientes[i] = clientes[i + 1];
  }
  return clienteAServir;
}

int Cola::getClientesActuales() { return clientesActuales; }

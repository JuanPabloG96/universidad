#include "ManejadorRuta.h"
#include <iostream>
#include <fstream>

int main() {
  int autobusesSeleccionados = 0, tiempoDeSimulacionSeleccionado = 0;
  std::string ArchivoDeSalida;

  std::cout << "Simulación de Autobuses" << std::endl << std::endl;
  std::cout << "Ingrese la cantidad de autobuses: ";
  std::cin >> autobusesSeleccionados;
  std::cout << "Ingrese el tiempo de simulación: ";
  std::cin >> tiempoDeSimulacionSeleccionado;

  ManejadorRuta Ruta(autobusesSeleccionados, tiempoDeSimulacionSeleccionado);

  std::cout << "Selecciona el nombre del archivo de salida: ";
  std::cin >> ArchivoDeSalida;

  std::ofstream Archivo(ArchivoDeSalida + ".txt");
  Archivo << Ruta.Simular();
  Archivo.close();

  return 0;
}


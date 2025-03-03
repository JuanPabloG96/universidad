#include "Manejador.h"
#include <iostream>

void printMenu() {
  system("clear");
  std::cout << "###### MENU PRINCIPAL ######" << std::endl;
  std::cout << "1. Lanzar monedas" << std::endl;
  std::cout << "2. Lanzar dados" << std::endl;
  std::cout << "3. Salir" << std::endl;
}

int main() {
  Manejador manejador;

  int seleccion = 0;

  while (seleccion != 3) {
    printMenu();
    std::cout << "\nSeleccione una opcion: ";
    std::cin >> seleccion;
    if (seleccion == 1) {
      system("clear");
      manejador.LanzarMonedas();
      std::cout << "\nPresione Enter para continuar...";
      std::cin.ignore();
      std::cin.get();

    } else if (seleccion == 2) {
      system("clear");
      manejador.LanzarDados();
      std::cout << "\nPresione Enter para continuar...";
      std::cin.ignore();
      std::cin.get();
    }
  }

  return 0;
}


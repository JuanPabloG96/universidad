#include "Manejador.h"
#include <iostream>
#include <fstream>

void printMenu(int& seleccion) {
  system("clear");
  std::cout << "###### MENU PRINCIPAL ######" << std::endl;
  std::cout << "1. Lanzar monedas" << std::endl;
  std::cout << "2. Lanzar dados" << std::endl;
  std::cout << "3. Salir" << std::endl;

  std::cout << "\nSeleccione una opcion: ";
  std::cin >> seleccion;
}

void esperar() {
  std::cout << "\nPresione Enter para continuar...";
  std::cin.ignore();
  std::cin.get();
}

void getNombreArchivo(std::string& nombreArchivo) {
  std::cout << "\nIntroduzca el nombre del archivo: ";
  std::cin >> nombreArchivo;
}

void almacenaResultados(const std::string& nombreArchivo, const std::string& resultados) {
  std::string archivoExtension = nombreArchivo + ".txt";
  std::ofstream archivo;
  archivo.open(archivoExtension);
  archivo << resultados;
  archivo.close();
}

int main() { 
  Manejador manejador;
  std::string nombreArchivo;

  int seleccion = 0;

  while (seleccion != 3) {
    printMenu(seleccion);

    if (seleccion == 1) {
      getNombreArchivo(nombreArchivo);
      system("clear");
      almacenaResultados(nombreArchivo, manejador.LanzarMonedas());
      esperar();

    } else if (seleccion == 2) {
      getNombreArchivo(nombreArchivo);
      system("clear");
      almacenaResultados(nombreArchivo, manejador.LanzarDados());
      esperar();
    }
  }

  return 0;
}


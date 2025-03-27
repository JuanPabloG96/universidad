#include "Banco.h"
#include <iostream>
#include <fstream>

int main() {
  int tiempoSimulacion = 0;
  int cajasSeleccionadas = 3;
  std::string nombreArchivo = "resultados_simulacion.txt";

  std::cout << "Simulación Bancaria" << std::endl;
  std::cout << "Introduce el tiempo de simulación en minutos: ";
  std::cin >> tiempoSimulacion;
  std::cout << "Introduce el número de cajas: ";
  std::cin >> cajasSeleccionadas;
  std::cout << "Introduce el nombre del archivo de resultados: ";
  std::cin >> nombreArchivo;

  nombreArchivo += ".txt";

  // Crear banco con 3 cajas y tiempo de simulación
  Banco banco(cajasSeleccionadas, tiempoSimulacion);
    
  // Realizar simulación y obtener resultados
  std::string resultadosSimulacion = banco.Simular();

  // Guardar resultados en archivo
  std::ofstream archivoSalida(nombreArchivo);
  if (archivoSalida.is_open()) {
    archivoSalida << resultadosSimulacion;
    archivoSalida.close();
    std::cout << "Resultados guardados en: " << nombreArchivo << std::endl;
  } else {
    std::cerr << "Error: No se pudo abrir el archivo" << std::endl;
  }

  return 0;
}

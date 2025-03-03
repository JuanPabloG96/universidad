#include "Manejador.h"
#include "Moneda.h"
#include "Dado.h"
#include <iomanip>
#include <iostream>

Manejador::Manejador() : corridas(0), numLanzamientos(0) {}

void Manejador::LanzarMonedas() {
  Moneda moneda;
  int contadorCorridas = 0;
  int contadorLanzamientos = 0;
  const int valoresPosibles = 2;
  int resultados[valoresPosibles] = {0, 0};

  std::cout << "Introduzca el numero de corridas: ";
  std::cin >> corridas;
  std::cout << "Introduzca el numero de lanzamientos: ";
  std::cin >> numLanzamientos;

  while (contadorCorridas < corridas) {
    while (contadorLanzamientos < numLanzamientos) {
      moneda.LanzarMoneda();
      resultados[moneda.getValor() - 1] = resultados[moneda.getValor() - 1] + 1;
      contadorLanzamientos++;
    }
    
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\nCorrida " << contadorCorridas + 1 << ". Porcentajes obtenidos en " << numLanzamientos << " lanzamientos" << std::endl;
    std::cout << "Numero de caras: " << resultados[0] << std::endl;
    std::cout << "Numero de sellos: " << resultados[1] << std::endl;    
    std::cout << "Cara: " << double (resultados[0] * 100.0 / numLanzamientos) << "%" << std::endl;
    std::cout << "Sello: " << double (resultados[1] * 100.0 / numLanzamientos) << "%" << std::endl;

    contadorCorridas++;
    contadorLanzamientos = 0;
    for (int i = 0; i < valoresPosibles; i++) {
      resultados[i] = 0;
    }
  }
}

void Manejador::LanzarDados() {
  Dado dado;
  int contadorCorridas = 0;
  int contadorLanzamientos = 0;
  const int valoresPosibles = 6;
  int resultados[valoresPosibles] = {0, 0, 0, 0, 0, 0};

  std::cout << "Introduzca el numero de corridas: ";
  std::cin >> corridas;
  std::cout << "Introduzca el numero de lanzamientos: ";
  std::cin >> numLanzamientos;

  while (contadorCorridas < corridas) {
    while (contadorLanzamientos < numLanzamientos) {
      int i =dado.LanzarDado();
      resultados[i - 1] = resultados[i - 1] + 1;
      contadorLanzamientos++;
    }

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\nCorrida " << contadorCorridas + 1 << ". Porcentajes obtenidos en " << numLanzamientos << " lanzamientos" << std::endl;
    std::cout << "1: " << resultados[0] << " : " << double (resultados[0] * 100.0 / numLanzamientos) << "%" << std::endl;
    std::cout << "2: " << resultados[1] << " : " << double (resultados[1] * 100.0 / numLanzamientos) << "%" << std::endl;
    std::cout << "3: " << resultados[2] << " : " << double (resultados[2] * 100.0 / numLanzamientos) << "%" << std::endl;
    std::cout << "4: " << resultados[3] << " : " << double (resultados[3] * 100.0 / numLanzamientos) << "%" << std::endl;
    std::cout << "5: " << resultados[4] << " : " << double (resultados[4] * 100.0 / numLanzamientos) << "%" << std::endl;
    std::cout << "6: " << resultados[5] << " : " << double (resultados[5] * 100.0 / numLanzamientos) << "%" << std::endl;

    contadorCorridas++;
    contadorLanzamientos = 0;
    for (int i = 0; i < valoresPosibles; i++) {
      resultados[i] = 0;
    }
  }
}

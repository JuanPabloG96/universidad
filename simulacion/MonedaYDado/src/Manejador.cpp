#include "Manejador.h"
#include "Moneda.h"
#include "Dado.h"
#include <iomanip>
#include <iostream>
#include <sstream>

Manejador::Manejador() : corridas(0), numLanzamientos(0) {}

std::string Manejador::LanzarMonedas() {
  Moneda moneda;
  int contadorCorridas = 0;
  const int valoresPosibles = 2;
  int resultados[valoresPosibles] = {0, 0};

  std::ostringstream salida;

  std::cout << "Introduzca el numero de corridas: ";
  std::cin >> corridas;
  std::cout << "Introduzca el numero de lanzamientos: ";
  std::cin >> numLanzamientos;

  while (contadorCorridas < corridas) {
    int contadorLanzamientos = 0;

    while (contadorLanzamientos < numLanzamientos) {
      moneda.LanzarMoneda();
      resultados[moneda.getValor() - 1] = resultados[moneda.getValor() - 1] + 1;
      contadorLanzamientos++;
    }
    
    salida << std::fixed << std::setprecision(4);
    salida << "\nCorrida " << contadorCorridas + 1 << ". Porcentajes obtenidos en " << numLanzamientos << " lanzamientos" << std::endl;
    salida << "Numero de caras: " << resultados[0] << std::endl;
    salida << "Numero de sellos: " << resultados[1] << std::endl;    
    salida << "Cara: " << double (resultados[0] * 100.0 / numLanzamientos) << "%" << std::endl;
    salida << "Sello: " << double (resultados[1] * 100.0 / numLanzamientos) << "%" << std::endl;

    std::cout << salida.str();

    contadorCorridas++;
    for (int i = 0; i < valoresPosibles; i++) {
      resultados[i] = 0;
    }
  }

  return salida.str();
}

std::string Manejador::LanzarDados() {
  Dado dado;
  int contadorCorridas = 0;
  const int valoresPosibles = 6;
  int resultados[valoresPosibles] = {0, 0, 0, 0, 0, 0};

  std::ostringstream salida;

  std::cout << "Introduzca el numero de corridas: ";
  std::cin >> corridas;
  std::cout << "Introduzca el numero de lanzamientos: ";
  std::cin >> numLanzamientos;

  while (contadorCorridas < corridas) {
    int contadorLanzamientos = 0;

    while (contadorLanzamientos < numLanzamientos) {
      int i =dado.LanzarDado();
      resultados[i - 1] = resultados[i - 1] + 1;
      contadorLanzamientos++;
    }

    salida << std::fixed << std::setprecision(4);
    salida << "\nCorrida " << contadorCorridas + 1 << ". Porcentajes obtenidos en " << numLanzamientos << " lanzamientos" << std::endl;
    salida << "1: " << resultados[0] << " : " << double (resultados[0] * 100.0 / numLanzamientos) << "%" << std::endl;
    salida << "2: " << resultados[1] << " : " << double (resultados[1] * 100.0 / numLanzamientos) << "%" << std::endl;
    salida << "3: " << resultados[2] << " : " << double (resultados[2] * 100.0 / numLanzamientos) << "%" << std::endl;
    salida << "4: " << resultados[3] << " : " << double (resultados[3] * 100.0 / numLanzamientos) << "%" << std::endl;
    salida << "5: " << resultados[4] << " : " << double (resultados[4] * 100.0 / numLanzamientos) << "%" << std::endl;
    salida << "6: " << resultados[5] << " : " << double (resultados[5] * 100.0 / numLanzamientos) << "%" << std::endl;

    std::cout << salida.str();


    contadorCorridas++;
    for (int i = 0; i < valoresPosibles; i++) {
      resultados[i] = 0;
    }
  }

  return salida.str();
}

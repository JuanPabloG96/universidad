#include "Banco.h"
#include "Generador.h"
#include <iostream>
#include <sstream>

// Los constructores permanecen igual
Banco::Banco() : cantidadCajasNormales(3), tiempoSimulacion(60) {
  cajasNormales.resize(cantidadCajasNormales);
  cajasNormales[0].setEstaAbierta(true);
  cajaPremier.setEstaAbierta(true);
}

Banco::Banco(int normales, int tiempoSimulacion) : cantidadCajasNormales(normales), tiempoSimulacion(tiempoSimulacion) {
  cajasNormales.resize(cantidadCajasNormales);
  cajasNormales[0].setEstaAbierta(true);
  cajaPremier.setEstaAbierta(true);
}

std::string Banco::Simular() {
  Generador generador;
  int tiempoActual = 0;
  int contadorClientes = 0;
  int contadorClientesAtendidos = 0;
  int contadorPreferenciales = 0;
  int tiempoServicio = 0;
  const int mediaLlegada = 10;
  const int mediaServicio = 3;

  // Crear stringstream para resultados
  std::stringstream resultados;

  // Encabezado
  resultados << "Reporte de Simulación Bancaria\n";
  resultados << "Tiempo de Simulación: " << tiempoSimulacion << " minutos\n";
  resultados << "Número de Cajas Normales: " << cantidadCajasNormales << "\n";
  resultados << "Numero de cajas Premier: 1\n";
  
  // Reiniciar colas y estado de cajas
  colaNormal = Cola();
  colaPremier = Cola();
  
  // Inicializar estado de cajas
  for (auto& caja : cajasNormales) {
    caja.setEstaAbierta(true);
    caja.setEstaOcupada(false);
    caja.setTiempoServicio(0);
  }
  cajaPremier.setEstaOcupada(false);
  cajaPremier.setTiempoServicio(0);
  
  // Bucle principal de la simulación
  while (tiempoActual < tiempoSimulacion) {
    // Generar tiempo entre llegadas (distribución exponencial)
    int tiempoEntreClientes = generador.distribucionExponencial(mediaLlegada);
    tiempoActual += tiempoEntreClientes;
    
    // Detener si se supera el tiempo de simulación
    if (tiempoActual > tiempoSimulacion) break;
    
    // Decidir si es cliente preferente (probabilidad del 10%)
    bool esPreferente = generador.valorRandom() < 0.1;
    Cliente nuevoCliente(esPreferente);
    
    // Agregar a la cola correspondiente
    if (esPreferente) {
      colaPremier.agregarCliente(nuevoCliente);
      contadorPreferenciales++;
    } else {
      colaNormal.agregarCliente(nuevoCliente);
    }

    // Registrar llegada de cliente
    resultados << "\nTiempo de llegada: minuto " << tiempoActual
               << " \n Llega cliente: " << (esPreferente ? "Preferente" : "Normal") 
               << " \n Clientes en Cola Normal: " << colaNormal.getClientesActuales()
               << " \n Clientes en Cola Premier: " << colaPremier.getClientesActuales() << "\n";

    contadorClientes++;
    
    // Atender clientes en caja Premier
    if (!cajaPremier.getEstaOcupada() && colaPremier.getClientesActuales() > 0) {
      colaPremier.quitarCliente();
      while (tiempoServicio == 0) {
        tiempoServicio = generador.distribucionExponencial(mediaServicio);
      }
      cajaPremier.setTiempoServicio(tiempoServicio);
      cajaPremier.setEstaOcupada(true);
      
      resultados << "Caja Premier atiende cliente. Tiempo de servicio: " << tiempoServicio << " minutos\n";
    }

    // Atender clientes en cajas normales
    for (int i = 0; i < cantidadCajasNormales; i++) {
      if (!cajasNormales[i].getEstaOcupada() && cajasNormales[i].getEstaAbierta() && (colaNormal.getClientesActuales() > 0 || colaPremier.getClientesActuales() > 0)) {
        if (colaPremier.getClientesActuales() > 0) {
          colaPremier.quitarCliente();
          tiempoServicio = 0;
          while (tiempoServicio == 0) {
            tiempoServicio = generador.distribucionExponencial(mediaServicio);
          }
          cajaPremier.setTiempoServicio(tiempoServicio);
          cajaPremier.setEstaOcupada(true);
          resultados << "Caja Normal atiende cliente Premier. Tiempo de servicio: " << tiempoServicio << " minutos\n";
        } else {
          colaNormal.quitarCliente();
          tiempoServicio = 0;
          while (tiempoServicio == 0) {
            tiempoServicio = generador.distribucionExponencial(mediaServicio);
          }
          cajasNormales[i].setTiempoServicio(tiempoServicio);
          cajasNormales[i].setEstaOcupada(true);
          resultados << "Caja Normal atiende cliente. Tiempo de servicio: " << tiempoServicio << " minutos\n";
        }
      } 
    }
    
    // Liberar cajas normales
    for (auto& caja : cajasNormales) {
      if (caja.getTiempoServicio() > 0) {
        caja.setTiempoServicio(caja.getTiempoServicio() - 1);
        if (caja.getTiempoServicio() == 0) {
          caja.setEstaOcupada(false);
          resultados << "Caja Normal liberada\n";
        }
      }
    }
    
    // Liberar caja Premier
    if (cajaPremier.getTiempoServicio() > 0) {
      cajaPremier.setTiempoServicio(cajaPremier.getTiempoServicio() - 1);
      if (cajaPremier.getTiempoServicio() == 0) {
        cajaPremier.setEstaOcupada(false);
        resultados << "  - Caja Premier liberada\n";
      }
    }
  }
  
  // Agregar resumen final
  resultados << "\nResumen Final:\n";
  resultados << "Total de Clientes que llegaron al banco: " << contadorClientes << "\n";
  resultados << "Clientes Preferenciales: " << contadorPreferenciales << "\n";
  resultados << "Clientes que quedaron en Cola Normal: " << colaNormal.getClientesActuales() << "\n";
  resultados << "Clientes que quedaron en Cola Premier: " << colaPremier.getClientesActuales() << "\n";

  std::cout << resultados.str();
  
  return resultados.str();
}

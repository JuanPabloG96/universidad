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

Banco::Banco(int normales, int tiempoSimulacion)
    : cantidadCajasNormales(normales), tiempoSimulacion(tiempoSimulacion) {
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

  // Inicializar estado de cajas
  for (auto &caja : cajasNormales) {
    caja.setEstaAbierta(true);
    caja.setEstaOcupada(false);
    caja.setTiempoServicio(0);
  }
  cajaPremier.setEstaOcupada(false);
  cajaPremier.setTiempoServicio(0);

  // Generar tiempo entre llegadas (distribución exponencial)
  int tiempoEntreClientes = generador.distribucionExponencial(mediaLlegada);
  int acumuladorTiempoEntreClientes = tiempoEntreClientes;

  // Bucle principal de la simulación
  while (tiempoActual <= tiempoSimulacion) {

    if (tiempoActual == acumuladorTiempoEntreClientes) {
      // Generar nuevo tiempo entre llegadas
      tiempoEntreClientes = 0;
      while (tiempoEntreClientes == 0) {
        tiempoEntreClientes = generador.distribucionExponencial(mediaLlegada);
      }
      acumuladorTiempoEntreClientes += tiempoEntreClientes;

      // Generar nuevo cliente
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
                 << " \nLlega cliente: "
                 << (esPreferente ? "Preferente" : "Normal")
                 << " \nClientes en Cola Normal: "
                 << colaNormal.getClientesActuales()
                 << " \nClientes en Cola Premier: "
                 << colaPremier.getClientesActuales() << "\n";

      contadorClientes++;
    }

    // Atender clientes en caja Premier
    if (!cajaPremier.getEstaOcupada() &&
        colaPremier.getClientesActuales() > 0) {
      colaPremier.quitarCliente();
      tiempoServicio = 0;
      while (tiempoServicio < 1) {
        tiempoServicio = generador.distribucionExponencial(mediaServicio);
      }
      cajaPremier.setTiempoServicio(tiempoServicio);
      cajaPremier.setEstaOcupada(true);

      resultados << "Caja Premier atiende cliente. Tiempo de servicio: "
                 << tiempoServicio << " minutos\n";
    }

    // Atender clientes en cajas normales
    for (int i = 0; i < cantidadCajasNormales; i++) {
      if (!cajasNormales[i].getEstaOcupada() &&
          cajasNormales[i].getEstaAbierta() &&
          (colaNormal.getClientesActuales() > 0 ||
           colaPremier.getClientesActuales() > 0)) {
        if (colaPremier.getClientesActuales() > 0) {
          colaPremier.quitarCliente();
          tiempoServicio = 0;
          while (tiempoServicio < 1) {
            tiempoServicio = generador.distribucionExponencial(mediaServicio);
          }
          int tiempoLiberar = tiempoActual + tiempoServicio;
          cajasNormales[i].setTiempoServicio(tiempoLiberar);
          cajasNormales[i].setEstaOcupada(true);
          resultados << "Caja Normal " << i + 1
                     << " atiende cliente Premier. Tiempo de servicio: "
                     << tiempoServicio << " minutos\n";
        } else {
          colaNormal.quitarCliente();
          tiempoServicio = 0;
          while (tiempoServicio < 1) {
            tiempoServicio = generador.distribucionExponencial(mediaServicio);
          }
          int tiempoLiberar = tiempoActual + tiempoServicio;
          cajasNormales[i].setTiempoServicio(tiempoLiberar);
          cajasNormales[i].setEstaOcupada(true);
          resultados << "Caja Normal " << i + 1
                     << " atiende cliente. Tiempo de servicio: "
                     << tiempoServicio << " minutos\n";
        }
      }
    }

    // Liberar cajas normales
    for (int i = 0; i < cantidadCajasNormales; i++) {
      if (cajasNormales[i].getEstaOcupada() &&
          tiempoActual >= cajasNormales[i].getTiempoServicio()) {
        contadorClientesAtendidos++;
        cajasNormales[i].setEstaOcupada(false);
        resultados << "Caja Normal " << i + 1 << " liberada en minuto "
                   << tiempoActual << "\n";
      }
    }

    // Liberar caja Premier
    if (cajaPremier.getEstaOcupada() &&
        tiempoActual >= cajaPremier.getTiempoServicio()) {
      contadorClientesAtendidos++;
      cajaPremier.setEstaOcupada(false);
      resultados << "Caja Premier liberada en minuto " << tiempoActual << "\n";
    }

    tiempoActual++;
  }

  // Agregar resumen final
  resultados << "\nResumen Final:\n";
  resultados << "Total de Clientes que llegaron al banco: " << contadorClientes
             << "\n";
  resultados << "Total de Clientes que fueron atendidos: "
             << contadorClientesAtendidos << "\n";
  resultados << "Clientes Preferenciales: " << contadorPreferenciales << "\n";
  resultados << "Clientes que quedaron en Cola Normal: "
             << colaNormal.getClientesActuales() << "\n";
  resultados << "Clientes que quedaron en Cola Premier: "
             << colaPremier.getClientesActuales() << "\n";

  std::cout << resultados.str();

  return resultados.str();
}

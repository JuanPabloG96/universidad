import timeit
import matplotlib.pyplot as plt
from tabulate import tabulate as tb

# Función para generar el powerset
def powerset(conjunto):
    n = len(conjunto)
    powerset = []

    total_combinaciones = 1 << n  # Usar desplazamiento de bits para calcular 2 elevado a la n

    for i in range(total_combinaciones):
        subconjunto = []
        for j in range(n):
            if (i >> j) & 1:
                subconjunto.append(conjunto[j])
        powerset.append(subconjunto)

    return powerset

# Función simple para generar conjuntos de diferente magnitud
def generar_conjuntos(magnitud):
  nuevo_conjunto = []
  for i in range(0, magnitud):
    nuevo_conjunto.append(i + 1)

  return nuevo_conjunto

# Función para generar la tabla
def generar_tabla(num_datos):
  nombre_conjunto = []
  magnitud = []
  conjuntos_generados = []
  tiempo_ejecucion = []

  for num in range(0, num_datos):
    nombre_conjunto.append("conjunto " + str(num + 1))
    magnitud.append(num + 1)
    conjuntos_generados.append(generar_conjuntos(num + 1))
    tiempo_ejecucion.append(
        round(
            timeit.timeit(lambda: powerset(conjuntos_generados[num]),
                          number=1), 10))

  datos_tabla = list(zip(nombre_conjunto, magnitud, tiempo_ejecucion))

  tabla = tb(
      datos_tabla,
      headers=["Conjunto", "Magnitud", "Tiempo de ejecucion en segundos"],
      tablefmt="simple")

  return tabla, datos_tabla

# Función para generar la gráfica
def graficar_resultados(datos_tabla):
  magnitudes = [row[1] for row in datos_tabla]
  tiempos_ejecucion = [row[2] for row in datos_tabla]

  plt.plot(magnitudes, tiempos_ejecucion, marker='o')
  plt.title('Tiempo de ejecución en función de la magnitud del conjunto')
  plt.xlabel('Magnitud del Conjunto')
  plt.ylabel('Tiempo de Ejecución (segundos)')
  plt.grid(True)
  plt.show()

# Prueba inicial con el conjunto asignado
conjunto = {'a', 'b', 'c'}
resultado = powerset(list(conjunto))

for subconjunto in resultado:
  print(subconjunto)

# Medir el tiempo de ejecución
tiempo_ejecucion = timeit.timeit("powerset(['a', 'b', 'c'])",
                                 globals=globals(),
                                 number=100)
print(f"Tiempo de ejecución: {tiempo_ejecucion} segundos")

while(True):
  # Establecer el valor de n
  elementos_tabla = input("Escribe la cantidad de elementos a evaluar: ")

  try:
    elementos_tabla = int(elementos_tabla)
  except:
    print("Los datos ingresados deben ser enteros")
  
  if isinstance(elementos_tabla, int):
    break

# Imprimir la tabla usando diferentes 'n' para ver la tendencia
tabla, datos_tabla = generar_tabla(elementos_tabla)
print(tabla)

# Graficar los resultados de la tabla
graficar_resultados(datos_tabla)

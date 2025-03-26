# Proyecto de Simulador de Dados y Monedas

Este proyecto es una aplicación en C++ que simula el comportamiento de llegada de clientes a un banco.

## Requisitos

Antes de compilar y ejecutar el proyecto, asegúrate de tener instaladas las siguientes dependencias en tu sistema:

- **Compilador de C++** compatible con C++20 (ejemplo: `g++` de GCC 10+ o Clang 10+).
- **Make** para la automatización de la compilación.

### Instalación en Linux (Debian/Ubuntu)

```sh
sudo apt update
sudo apt install build-essential
```

### Instalación en Arch Linux

```sh
sudo pacman -S base-devel
```

### Instalación en Windows

1. Descarga e instala [Chocolatey](https://community.chocolatey.org/).
2. Una vez instalado chocolatey revisa si la instalacion se completo adecuadamente

```sh
choco --version
```

3. Utiliza esta herramienta para instalar mingw

```sh
choco install mingw
```

4. Verifica que el compilador g++ esta correctamente instalado

```sh
g++ --version
```

5. Instala make con chocolatey

```sh
choco install make
```

6. Verifica instalacion

```sh
make --version
```

## Compilación y Ejecución

Para compilar el proyecto, usa el siguiente comando en la terminal:

```sh
make
```

Para ejecutar el programa compilado:

```sh
./build/program
```

## Estructura del Proyecto

```
.
├── build/                 # Carpeta donde se generan los archivos compilados
├── includes/              # Archivos de cabecera (.h)
├── src/                   # Código fuente (.cpp)
├── main.cpp               # Punto de entrada del programa
├── Makefile               # Script de compilación
└── readme.md              # Este archivo
```

## Limpieza del Proyecto

Para eliminar los archivos compilados y limpiar la carpeta `build/`, ejecuta:

```sh
make clean
```

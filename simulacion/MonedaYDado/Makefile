# Compilador
CXX = g++

# Flags del compilador
CXXFLAGS = -Wall -Wextra -std=c++17 -Iincludes `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4`

# Directorios
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = includes

# Buscar todos los archivos .cpp en src/ + main.cpp
SRCS = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Nombre del ejecutable
TARGET = $(BUILD_DIR)/program

# Mensajes de depuración
$(info 🔍 Archivos fuente encontrados: $(SRCS))
$(info 🔍 Archivos objeto generados: $(OBJS))

# Regla por defecto
all: $(BUILD_DIR) $(TARGET)

# Compilación del ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compilación de cada archivo .cpp en su correspondiente .o
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)/$(SRC_DIR)
	mkdir -p $(dir $@)  # Crea la carpeta donde irá el .o
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Reglas para compilar los archivos dentro de src/
$(BUILD_DIR)/src/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)/$(SRC_DIR)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla específica para main.cpp, ya que no está en src/
$(BUILD_DIR)/main.o: main.cpp | $(BUILD_DIR)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Creación de build/ si no existe
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Creación de build/src/ si no existe
$(BUILD_DIR)/$(SRC_DIR):
	mkdir -p $(BUILD_DIR)/$(SRC_DIR)

# Limpiar compilación
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean


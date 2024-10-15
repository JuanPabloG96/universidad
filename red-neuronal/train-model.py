import numpy as np
import matplotlib.pyplot as plt
from keras.layers import Dense
from keras.models import Sequential

from constants import R_list, O_list, M_list, A_list
from utils import testWord

# Organiza los datos de entrenamiento
training_data = np.array([R_list, O_list, M_list, A_list], "int32")
training_data_flattened = training_data.reshape(-1, 16)

# Definir los valores objetivo
target_data = np.array([0, 1, 2, 3], "int32")

# Crea y compila el modelo
model = Sequential()
model.add(Dense(10, input_dim=16, activation='relu'))
model.add(Dense(4, activation='softmax'))
model.compile(loss='sparse_categorical_crossentropy', optimizer='adam', metrics=['accuracy'])

# Entrena el modelo durante 300 épocas
history = model.fit(training_data_flattened, target_data, epochs=300, verbose=0, validation_data=(training_data_flattened, target_data))

# Guardar el modelo
model.save("model/RedNeuronal.keras")

# Obtener las pérdidas de entrenamiento y validación
train_loss = history.history['loss']
val_loss = history.history['val_loss']

# Crear un gráfico de pérdida
print("\n\n")
plt.plot(train_loss, label='Training Loss')
plt.plot(val_loss, label='Validation Loss')
plt.legend()
plt.xlabel('Epochs')
plt.ylabel('Loss')
plt.title('Loss Over Time')
plt.show()

testing_example = [M_list, O_list, R_list, A_list]

print("\nPredicted letters:", testWord(testing_example, model), "\n")
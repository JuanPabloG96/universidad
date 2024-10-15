from keras.models import load_model
from constants import R_list, O_list, M_list, A_list
from utils import testWord

# Carga el archivo del modelo ya entrenado
RedNeuronal = load_model("model/RedNeuronal.keras")

# mapa de las palabras a probar en la red
word_mapping = {
    "AMOR": [A_list, M_list, O_list, R_list],
    "ROMA":[R_list, O_list, M_list, A_list],
    "MORA":[M_list, O_list, R_list, A_list],
    "RAMO": [R_list, A_list, M_list, O_list]
}

# Se hace un recorrido del mapa de palabras para probar la red en cada una
for word, letter_matrix in word_mapping.items():
  print("Predicted letters for", word, ":", testWord(letter_matrix, RedNeuronal))
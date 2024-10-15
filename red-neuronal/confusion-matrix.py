import pandas as pd
from keras.models import load_model
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay

from utils import testWord, matrix_generator

# Carga el archivo del modelo ya entrenado
RedNeuronal = load_model("model/RedNeuronal.keras")

# Obtener los datos de los archivos excel
excel_file = 'data/RedesNeuronalesLetras.xlsx'
excel_data = pd.read_excel(excel_file, sheet_name=None, header=None)
# Reemplaza los valores no finitos (NaN o inf) por cero en todas las hojas
excel_data = {sheet: data.fillna(0) for sheet, data in excel_data.items()}

sheets = {
    "combinacion1": excel_data['Combinacion1'],
    "combinacion2": excel_data['Combinacion2'],
    "combinacion3": excel_data['Combinacion3']
}

predicted_label = []

# Generar las predicciones para cada matriz de prueba
for sheet_name, sheet_data in sheets.items():
  matrices = matrix_generator(sheet_data)
  word = []

  for index in range(0,16):
    word.append(matrices[index])
    if ((index + 1) % 4 == 0):
      word = testWord(word, RedNeuronal)
      # Convertir la lista en una cadena de caracteres
      word_str = ''.join([''.join(row) for row in word])
      predicted_label.append(word_str)
      word = []

true_label = [
    ['AMOR'], ['ROMA'], ['MORA'], ['RAMO'],
    ['MORA'], ['ROMA'], ['RAMO'], ['AMOR'],
    ['ROMA'], ['AMOR'], ['RAMO'], ['MORA']
]

# Calcular la matriz de confusión utilizando las predicciones
cm = confusion_matrix(true_label, predicted_label)
vis = ConfusionMatrixDisplay(cm)
# Imprimir la matriz
print("\nMatriz de confusion")
vis.plot()
import pandas as pd
from keras.models import load_model

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

for sheet_name, sheet_data in sheets.items():
  matrices = matrix_generator(sheet_data)
  word = []

  print("\n", sheet_name)

  for index in range(0,16):
    word.append(matrices[index])
    if ((index + 1) % 4 == 0):
      print(testWord(word, RedNeuronal))
      word = []
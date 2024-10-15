import numpy as np

def testWord(word, model):
  test = np.array(word, "int32")
  test_flattened = test.reshape(-1, 16)

  predictions = model.predict(test_flattened)
  predicted_classes = np.argmax(predictions, axis=1)

  # Mapeo de letras
  letter_mapping = {0: 'R', 1: 'O', 2: 'M', 3: 'A'}
  predicted_letters = [letter_mapping[c] for c in predicted_classes]

  return predicted_letters

# Funcion para dividir el archivo de excel
def split_5x5_matrices(data):
  matrices = []
  matrix_size = 5
  for i in range(0, len(data), matrix_size):
    for j in range(0, data.shape[1], matrix_size):
      matrix = data.iloc[i:i + matrix_size, j:j + matrix_size]
      matrices.append(matrix)
  matrices = [matrix.astype(int) for matrix in matrices]
  return matrices

# Eliminar la ultima columna y fila de las matrices 5x5
def generate_4x4_matrix(matrices):
  matrices_4x4 = [matrix.iloc[:-1, :-1] for matrix in matrices]
  return matrices_4x4

# Funcion para generar el arreglo de las matrices
def matrix_generator(data):
    matrices_5x5 = split_5x5_matrices(data)
    matrices_4x4 = generate_4x4_matrix(matrices_5x5)

    return matrices_4x4
import cv2
from deepface import DeepFace
import os
cascada_cara = cv2.CascadeClassifier(cv2.data.haarcascades +  "haarcascade_frontalface_default.xml")
myvid = cv2.VideoCapture(0)
def identificar_cara(ruta_imagen, ruta_bd):
    dfs = DeepFace.find(ruta_imagen, ruta_bd, 
						model_name = "Facenet512", 
						distance_metric = "cosine", 
						enforce_detection = False,  
						detector_backend = "mtcnn", 
						threshold=0.3, 
						normalization ="base")
    identidad = -1
    if len(dfs[0].identity) > 0:
        ruta_imagen_plantilla = dfs[0].identity.to_string()
        partes_ruta = os.path.split(ruta_imagen_plantilla)
        cola_ruta = partes_ruta[0]
        partes_cola = os.path.split(cola_ruta)
        identidad = partes_cola[1]
    return identidad
while True:
	resultado, imagen = myvid.read()
	if resultado is False:
		break
	caras = cascada_cara.detectMultiScale(imagen, 1.1, 5, minSize=(40,40)) 
	for (x, y, w, h) in caras:
		cara_recortada = imagen[y:y+h, x:x+w]
		cv2.imwrite('cara_temp.jpg', cara_recortada)
		id_cara = identificar_cara('cara_temp.jpg', 'Galeria')
		cv2.putText(imagen, 'Identidad: ' + str(id_cara), (x-10, y-10), 
			  cv2.FONT_HERSHEY_SIMPLEX, 1, (0,255,0), 2, cv2.LINE_AA)
		cv2.rectangle(imagen, (x,y), (x+w, y+h), (0,255,0), 2)
	cv2.imshow("Imagen desde webcam", imagen)
	if cv2.waitKey(1) & 0xFF == ord("q"):
		break
	
myvid.release()
cv2.destroyAllWindows()
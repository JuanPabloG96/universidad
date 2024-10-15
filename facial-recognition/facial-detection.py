import cv2
import matplotlib.pyplot as plt

cascada_cara = cv2.CascadeClassifier('/usr/share/opencv4/haarcascades/haarcascade_frontalface_default.xml')

myvid = cv2.VideoCapture(0)

while True:
    resultado, imagen = myvid.read()

    if resultado is False:
        break
    
    imagen_rgb = cv2.cvtColor(imagen, cv2.COLOR_BGR2RGB)
    caras = cascada_cara.detectMultiScale(imagen_rgb, scaleFactor=1.1, minNeighbors=5, minSize=(40,40))

    for(x, y, w, h) in caras:
        cv2.rectangle(imagen, (x,y), (x+w, y+h), (100, 100, 100), 2)

    plt.figure(figsize=(20,10))
    cv2.imshow("facial recognition", imagen)
    plt.clf() 
    plt.close()  

    if cv2.waitKey(1) & 0xFF == ord("q"):
        break


myvid.release()
cv2.destroyAllWindows()

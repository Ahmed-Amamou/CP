import os
import numpy as np
import tensorflow as tf
from tensorflow.keras.preprocessing import image
from tensorflow.keras.applications import EfficientNetB7
from tensorflow.keras.layers import Dense, GlobalAveragePooling2D
from tensorflow.keras.models import Model
from sklearn.metrics import accuracy_score, precision_score


# Monter Google Drive
drive.mount('/content/drive')

# Charger le modèle EfficientNet pré-entraîné sans la dernière couche
base_model = EfficientNetB7(weights='imagenet', include_top=False)

# Ajouter une couche de Global Average Pooling et une couche Dense pour les prédictions
x = base_model.output
x = GlobalAveragePooling2D()(x)
predictions = Dense(7, activation='softmax')(x)  # 7 classes pour les émotions primaires

# Créer le modèle final
model = Model(inputs=base_model.input, outputs=predictions)

# Fonction pour prédire l'émotion sur une image donnée
def predict_emotion(img):
    # Prédiction de l'émotion
    emotions = ['Angry', 'Disgust', 'Fear', 'Happy', 'Sad', 'Surprise', 'Neutral']  # Les émotions correspondant aux classes
    prediction = model.predict(img)
    predicted_class = emotions[np.argmax(prediction)]
    
    return predicted_class

# Chemin du dossier contenant les images de test
test_dir = '/content/drive/My Drive/colab images/test'

# Liste des émotions
emotions = os.listdir(test_dir)

# Liste pour stocker les vraies et les prédictions d'émotions
true_emotions = []
predicted_emotions = []

# Parcourir chaque dossier d'émotion
for emotion in emotions:
    emotion_dir = os.path.join(test_dir, emotion)
    
    # Parcourir chaque image dans le dossier d'émotion
    for file in os.listdir(emotion_dir):
        img_path = os.path.join(emotion_dir, file)
        true_emotion = emotion
        
        # Charger et prétraiter l'image
        img = image.load_img(img_path, target_size=(224, 224))
        x = image.img_to_array(img)
        x = tf.expand_dims(x, axis=0)
        
        # Prédiction de l'émotion
        predicted_emotion = predict_emotion(x)
        
        true_emotions.append(true_emotion)
        predicted_emotions.append(predicted_emotion)

# Calculer l'accuracy et la précision
accuracy = accuracy_score(true_emotions, predicted_emotions)
precision = precision_score(true_emotions, predicted_emotions, average='weighted')

print("Accuracy du test:", accuracy)
print("Precision:", precision)
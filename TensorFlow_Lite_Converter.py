# -*- coding: utf-8 -*-
"""
Created on Mon Jul  5 12:32:50 2021

@author: Rahul

This code converts Tensorflow model to tensorFlow Lite model
"""
import tensorflow as tf

from tensorflow import keras

saved_model_dir = "VGG_cross_validated.h5"

model = keras.models.load_model(saved_model_dir)

converter = tf.lite.TFLiteConverter.from_keras_model(model)

tfliteModel = converter.convert()

with open('model.tflite', 'wb') as f:
  f.write(tfliteModel)


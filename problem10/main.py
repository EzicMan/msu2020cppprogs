import numpy as np
from numpy import array
from PIL import Image
from sys import argv

image = Image.open(argv[3])
image_arr = array(image)
factor = float(argv[1])
for i in range(image_arr.shape[0]):
    for j in range(image_arr.shape[1]):
        a = image_arr[i][j][0] * factor
        b = image_arr[i][j][1] * factor
        c = image_arr[i][j][2] * factor
        if (a < 0):
            a = 0
        if (b < 0):
            b = 0
        if (c < 0):
            c = 0
        if (a > 255):
            a = 255
        if (b > 255):
            b = 255
        if (c > 255):
            c = 255
        image_arr[i][j][0] = a
        image_arr[i][j][1] = b
        image_arr[i][j][2] = c


factor = float(argv[2])
avg = 0
for i in range(image_arr.shape[0]):
    for j in range(image_arr.shape[1]):
        r, g, b = image_arr[i][j]
        avg += r * 0.299 + g * 0.587 + b * 0.114
avg /= image_arr.shape[0] * image_arr.shape[1]
palette = []
for i in range(256):
    temp = int(avg + factor * (i - avg))
    if temp < 0:
        temp = 0
    elif temp > 255:
        temp = 255
    palette.append(temp)
for i in range(image_arr.shape[0]):
    for j in range(image_arr.shape[1]):
        image_arr[i][j] = (palette[image_arr[i][j][0]],palette[image_arr[i][j][1]],palette[image_arr[i][j][2]])
new_im = Image.fromarray(image_arr)
new_im.save(argv[4])
import cv2

def resize(img, width, height):
    dim = (width, height)
    # Resize
    resized = cv2.resize(img, dim, interpolation=cv2.INTER_AREA)

    return resized


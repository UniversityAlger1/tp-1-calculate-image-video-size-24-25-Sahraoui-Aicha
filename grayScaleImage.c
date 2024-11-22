#include <string.h>
#include "config/grayScaleImage.h"

// Parameters:
//   w: width of the image
//   h: height of the image
// Return value
//   grayScale size of the image Bitmap (in bytes)
float grayScaleImage(int w, int h) {
    // 8 bits per pixel for grayscale image (1 byte per pixel)
    float bitsPerPixel = 8;
    // Calculate the size in bits
    float sizeInBits = w * h * bitsPerPixel;
    // Convert to bytes
    return sizeInBits / 8; // Return size in bytes
}

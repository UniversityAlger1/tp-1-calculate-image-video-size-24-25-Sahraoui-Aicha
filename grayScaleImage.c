#include "config/grayScaleImage.h"

// Parameters:
//   w: width of the image
//   h: height of the image
// Return value
//   grayScale size of the image Bitmap (in byte)
float grayScaleImage(int w, int h) {
   // Calculate the size of the grayscale image
   return (float)(w * h);
}

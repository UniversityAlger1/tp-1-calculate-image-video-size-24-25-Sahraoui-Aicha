#include <string.h>
#include "config/coloredBitmap.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   unit: Unit of the output value. It could be 'bt' for bits, 'ko' for kilobits, 'mo' for megabits, 'go' for gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char* unit) {
    // Bits per pixel for colored image (24 bits or 3 bytes per pixel)
    float bitsPerPixel = 24;

    // Calculate the size in bits
    float sizeInBits = w * h * bitsPerPixel;

    // Variable to store size in the requested unit
    float size;

    // Convert size based on the requested unit
    if (strcmp(unit, "bt") == 0) {
        size = sizeInBits; // Size in bits
    } else if (strcmp(unit, "ko") == 0) {
        size = sizeInBits / 1024; // Convert to kilobits
    } else if (strcmp(unit, "mo") == 0) {
        size = sizeInBits / (1024 * 1024); // Convert to megabits
    } else if (strcmp(unit, "go") == 0) {
        size = sizeInBits / (1024 * 1024 * 1024); // Convert to gigabits
    } else {
        // If the unit is not recognized, return -1 or some error value
        return -1.0f;
    }

    // Return the size in the requested unit (in bits, kilobits, megabits, or gigabits)
    return size;
}

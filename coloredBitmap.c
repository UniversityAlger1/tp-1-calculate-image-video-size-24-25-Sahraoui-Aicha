#include <string.h>
#include "config/coloredBitmap.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char* unit) {
    // Calculate the size in bits
    float size = (float)(w * h * 24);

    // Convert the size based on the unit
    if (strcmp(unit, "bt") == 0) {
        // Size is already in bits
        return size;
    } else if (strcmp(unit, "ko") == 0) {
        // Convert to kilobits
        return size / 1024;
    } else if (strcmp(unit, "mo") == 0) {
        // Convert to megabits
        return size / (1024 * 1024);
    } else if (strcmp(unit, "go") == 0) {
        // Convert to gigabits
        return size / (1024 * 1024 * 1024);
    }

    // If the unit is unrecognized, return 0
    return 0;
}

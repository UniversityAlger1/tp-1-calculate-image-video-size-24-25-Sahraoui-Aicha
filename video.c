#include <string.h>
#include <stdio.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of the movie (colored image)
//   durationCredits: duration in seconds of credits (black/white image)
//   unit: Unit of the output value. It could be 'bt' for bytes, 'ko' for kilobits, 'mo' for megabits, 'go' for gigabits
// Return value
//   colored video size (based on the unit passed parameter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Use double for higher precision
    double bitsPerPixelColor = 24.0;
    double bitsPerPixelBW = 8.0;

    // Calculate size in bits for each part
    double clrImage = (double)w * h * bitsPerPixelColor * durationMovie * fps;
    double BImage = (double)w * h * bitsPerPixelBW * durationCredits * fps;

    // Total size in bits
    double sizeInBits = clrImage + BImage;

    // Convert size based on the requested unit
    double size = -1.0; // Default error value

    if (strcmp(unit, "bt") == 0) {
        size = sizeInBits / 8.0; // Convert to bytes
    } else if (strcmp(unit, "ko") == 0) {
        size = sizeInBits / (8.0 * 1024.0); // Convert to kilobytes
    } else if (strcmp(unit, "mo") == 0) {
        size = sizeInBits / (8.0 * 1024.0 * 1024.0); // Convert to megabytes
    } else if (strcmp(unit, "go") == 0) {
        size = sizeInBits / (8.0 * 1024.0 * 1024.0 * 1024.0); // Convert to gigabytes
    }

    return size;
}


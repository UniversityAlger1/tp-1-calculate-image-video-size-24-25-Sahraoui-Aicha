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
    // Bits per pixel for colored image (24 bits)
    float bitsPerPixel = 24;

    // Calculate the size of the colored part of the video in bits
    float clrImage = w * h * bitsPerPixel * durationMovie * fps;
    
    // Calculate the size of the black/white part of the video (assumed to be 8 bits per pixel for grayscale)
    float BImage = w * h * 8 * durationCredits * fps;

    // Total size in bits (colored + black/white parts)
    float sizeInBits = clrImage + BImage;

    // Variable to hold the size in the requested unit
    float size;

    // Convert size based on the requested unit
    if (strcmp(unit, "bt") == 0) {
        size = sizeInBits / 8; // Convert to bytes
    } else if (strcmp(unit, "ko") == 0) {
        size = sizeInBits / (1024 * 8); // Convert to kilobits
    } else if (strcmp(unit, "mo") == 0) {
        size = sizeInBits / (1024 * 1024 * 8); // Convert to megabits
    } else if (strcmp(unit, "go") == 0) {
        size = sizeInBits / (1024 * 1024 * 1024 * 8); // Convert to gigabits
    } else {
        // If the unit is not recognized, return -1 or some error value
        return -1.0f;
    }

    // Return the calculated size
    return size;
}


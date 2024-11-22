#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   fps: Frames per second
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value:
//   colored video size (based on the unit passed parameter)

float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Size of the colored movie section (3 bytes per pixel for RGB)
    long long coloredSize = (long long) w * h * 3 * fps * durationMovie;

    // Size of the black-and-white credits section (1 byte per pixel for grayscale)
    long long grayscaleSize = (long long) w * h * fps * durationCredits;

    // Total size in bytes
    long long totalSize = coloredSize + grayscaleSize;

    // Convert to the requested unit
    if (strcmp(unit, "bt") == 0) {
        // Return size in bytes (already in bytes)
        return (float)totalSize;
    } else if (strcmp(unit, "ko") == 0) {
        // Convert bytes to kilobits (1 byte = 8 bits, 1 kilobit = 1024 bits)
        return (float)(totalSize * 8) / 1024;
    } else if (strcmp(unit, "mo") == 0) {
        // Convert bytes to megabits (1 byte = 8 bits, 1 megabit = 1024 kilobits)
        return (float)(totalSize * 8) / (1024 * 1024);
    } else if (strcmp(unit, "go") == 0) {
        // Convert bytes to gigabits (1 byte = 8 bits, 1 gigabit = 1024 megabits)
        return (float)(totalSize * 8) / (1024 * 1024 * 1024);
    }

    // If the unit is not recognized, return 0
    return 0;
}


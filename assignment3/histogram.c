#include "histogram.h"

int main() {
    uint8_t img[ROWS][COLS];  /* 2D array with pixel values */
    int histogram[MAX_VALUE + 1] = {0}; /* Histogram array */

    /*** Initialize random seed ***/
    srand(42);

    /*** Fill the 2D array with random values ***/
    printf("Filling the array with random values...\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            img[i][j] = rand() % (MAX_VALUE + 1); // Random values between 0 and 255
        }
    }

    /*** Compute the histogram ***/
    printf("Computing the histogram...\n");
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    /* TODO: ADD YOUR PRAGMA'S HERE */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            histogram[img[i][j]]++;
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed_time_ms = (end.tv_sec - start.tv_sec) * 1000.0 +
                             (end.tv_nsec - start.tv_nsec) / 1e6;

    /*** Print the histogram ***/
    printf("Checking answer...\n");
    bool correct = true;
    for (int i = 0; i <= MAX_VALUE; i++) {
         if (histogram[i] != expected_output[i]) {
             printf("Value %3d is incorrect. Expected: %d, Got: %d\n", i, expected_output[i], histogram[i]);
             correct = false;
         }
    }
    if (correct) {
        printf("All values are correct.\n");
    }
    printf("Execution completed in %.3f ms.\n", elapsed_time_ms);
    printf("Done.\n");

    return 0;
}

#include "matmul.h"

int main () {
    float a[NRA][NCA],           /* matrix A to be multiplied */
          b[NCA][NCB],           /* matrix B to be multiplied */
          c[NRA][NCB];           /* result matrix C */

    /*** Initialize matrices ***/
    init_matrices(a, b, c);

    /*** Do matrix multiplication  ***/
    printf("Computing matrix multiplication...\n");
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start); /* Start the timer */

    /* TODO: ADD YOUR PRAGMA'S HERE */
    for (int i=0; i<NRA; i++) {
        for(int j=0; j<NCB; j++) {
            for (int k=0; k<NCA; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end); /* End the timer */
    double elapsed_time_ms = (end.tv_sec - start.tv_sec) * 1000.0 +
                             (end.tv_nsec - start.tv_nsec) / 1e6;

    /*** Print results ***/
    printf("Matrix multiplication completed in %.3f ms.\n", elapsed_time_ms);
    printf ("Done.\n");

    return 0;
}
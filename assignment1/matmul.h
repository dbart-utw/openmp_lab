#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NRA 1000                 /* number of rows in matrix A */
#define NCA 1000                 /* number of columns in matrix A */
#define NCB 1000                  /* number of columns in matrix B */

void init_matrices(float a[NRA][NCA], float b[NCA][NCB], float c[NRA][NCB]) {
    printf("Initializing matrices...\n");
    for (int i=0; i<NRA; i++) {
        for (int j=0; j<NCA; j++) {
            a[i][j]= i+j;
        }
    }
    for (int i=0; i<NCA; i++) {
        for (int j=0; j<NCB; j++) {
            b[i][j]= i*j;
        }
    }
    for (int i=0; i<NRA; i++) {
        for (int j=0; j<NCB; j++) {
            c[i][j]= 0;
        }
    }
}
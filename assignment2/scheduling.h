#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define LIST_SIZE 100 /* Number of items in the list */

void task(int x) {
    for (int i = 0; i < x; i++) {
        usleep(1000); /* Simulate a task taking 1 millisecond */
    }
}

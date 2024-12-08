#include "scheduling.h"

int main() {
    int list[LIST_SIZE]; /* Array representing the list */

    /*** Initialize list with values from 1 to LIST_SIZE ***/
    printf("Initializing list...\n");
    for (int i = 0; i < LIST_SIZE; i++) {
        list[i] = i + 1;
    }

    /*** Process each item in the list ***/
    printf("Processing list items...\n");
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    /* TODO: ADD YOUR PRAGMA'S HERE */
    for (int i = 0; i < LIST_SIZE; i++) {
        printf("Processing item %d...\n", i);
        task(list[i]);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed_time_ms = (end.tv_sec - start.tv_sec) * 1000.0 +
                             (end.tv_nsec - start.tv_nsec) / 1e6;

    /*** Print results ***/
    printf("******************************************************\n");
    printf("All items processed in  %.3f ms.\n", elapsed_time_ms);
    printf("******************************************************\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>



#define BLOCKSIZE  5


void printAverage(int* array, int n) {
    float sum;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    float avg = sum / (float)n;
    printf("Der Durchschnitt Ihres Arrays ist: %.1f\n", avg);
}


int main() {

    printf("Geben Sie die Elemente Ihres Arrays an:\n");
    int n = 0;
    int *array = (int*)malloc(sizeof(int)*BLOCKSIZE);

    while (1) {
        printf(" > Element #%d: ", n);
        fflush(stdout);
        char buffer[64];
        fgets(buffer, 64, stdin);
        if (buffer[0] == '\n' || buffer[0] == '\r') {
            break;
        }
        int value = 0;
        if (sscanf(buffer, "%d", &value) == 0) {
            continue;
        }
        array[n] = value;
        n++;
        if (n % 5 == 0) {
            array = (int*)realloc(array, sizeof(int)*(n+BLOCKSIZE));
        }
    }

    printf("Eingabe beendet.\n");

    printAverage(array, n);

    free(array);

    return EXIT_SUCCESS;
}

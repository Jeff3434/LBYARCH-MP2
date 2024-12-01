#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define TIMES 50

void getInputs(int height, int width, double* arr) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%lf", &arr[i * width + j]);
        }
    }
}

void displayArr(int height, int width, uint8_t* output) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3d ", output[i * width + j]);
        }
        printf("\n");
    }
}

extern void imgCvtGrayDoubleToInt(int height, int width, double* arr, uint8_t* output);

int main() {
    int height, width;
    double time, totalTime, aveTime;
    struct timespec start, end;

    totalTime = 0.0;

    scanf("%d", &height);
    scanf("%d", &width);

    double* arr = malloc(height * width * sizeof(double));
    uint8_t* output = malloc(height * width * sizeof(uint8_t));

    if (!arr || !output) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    getInputs(height, width, (double*) arr);

    for (int i = 0; i < TIMES; i++) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        imgCvtGrayDoubleToInt(height, width, arr, output);
        clock_gettime(CLOCK_MONOTONIC, &end);

        time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        
        totalTime += time;
    }
    displayArr(height, width, output);
    
    aveTime = totalTime / TIMES;
    
    printf("Average time (after %d runs): %.12f seconds.", TIMES, aveTime);

    free(arr);
    free(output);

    return 0;
}
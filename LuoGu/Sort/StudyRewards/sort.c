#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_HEAP_SIZE 2000

typedef struct {
    float H[MAX_HEAP_SIZE];
} Heap;

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void adjustHeap(int k, int n, float *H) {
    float temp = H[k];
    int i;
    for (i = 2 * k; i <= n; i = 2 * i) {
        if (i < n && H[i] < H[i + 1]) {
            i++;
        }
        if (!(H[0] < H[i])) {
            break;
        } else {
            H[k] = H[i];
            k = i;
        }
    }
    H[k] = temp;
}

void buildMaxHeap(int n, float *H) {
    for (int i = n / 2; i > 0; i--) {
        adjustHeap(i, n, H);
    }
}

void heapSort(int n, float *H) {
    buildMaxHeap(n, H);
    for (int i = n; i > 0; i--) {
        swap(&H[1], &H[i]);
        adjustHeap(1, i - 1, H);
    }
}

float *findMax2(int n, float *H, float *answer) {
    heapSort(n, H);
    answer[0] = H[n];
    answer[1] = H[n - 1];
    return answer;
}

int main() {
    float answer[2] = {0};
    float H[MAX_HEAP_SIZE] = {0};
    int n = 50;

    srand(time(0));

    for (int i = 1; i <= n; i++) {
        H[i] = rand() % 100 + 1;
    }

    printf("Original array:\n");
    for (int i = 1; i <= n; i++) {
        printf("%.2f ", H[i]);
    }

    findMax2(n, H, answer);

    printf("\nSorted array:\n");
    
    for (int i = 1; i <= n; i++) {
        printf("%.2f ", H[i]);
    }
    printf("\n\nLargest two values: %f %f\n", answer[0], answer[1]);

    return 0;
}
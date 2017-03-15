#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Heap.h"

int main() {
    int n = 25;
    Heap H = newHeap(n);

    for (int i = 0; i < n - 3; i++) {
        insert(H, ((int)pow(i + 7, 5) % 97));
    }
    printf("H is:\n");
    printHeap(H);

    buildHeap(H);
    printf("\nAfter buildHeap(), H is:\n");
    printHeap(H);

    printf("\nThe max() of H is %d", extractMax(H));

    printf("\nAfter extractMax(), H is:\n");
    printHeap(H);

    heapSort(H);
    printf("\nAfter heapSort(), H is:\n");
    printHeap(H);

    freeHeap(&H);
}

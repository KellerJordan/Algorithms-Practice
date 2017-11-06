#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Heap.h"

int main() {
    int n = 12;
    Heap H = newHeap(n);

    insert(H, 5); insert(H, 3); insert(H, 7); insert(H, 1);
    insert(H, 10); insert(H, 12); insert(H, 19); insert(H, 24);
    insert(H, 5); insert(H, 7); insert(H, 2); insert(H, 6);
    
    printf("H is:\n");
    printHeap(H);

    buildHeap(H);
    printf("\nAfter buildHeap(), H is:\n");
    printHeap(H);

    printf("\nThe max() of H is %d", extractMax(H));

    // printf("\nAfter extractMax(), H is:\n");
    // printHeap(H);

    heapSort(H);
    printf("\nAfter heapSort(), H is:\n");
    printHeap(H);

    freeHeap(&H);
}

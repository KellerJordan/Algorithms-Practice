// max-priority heap

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Heap.h"


// structs --------------------------------------------------------------------

typedef struct HeapObj {
    int length,
        size,
        *k;
} HeapObj;


// Constructors-Destructors ---------------------------------------------------

Heap newHeap(int n) {
    Heap H = malloc(sizeof(HeapObj));
    H->length = n;
    H->size = 0;
    H->k = malloc(sizeof(int) * (n + 1));
    return H;
}

void freeHeap(Heap *pH) {
    if (pH != NULL && *pH != NULL) {
        Heap H = *pH;
        free(H->k);
        free(H);
        *pH = NULL;
    }
}

// Helper Functions -----------------------------------------------------------

int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }


// Access functions -----------------------------------------------------------

int length(Heap H) { return H->length; }
int size(Heap H) { return H->size; }
int max(Heap H) { return H->k[1]; }


// Manipulation procedures ----------------------------------------------------

void insert(Heap H, int k) {
    if (H->size < H->length) {
        H->k[H->size + 1] = k;
        H->size++;
    }
}

int extractMax(Heap H) {
    int k = H->k[1];
    H->k[1] = H->k[H->size];
    H->k[H->size] = k;
    H->size--;
    heapify(H, 1);
    return k;
}

void increaseKey(Heap H, int i, int k) {
    if (H->k[i] < k)
        H->k[i] = k;
    // need to re-run all of buildHeap? or easier operation
}

void heapify(Heap H, int i) {
    // find the largest of i, left(i), right(i)
    int l = left(i),
        r = right(i),
        m = i;
    if (l <= H->size && H->k[l] > H->k[i])
        m = l;
    if (r <= H->size && H->k[r] > H->k[m])
        m = r;
    
    // if the largest is one of the children of i, then swap this and i
    if (m != i) {
        int t = H->k[i];
        H->k[i] = H->k[m];
        H->k[m] = t;
        // then, call heapify on the place where i was swapped in
        heapify(H, m);      
    }
}

void buildHeap(Heap H) {
    for (int i = (H->size / 2); i >= 1; i--)
        heapify(H, i);
}

void heapSort(Heap H) {
    buildHeap(H);
    for (int i = H->size; i >= 1; i--) {
        int t = H->k[i];
        H->k[i] = H->k[1];
        H->k[1] = t;
        H->size--;
        heapify(H, 1);
    }
}


// Other operations -----------------------------------------------------------

void printHeap(Heap H) {
    for (int i = 1; i <= H->size; i++)
        printf("%d ", H->k[i]);
    printf("| ");
    for (int i = H->size + 1; i <= H->length; i++)
        printf("%d ", H->k[i]);
    printf("\n");
}
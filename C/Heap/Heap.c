// max-priority queue with max-priority heap

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Heap.h"


// structs --------------------------------------------------------------------

typedef struct HeapObj {
    int length,
        size,
        *v;
        // *k;
} HeapObj;


// Constructors-Destructors ---------------------------------------------------

Heap newHeap(int n) {
    Heap H = malloc(sizeof(HeapObj));
    H->length = n;
    H->size = 0;
    H->v = malloc(sizeof(int) * (n + 1));
    return H;
}

void freeHeap(Heap *pH) {
    if (pH != NULL && *pH != NULL) {
        Heap H = *pH;
        free(H->v);
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
int max(Heap H) { return H->v[1]; }


// Manipulation procedures ----------------------------------------------------

void insert(Heap H, int x) {
    if (H->size < H->length) {
        H->v[H->size + 1] = x;
        H->size++;
    }
}


void heapify(Heap H, int i) {
    // find the largest of i, left(i), right(i)
    int l = left(i),
        r = right(i),
        m = i;
    if (l <= H->size && H->v[l] > H->v[i])
        m = l;
    if (r <= H->size && H->v[r] > H->v[m])
        m = r;
    
    // if the largest is one of the children of i, then swap this and i
    if (m != i) {
        int t = H->v[i];
        H->v[i] = H->v[m];
        H->v[m] = t;
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
    for (int i = H->length; i >= 2; i--) {
        int t = H->v[i];
        H->v[i] = H->v[1];
        H->v[1] = t;
        H->size--;
        heapify(H, 1);
    }
}


// Other operations -----------------------------------------------------------

void printHeap(Heap H) {
    for (int i = 1; i < H->length; i++)
        printf("%d ", H->v[i]);
    printf("%d\n", H->v[H->length]);
}
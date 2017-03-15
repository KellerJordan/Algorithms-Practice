#ifndef _HEAP_H_INCLUDE_
#define _HEAP_H_INCLUDE_

#define INF -1

typedef struct HeapObj* Heap;

// Constructors-Destructors ---------------------------------------------------
Heap newHeap();
void freeHeap(Heap *pH);

// Access functions -----------------------------------------------------------
int length(Heap H);
int size(Heap H);
int max(Heap H);

// Manipulation procedures ----------------------------------------------------
void insert(Heap H, int x);
void heapify(Heap H, int i);
void buildHeap(Heap H);
void heapSort(Heap H);
// int extractMax(Heap H);
// void increaseKey(Heap H, int k0, int k);

// Other operations -----------------------------------------------------------
void printHeap(Heap H);

#endif
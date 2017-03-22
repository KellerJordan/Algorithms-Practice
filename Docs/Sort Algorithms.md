# Sorting Algorithms

### Merge
Recursively split array down to size 1, then merge sorted sub-arrays back up.
Best/Average/Worse O(nlog(n))

### Heap
Remove the root of heap, prepend to sorted array, then heapify remaining heap.
Best/Average/Worst O(nlog(n))

### Quick
Pick a pivot element. Put all elements smaller on left, larger on right. Recursively quicksort each side.
Best O(n) Average O(nlog(n)) Worst O(n^2)

### Selection
Iterate through array, swapping cursor with smallest element to it's right
Best/Average/Worst O(n^2)

### Insertion
Iterate through array, inserting each element in correct position left of cursor.
Best O(n) Average/Worst O(n^2)

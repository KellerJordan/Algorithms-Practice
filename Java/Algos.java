class Algos {
    public void selectionSort(int[] A) {
        int n = A.length;
        for (int i = 0; i < n - 1; i++) {
            int p = i;
            for (int j = i + 1; j < n; j++)
                if (A[j] < A[p]) p = j; // set p to the index of the smallest element in A[i...]
            int temp = A[i]; A[i] = A[p]; A[p] = temp; // swap A[i] and A[p]
        }
    }

    public void insertionSort(int[] A) {
        int n = A.length;
        for (int i = 1; i < n; i++) {
            int v = A[i], p = i; // v is the element being looked at
            for (; p > 0 && A[p - 1] > v; p--)
                A[p] = A[p - 1]; // shift elements between v and the index it should be at
            A[p] = v; // put v into empty slot
        }
    }
    
    public void bubbleSort(int[] A) {
        int n = A.length;
    }

    public void quickSort(int[] A) {
        int n = A.length;
    }
    
    public void mergeSort(int[] A) { mergeMain(A, 0, A.length); }
    private void mergeMain(int[] A, int p, int q) {
        if (p >= q - 1) return;
        int r = (p + q) / 2;
        mergeMain(A, p, r); mergeMain(A, r, q); // recursively sort both sub-arrays
        int[] L = new int[r - p]; int[] R = new int[q - r]; // initialize left and right temp arrays
        for (int i = p; i < r; i++) L[i - p] = A[i]; for (int i = r; i < q; i++) R[i - r] = A[i]; // fill left and right arrays
        int li = 0, ri = 0; // set subarray indices
        for (int i = p; i < q; i++) {
            if (li == L.length) { A[i] = R[ri]; ri++; }
            else if (ri == R.length || L[li] < R[ri]) { A[i] = L[li]; li++; }
            else { A[i] = R[ri]; ri++; }
        }
    }
}
class Sorts {
    public void selectionSort(int[] A) {
        int n = A.length;
        for (int i = 0; i < n - 1; i++) {
            int p = i;
            for (int j = i + 1; j < n; j++)
                if (A[j] < A[p]) p = j; // set p to the index of the smallest element in A[i...]
            swap(A, i, p);
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
        for (int i = A.length - 1; i > 1; i--) {
            for (int j = 0; j < i; j++)
                if (A[j] > A[j + 1]) swap(A, j, j + 1);
        }
    }

    public void quickSort(int[] A) {
        int n = A.length; // unimplemented
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
            if (li == L.length) A[i] = R[ri++];
            else if (ri == R.length || L[li] < R[ri]) A[i] = L[li++];
            else A[i] = R[ri++];
        }
    }

    public int mergeSortAndcountInversions(int[] A) { return mergeAndCountInversionsMain(A, 0, A.length); }
    private int mergeAndCountInversionsMain(int[] A, int p, int q) {
        if (p >= q - 1) return 0;
        int inversions = 0;
        int r = (p + q) / 2;
        inversions += mergeAndCountInversionsMain(A, p, r) + mergeAndCountInversionsMain(A, r, q);
        int[] L = new int[r - p]; int[] R = new int[q - r];
        for (int i = p; i < r; i++) L[i - p] = A[i]; for (int i = r; i < q; i++) R[i - r] = A[i];
        int li = 0, ri = 0;
        for (int i = p; i < q; i++) {
            if (li == L.length) A[i] = R[ri++];
            else if (ri == R.length || L[li] < R[ri]) A[i] = L[li++];
            else {
                A[i] = R[ri++];
                inversions += L.length - li;
            }
        }
        return inversions;
    }

    private void swap(int[] A, int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}
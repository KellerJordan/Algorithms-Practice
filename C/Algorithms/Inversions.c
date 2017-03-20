#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int inversions(int A[], int p, int r) {
    if (p < r) {
        int q, a, b, c, i, j;
        q = (p + r) / 2;

        a = inversions(A, p, q); // inversions in subset [p : q]
        b = inversions(A, q + 1, r); // inversions in [q+1 : r]
        c = 0;

        // inversions from [p : q] to [q+1 : r]
        for (i = p; i <= q; i++) {
            for (j = q + 1; j <= r; j++)
                c += (A[i] > A[j]);
        }

        return a + b + c;
    }
    return 0;
}

int main() {
    int n = 8, A[n], I, i;

    for (i = 0; i < n; i++)
        A[i] = (int)pow(i + 7, 3) % 97;

    I = inversions(A, 0, n - 1);

    printf("[");
    for (i = 0; i < n - 1; i++)
        printf("%d, ", A[i]);
    printf("%d] ", A[n - 1]);
    printf("has %d inversions.\n", I);
}
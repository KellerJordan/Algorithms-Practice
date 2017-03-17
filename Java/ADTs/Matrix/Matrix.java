@SuppressWarnings("overrides")
class Matrix {
    // Private classes and fields
    private class Entry {
        int pos;
        double val;

        Entry(int pos, double val) {
            this.pos = pos;
            this.val = val;
        }

        public boolean equals(Object x) {
            if (x == this) return true;
            if (x == null || x.getClass() != getClass()) return false;
            Entry E = (Entry) x;
            return pos == E.pos && val == E.val;
        }
        public String toString() {
            String valStr = String.format("%.2f", Math.round(val * 100.0) / 100.0);
            if (valStr.charAt(valStr.length() - 1) == '0') valStr = valStr.substring(0, valStr.length() - 1);
            return String.format("(%d, %s)", pos, valStr);
        }
    }
    private List[] rows; // How would I be able to write an equals() method with this field being private?
    private int size;

    // Constructor
    Matrix(int n) {
        if (n < 1) throw new RuntimeException("Matrix Error: initialized with n < 1");
        rows = new List[n];
        for (int i = 0; i < n; i++) rows[i] = new List();
        size = n;
    }

    // Access functions
    // returns n, the number of rows and columns of this Matrix
    int getSize() {
        return size;
    }
    // returns the number of non-zero entries in this Matrix
    int getNNZ() {
        int entries = 0;
        for (List L : rows) entries += L.length();
        return entries;
    }
    // overrides Object's equals() method
    public boolean equals(Object x) {
        if (x == this) return true;
        if (x == null || x.getClass() != getClass()) return false;
        Matrix M = (Matrix) x;
        for (int i = 0; i < size; i++) {
            List L1 = rows[i];
            List L2 = M.rows[i];
            if ((L1 == null && L2 != null) || !L1.equals(L2)) return false;
        }
        return true;
    }

    // Helper functions
    // computes dot product of two matrix rows represented by P and Q
    private static double dot(List P, List Q) {
        double result = 0;
        if (P == Q) {
            for (P.moveFront(); P.index() != -1; P.moveNext()) {
                Entry E = (Entry) P.get();
                result += E.val * E.val;
            }
        } else {
            P.moveFront();
            Q.moveFront();
            while (P.index() != -1 && Q.index() != -1) {
                Entry E1 = (Entry) P.get();
                Entry E2 = (Entry) Q.get();
                if (E1.pos < E2.pos) P.moveNext();
                else if (E2.pos < E1.pos) Q.moveNext();
                else {
                    result += E1.val * E2.val;
                    P.moveNext();
                    Q.moveNext();
                }
            }
        }
        return result;
    }

    // Manipulation procedures
    // sets this Matrix to the zero state
    void makeZero() {
        for (List L : rows) L.clear();
    }
    // returns a new Matrix having the same entries as this Matrix
    Matrix copy() {
        Matrix M = new Matrix(size);
        for (int i = 0; i < size; i++) {
            List L = rows[i];
            for (L.moveFront(); L.index() != -1; L.moveNext()) {
                Entry E = (Entry) L.get();
                M.changeEntry(i + 1, E.pos, E.val);
            }
        }
        return M;
    }
    // changes ith row, jth column of this Matrix to x
    // pre: 1<=i<=getSize(), 1<=j<=getSize()
    void changeEntry(int i, int j, double x) {
        if (i < 1 || i > size) throw new RuntimeException("Matrix Error: changeEntry() called with out of bounds i");
        if (j < 1 || j > size) throw new RuntimeException("Matrix Error: changeEntry() called with out of bounds j");
        if (x != 0) {
            Entry E = new Entry(j, x);
            List L = rows[i - 1];
            for (L.moveBack(); L.index() != -1; L.movePrev())
                if (j >= ((Entry) L.get()).pos) break;
            if (L.index() == -1)
                L.prepend(E);
            else {
                Entry F = (Entry) L.get();
                if (F.pos == j) F.val = x;
                else L.insertAfter(E);
            }
        }
    }
    // returns a new Matrix that is the scalar product of this Matrix with x
    Matrix scalarMult(double x) {
        Matrix M = new Matrix(size);
        for (int i = 0; i < size; i++) {
            List L = rows[i];
            for (L.moveFront(); L.index() != -1; L.moveNext()) {
                Entry E = (Entry) L.get();
                M.changeEntry(i + 1, E.pos, E.val * x);
            }
        }
        return M;
    }
    // returns a new Matrix that is the sum of this Matrix with M
    // pre: getSize()==M.getSize()
    Matrix add(Matrix M) {
        if (size != M.size) throw new RuntimeException("Matrix Error: add() called with differently sized M");
        Matrix N = new Matrix(size);
        for (int i = 0; i < size; i++) {
            List L1 = rows[i];
            List L2 = M.rows[i];
            if (L1 != L2) {
                L1.moveFront();
                L2.moveFront();
                while (L1.index() != -1 || L2.index() != -1) {
                    Entry E1 = L1.index() != -1 ? (Entry) L1.get() : null;
                    Entry E2 = L2.index() != -1 ? (Entry) L2.get() : null;
                    if (E2 == null || E1 != null && E1.pos < E2.pos) {
                        N.changeEntry(i + 1, E1.pos, E1.val);
                        L1.moveNext();
                    } else if (E1 == null || E2 != null && E2.pos < E1.pos) {
                        N.changeEntry(i + 1, E2.pos, E2.val);
                        L2.moveNext();
                    } else {
                        N.changeEntry(i + 1, E1.pos, E1.val + E2.val);
                        L1.moveNext();
                        L2.moveNext();
                    }
                }
            } else {
                for (L1.moveFront(); L1.index() != -1; L1.moveNext()) {
                    Entry E = (Entry) L1.get();
                    N.changeEntry(i + 1, E.pos, E.val + E.val);
                }
            }
        }
        return N;
    }
    // returns a new Matrix that is the difference of this Matrix with M
    // pre: getSize()==M.getSize()
    Matrix sub(Matrix M) {
        if (size != M.size) throw new RuntimeException("Matrix Error: sub() called with differently sized M");
        Matrix N = new Matrix(size);
        if (this != M) {
            for (int i = 0; i < size; i++) {
                List L1 = rows[i];
                List L2 = M.rows[i];
                L1.moveFront();
                L2.moveFront();
                while (L1.index() != -1 || L2.index() != -1) {
                    Entry E1 = L1.index() != -1 ? (Entry) L1.get() : null;
                    Entry E2 = L2.index() != -1 ? (Entry) L2.get() : null;
                    if (E2 == null || E1 != null && E1.pos < E2.pos) {
                        N.changeEntry(i + 1, E1.pos, E1.val);
                        L1.moveNext();
                    } else if (E1 == null || E2 != null && E2.pos < E1.pos) {
                        N.changeEntry(i + 1, E2.pos, 0 - E2.val);
                        L2.moveNext();
                    } else {
                        N.changeEntry(i + 1, E1.pos, E1.val - E2.val);
                        L1.moveNext();
                        L2.moveNext();
                    }
                }
            }
        }
        return N;
    }
    
    // returns a new Matrix that is the transpose of this Matrix
    Matrix transpose() {
        Matrix M = new Matrix(size);
        for (int i = 0; i < size; i++) {
            List L = rows[i];
            for (L.moveFront(); L.index() != -1; L.moveNext()) {
                Entry E = (Entry) L.get();
                M.changeEntry(E.pos, i + 1, E.val);
            }
        }
        return M;
    }
    // returns a new Matrix that is the product of this Matrix with M
    // pre: getSize()==M.getSize()
    Matrix mult(Matrix M) {
        if (size != M.size) throw new RuntimeException("Matrix Error: mult() called with differently sized M");
        Matrix N = new Matrix(size);
        Matrix T = M.transpose();
        for (int i = 0; i < size; i++) {
            List L1 = rows[i];
            if (L1.length() != 0) {
                for (int j = 0; j < size; j++) {
                    List L2 = T.rows[j];
                    if (L2.length() != 0)
                        N.changeEntry(i + 1, j + 1, dot(L1, L2));
                }
            }
        }
        return N;
    }

    // Other functions
    // overrides Object's toString() method
    public String toString() {
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < size; i++) {
            List L = rows[i];
            if (L.length() != 0)
                sb.append(String.format("%d: %s\n", i + 1, L.toString()));
        }
        return new String(sb);
    }
}
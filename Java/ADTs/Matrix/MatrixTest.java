class MatrixTest {
    public static void main(String[] args) {
        int n = 3;
        Matrix A = new Matrix(n);
        Matrix B = new Matrix(n);

        A.changeEntry(1,1,1); B.changeEntry(1,1,1);
        A.changeEntry(1,2,2); B.changeEntry(1,2,0);
        A.changeEntry(1,3,3); B.changeEntry(1,3,1);
        A.changeEntry(2,1,4); B.changeEntry(2,1,0);
        A.changeEntry(2,2,5); B.changeEntry(2,2,1);
        A.changeEntry(2,3,6); B.changeEntry(2,3,0);
        A.changeEntry(3,1,7); B.changeEntry(3,1,1);
        A.changeEntry(3,2,8); B.changeEntry(3,2,1);
        A.changeEntry(3,3,9); B.changeEntry(3,3,1);

        System.out.println(String.format("Matrix A has %d non-zero entries and is:", A.getNNZ()));
        System.out.println(A);

        System.out.println("Matrix B is:");
        System.out.println(B);

        System.out.println("A.scalarMult(3.2) is:");
        System.out.println(A.scalarMult(3.2));

        System.out.println("A.add(B) is:");
        System.out.println(A.add(B));

        System.out.println("A.sub(B) is:");
        System.out.println(A.sub(B));

        System.out.println("B.transpose is:");
        System.out.println(B.transpose());

        System.out.println("A.mult(B) is:");
        System.out.println(A.mult(B));

        System.out.println("A.copy() is:");
        System.out.println(A.copy());

        System.out.println("A.equals(A.copy()) is:");
        System.out.println(A.equals(A.copy()));

        System.out.println("A.equals(B) is:");
        System.out.println(A.equals(B));

        System.out.println("After calling A.makeZero(), A is:");
        A.makeZero();
        System.out.println(A);
    }
}
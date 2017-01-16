import java.util.Random;

class Client {
    public static void printArr(int[] A) {
        System.out.print("{ ");
        for (int i = 0; i < A.length - 1; i++)
            System.out.print(A[i] + ", ");
        System.out.println(A[A.length - 1] + " }");
    }

    public static void fillArr(int[] A) {
        int n = A.length; Random randGen = new Random();
        for (int i = 0; i < n; i++) A[i] = randGen.nextInt(n);
    }

    public static void main(String[] args) {
        int n1, n2;
        int[] A;
        Sorts sortAlgos = new Sorts();
        long start, t1, t2;

        // merge sort
        // n1 = 1000000; A = new int[n1]; fillArr(A); start = System.nanoTime(); sortAlgos.mergeSort(A); t1 = (System.nanoTime() - start) / 1000000;
        // n2 = 10000000; A = new int[n2]; fillArr(A); start = System.nanoTime(); sortAlgos.mergeSort(A); t2 = (System.nanoTime() - start) / 1000000;
        // System.out.printf("Merge sort took %d times as long with %d times the n.\n", t2/t1, n2/n1);
        // // insertion sort
        // n1 = 40000; A = new int[n1]; fillArr(A); start = System.nanoTime(); sortAlgos.insertionSort(A); t1 = (System.nanoTime() - start) / 1000000;
        // n2 = 400000; A = new int[n2]; fillArr(A); start = System.nanoTime(); sortAlgos.insertionSort(A); t2 = (System.nanoTime() - start) / 1000000;
        // System.out.printf("Insertion sort took %d times as long with %d times the n.\n", t2/t1, n2/n1);
        // // selection sort
        // n1 = 100000; A = new int[n1]; fillArr(A); start = System.nanoTime(); sortAlgos.selectionSort(A); t1 = (System.nanoTime() - start) / 1000000;
        // n2 = 1000000; A = new int[n2]; fillArr(A); start = System.nanoTime(); sortAlgos.selectionSort(A); t2 = (System.nanoTime() - start) / 1000000;
        // System.out.printf("Selection sort took %d times as long with %d times the n.\n", t2/t1, n2/n1);
    }
}
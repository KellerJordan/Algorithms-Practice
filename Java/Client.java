import java.util.Random;

public class Client {
    public static void printArr(int[] A) {
        System.out.print("{ ");
        for (int i = 0; i < A.length - 1; i++)
            System.out.print(A[i] + ", ");
        System.out.println(A[A.length - 1] + " }");
    }

    public static void fillArr(int[] A) {
        Random randGen = new Random();
        for (int i = 0; i < A.length; i++) {
            A[i] = randGen.nextInt();
        }
    }

    public static void main(String[] args) {
        int n = 15;
        int[] A = new int[n];
        Algos myAlgos = new Algos();
        
        printArr(A);
        myAlgos.mergeSort(A);
        printArr(A);
    }
}
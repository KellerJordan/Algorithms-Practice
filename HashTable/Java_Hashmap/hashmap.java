public class hashmap {
    static int[] hashArr = new int[11];

    public static int hash(int k, int i) {
        return (k % 11 + i * (1 + k % 10)) % 11;
    }

    public static void insert(int k) {
        String result = k + ": ";
        int i = 0; int p = 0;
        do {
            p = hash(k, i);
            result += p + ", ";
            i++;
        } while (hashArr[p] != 0);
        hashArr[p] = k;

        System.out.println(result);
    }

    public static void main(String[] args) {
        insert(34);
        insert(25);
        insert(79);
        insert(56);
        insert(6);
    }
}
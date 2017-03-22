class GraphTest {
    public static void main(String[] args) {
        // PROBLEM 10
        int n = 4;
        Graph G = new Graph(n);
        G.addEdge(1, 1, -1); G.addEdge(1, 2, -1);
        G.addEdge(2, 3, 2); G.addEdge(2, 4, 1);
        G.addEdge(3, 4, -3);

        // int n = 10;
        // Graph G = new Graph(n);
        // G.addEdge(1, 2, 1);
        // G.addEdge(2, 3, 2); G.addEdge(2, 5, 2); G.addEdge(2, 6, 3); G.addEdge(2, 7, 1);
        // G.addEdge(3, 7, 2);
        // G.addEdge(4, 3, 2); G.addEdge(4, 8, 1);
        // G.addEdge(5, 9, 1); G.addEdge(5, 1, 1);
        // G.addEdge(6, 9, 2);
        // G.addEdge(8, 3, 1); G.addEdge(8, 4, 3);
        // G.addEdge(9, 10, 1);
        // G.addEdge(10, 6, 1); G.addEdge(10, 7, 3);

        System.out.println(G);

        G.BellmanFord(2);
        System.out.println();
        G.printDistances();
    }
}
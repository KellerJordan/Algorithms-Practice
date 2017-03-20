#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main() {
    // PROBLEM 10
    // int n = 4;
    // Graph G = newGraph(n);
    // addEdge(G, 1, 1, -1); addEdge(G, 1, 2, -1);
    // addEdge(G, 2, 3, 2); addEdge(G, 2, 4, 1);
    // addEdge(G, 3, 4, -3);

    // PROBLEM 11
    int n = 10;
    Graph G = newGraph(n);
    addEdge(G, 1, 2, 1);
    addEdge(G, 2, 3, 2); addEdge(G, 2, 5, 2); addEdge(G, 2, 6, 3); addEdge(G, 2, 7, 1);
    addEdge(G, 3, 7, 2);
    addEdge(G, 4, 3, 2); addEdge(G, 4, 8, 1);
    addEdge(G, 5, 9, 1); addEdge(G, 5, 1, 1);
    addEdge(G, 6, 9, 2);
    addEdge(G, 8, 3, 1); addEdge(G, 8, 4, 3);
    addEdge(G, 9, 10, 1);
    addEdge(G, 10, 6, 1); addEdge(G, 10, 7, 3);

    printGraph(stdout, G);
    printf("G has size %d", getSize(G));
    printf("\n");

    int valid = BellmanFord(G, 2);

    if (valid) printf("worked!");
    else printf("did not work!");

    freeGraph(&G);
}

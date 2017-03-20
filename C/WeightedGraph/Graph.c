// Directed Weighted Graph ADT with Bellman-Ford and Dijkstra algorithms

#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

// structs --------------------------------------------------------------------

typedef struct GraphObj {
    int
        **edges, // edge weight matrix
        *p, // parent
        *d, // distance from source
        order, // |V(G)|
        size, // |E(G)|
        source;
} GraphObj;


// Constructors-Destructors ---------------------------------------------------

Graph newGraph(int n) {
    int len = n + 1;
    Graph G = malloc(sizeof(GraphObj));
    G->edges = malloc(sizeof(int*) * len);
    G->p = malloc(sizeof(int) * len);
    G->d = malloc(sizeof(int) * len);
    for (int u = 1; u <= n; u++) {
        G->edges[u] = malloc(sizeof(int) * len);
        for (int v = 1; v <= n; v++)
            G->edges[u][v] = INF;
        G->p[u] = NIL;
        G->d[u] = INF;
    }
    G->order = n;
    G->size = 0;
    G->source = NIL;
    return G;
}

void freeGraph(Graph *pG) {
    if (pG != NULL && *pG != NULL) {
        Graph G = *pG;
        for (int u = 1; u <= G->order; u++)
            free(&(G->edges[u]));
        free(G->edges);
        free(G->p);
        free(G->d);
        free(G);
        *pG = NULL;
    }
}


// Access functions -----------------------------------------------------------

int getOrder(Graph G) { return G->order; }

int getSize(Graph G) { return G->size; }

int getSource(Graph G) { return G->source; }

int getParent(Graph G, int u) {
    if (0 >= u || u > getOrder(G)) {
        printf("Graph Error: calling getParent() with out of bounds u\n");
        exit(1);
    }
    return G->p[u];
}

int getDist(Graph G, int u) {
    if (0 >= u || u > getOrder(G)) {
        printf("Graph Error: calling getDist() with out of bounds u\n");
        exit(1);
    }
    return G->d[u];
}

void getPath(List L, Graph G, int u) {
    if (getSource(G) == NIL) {
        printf("Graph Error: calling getPath() on graph with no source\n");
        exit(1);
    }
    if (0 >= u || u > getOrder(G)) {
        printf("Graph Error: calling getPath() with out of bounds u\n");
        exit(1);
    }
    if (getDist(G, u) == INF)
        prepend(L, NIL);
    else {
        int v = u;
        while (v != 0) {
            prepend(L, v);
            v = G->p[v];
        }
    }
}


// Helper functions -----------------------------------------------------------

void initialize(Graph G, int s) {
    for (int i = 1; i <= G->order; i++) {
        G->p[i] = NIL;
        G->d[i] = INF;
    }
    G->d[s] = 0;
}

void relax(Graph G, int u, int v) {
    if (G->d[v] > G->d[v] + G->edges[u][v]) {
        G->d[v] = G->d[v] + G->edges[u][v];
        G->p[v] = u;
    }
}


// Manipulation procedures ----------------------------------------------------

void addEdge(Graph G, int u, int v, int w) {
    if (0 >= u || u > getOrder(G)) {
        printf("Graph Error: calling addEdge() with out of bounds u\n");
        exit(1);
    }
    if (0 >= v || v > getOrder(G)) {
        printf("Graph Error: calling addEdge() with out of bounds v\n");
        exit(1);
    }
    G->edges[u][v] = w;
    G->size++;
}

int BellmanFord(Graph G, int s) {
    initialize(G, s);
    // repeat |V(G)|-1 times
    for (int i = 1; i < G->order; i++) {
        // for each (u,v) in E(G), relax(u,v)
        for (int u = 1; u <= G->order; u++) {
            for (int v = 1; v <= G->order; v++) {
                if (G->edges[u][v] != INF)
                    relax(G, u, v);
            }
        }
    }

    for (int u = 1; u <= G->order; u++) {
        for (int v = 1; v <= G->order; v++) {
            if (G->d[v] > G->d[u] + G->edges[u][v]) {
                printf("d[v]:%d d[u]:%d w(u,v):%d", G->d[v], G->d[u], G->edges[u][v]);
                return 0;
            }
        }
    }
    return 1;
}

void Dijkstra(Graph G, int s) {

}


// Other operations -----------------------------------------------------------

void printGraph(FILE* out, Graph G) {
    for (int u = 1; u <= G->order; u++) {
        fprintf(out, "%d:", u);
        for (int v = 1; v <= G->order; v++) {
            int w = G->edges[u][v];
            if (w != INF)
                fprintf(out, " %d(w=%d)", v, w);
        }
        fprintf(out, "\n");
    }
}
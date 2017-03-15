// Graph with DFS algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

// structs --------------------------------------------------------------------

typedef struct GraphObj {
    List* edges;
    int *color,
        *p,
        *d,
        order,
        size,
        source;
} GraphObj;


// Constructors-Destructors ---------------------------------------------------

Graph newGraph(int n) {
    int len = n + 1;
    Graph G = malloc(sizeof(GraphObj));
    G->edges = malloc(sizeof(List) * len);
    G->color = malloc(sizeof(int) * len);
    G->p = malloc(sizeof(int) * len);
    G->d = malloc(sizeof(int) * len);
    for (int i = 1; i <= n; i++) {
        G->edges[i] = newList();
        G->color[i] = 0;
        G->p[i] = NIL;
        G->d[i] = INF;
    }
    G->order = n;
    G->size = 0;
    G->source = NIL;
    return G;
}

void freeGraph(Graph* pG) {
    Graph G = *pG;
    if (pG != NULL && *pG != NULL) {
        for (int i = 1; i <= (*pG)->order; i++)
            freeList(&(G->edges[i]));
        free(G->edges);
        free(G->color);
        free(G->p);
        free(G->d);
        free(*pG);
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


// Manipulation procedures ----------------------------------------------------

void makeNull(Graph G) {
    for (int i = 1; i <= G->order; i++)
        clear(G->edges[i]);
}

void addEdge(Graph G, int u, int v) {
    if (0 >= u || u > getOrder(G)) {
        printf("Graph Error: calling addEdge() with out of bounds u\n");
        exit(1);
    }
    if (0 >= v || v > getOrder(G)) {
        printf("Graph Error: calling addEdge() with out of bounds v\n");
        exit(1);
    }
    List L;
    L = G->edges[u];
    for (moveFront(L); 1; moveNext(L)) {
        if (index(L) == -1) {
            append(L, v);
            break;
        }
        if (v < get(L)) {
            insertBefore(L, v);
            break;
        }
    }
    L = G->edges[v];
    for (moveFront(L); 1; moveNext(L)) {
        if (index(L) == -1) {
            append(L, u);
            break;
        }
        if (u < get(L)) {
            insertBefore(L, u);
            break;
        }
    }
    G->size++;
}

void addArc(Graph G, int u, int v) {
    if (0 >= u || u > getOrder(G)) {
        printf("Graph Error: calling addArc() with out of bounds u\n");
        exit(1);
    }
    if (0 >= v || v > getOrder(G)) {
        printf("Graph Error: calling addArc() with out of bounds v\n");
        exit(1);
    }
    List L = G->edges[u];
    for (moveFront(L); 1; moveNext(L)) {
        if (index(L) == -1) {
            append(L, v);
            break;
        }
        if (v < get(L)) {
            insertBefore(L, v);
            break;
        }
    }
    G->size++;
}

void BFS(Graph G, int s) {
    // reset graph
    for (int i = 1; i <= G->order; i++) {
        G->color[i] = 0;
        G->p[i] = NIL;
        G->d[i] = INF;
    }

    // setup base case
    G->source = s;
    List Q = newList();
    append(Q, s);
    G->color[s] = 1;
    G->p[s] = NIL;
    G->d[s] = 0;
    
    // iterate through reachable nodes
    while (length(Q) > 0) {
        int v = front(Q);
        List L = G->edges[v];
        for (moveFront(L); index(L) != -1; moveNext(L)) {
            int u = get(L);
            if (G->color[u] == 0) {
                append(Q, u);
                G->color[u] = 1;
                G->p[u] = v;
                G->d[u] = G->d[v] + 1;
            }
        }
        G->color[v] = 2;
        deleteFront(Q);
    }

    // free objects
    freeList(&Q);
}


// Other operations -----------------------------------------------------------

void printGraph(FILE* out, Graph G) {
    for (int i = 1; i <= G->order; i++) {
        fprintf(out, "%d: ", i);
        printList(out, G->edges[i]);
    }
}
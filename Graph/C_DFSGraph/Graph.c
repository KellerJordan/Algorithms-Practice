// Graph ADT with DFS

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
        *f,
        order,
        size;
} GraphObj;


// Constructors-Destructors ---------------------------------------------------

Graph newGraph(int n) {
    int len = n + 1;
    Graph G = malloc(sizeof(GraphObj));
    G->edges = malloc(sizeof(List) * len);
    G->color = malloc(sizeof(int) * len);
    G->p = malloc(sizeof(int) * len);
    G->d = malloc(sizeof(int) * len);
    G->f = malloc(sizeof(int) * len);
    for (int i = 1; i <= n; i++) {
        G->edges[i] = newList();
        G->color[i] = 0;
        G->p[i] = NIL;
        G->d[i] = UNDEF;
        G->f[i] = UNDEF;
    }
    G->order = n;
    G->size = 0;
    return G;
}

void freeGraph(Graph *pG) {
    if (pG != NULL && *pG != NULL) {
        Graph G = *pG;
        for (int i = 1; i <= G->order; i++)
            freeList(&(G->edges[i]));
        free(G->edges);
        free(G->color);
        free(G->p);
        free(G->d);
        free(G->f);
        free(G);
        *pG = NULL;
    }
}


// Access functions -----------------------------------------------------------

int getOrder(Graph G) { return G->order; }

int getSize(Graph G) { return G->size; }

int getParent(Graph G, int u) {
    if (1 > u || u > getOrder(G)) {
        printf("Graph Error: calling getParent() with out of bounds u\n");
        exit(1);
    }
    return G->p[u];
}

int getDiscover(Graph G, int u) {
    if (1 > u || u > getOrder(G)) {
        printf("Graph Error: calling getDiscover() with out of bounds u\n");
        exit(1);
    }
    return G->d[u];
}

int getFinish(Graph G, int u) {
    if (1 > u || u > getOrder(G)) {
        printf("Graph Error: calling getFinish() with out of bounds u\n");
        exit(1);
    }
    return G->f[u];
}


// Manipulation procedures ----------------------------------------------------

void addEdge(Graph G, int u, int v) {
    if (1 > u || u > getOrder(G)) {
        printf("Graph Error: calling addEdge() with out of bounds u\n");
        exit(1);
    }
    if (1 > v || v > getOrder(G)) {
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
    if (1 > u || u > getOrder(G)) {
        printf("Graph Error: calling addArc() with out of bounds u\n");
        exit(1);
    }
    if (1 > v || v > getOrder(G)) {
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

// unchecked pre: S contains permutation of { 1, 2, ..., n }
void DFS(Graph G, List S) {
    if (length(S) != G->order) {
        printf("Graph Error: calling DFS() with List of different length than Graph's order");
        exit(1);
    }

    // reset graph
    for (int i = 1; i <= G->order; i++) {
        G->color[i] = 0;
        G->p[i] = NIL;
        G->d[i] = UNDEF;
        G->f[i] = UNDEF;
    }
    int time = 1;

    // helper visit function which uses the time variable declared in this scope
    void visit(int u) {
        G->color[u] = 1;
        G->d[u] = time++;

        List L = G->edges[u];
        for (moveFront(L); index(L) != -1; moveNext(L)) {
            int v = get(L);
            if (G->color[v] == 0) {
                G->p[v] = u;
                visit(v);
            }
        }

        G->color[u] = 2;
        G->f[u] = time++;
        prepend(S, u);
    }

    for (moveFront(S); index(S) != -1; moveNext(S)) {
        int u = get(S);
        if (G->color[u] == 0) {
            G->p[u] = NIL;
            visit(u);
        }
    }
    // clear ordering entries in back
    for (int i = 1; i <= G->order; i++)
        deleteBack(S);
}


// Other operations -----------------------------------------------------------

Graph transpose(Graph G) {
    Graph H = newGraph(G->order);
    for (int i = 1; i <= G->order; i++) {
        List L = G->edges[i];
        for (moveFront(L); index(L) != -1; moveNext(L))
            addArc(H, get(L), i);
    }
    return H;
}

Graph copyGraph(Graph G) {
    Graph H = newGraph(G->order);
    for (int i = 1; i <= G->order; i++) {
        List L = G->edges[i];
        for (moveFront(L); index(L) != -1; moveNext(L))
            addArc(H, i, get(L));
    }
    return H;
}

void printGraph(FILE* out, Graph G) {
    for (int i = 1; i <= G->order; i++) {
        fprintf(out, "%d: ", i);
        printList(out, G->edges[i]);
    }
}
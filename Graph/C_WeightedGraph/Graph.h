#include "../List/List.h"

#ifndef _GRAPH_H_INCLUDE_
#define _GRAPH_H_INCLUDE_

#define INF 536870912
#define NIL 0

typedef struct GraphObj* Graph;

// Constructors-Destructors ---------------------------------------------------
Graph newGraph(int n);
void freeGraph(Graph* pG);

// Access functions -----------------------------------------------------------
int getOrder(Graph G);
int getSize(Graph G);
int getSource(Graph G);
int getParent(Graph G, int u);
int getDist(Graph G, int u);
void getPath(List L, Graph G, int u);

// Manipulation procedures ----------------------------------------------------
void addEdge(Graph G, int u, int v, int w);
void Dijkstra(Graph G, int s);
int BellmanFord(Graph G, int s);

// Other operations -----------------------------------------------------------
void printGraph(FILE* out, Graph G);

#endif
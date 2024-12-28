#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED

#include <iostream>

#define firstVertex(G) G.firstVertex
#define firstEdge(E) E->firstEdge
#define nextVertex(V) V->next
#define nextEdge(E) E->nextEdge

using namespace std;

typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;

struct vertex {
    string idVertex;
    adrVertex next;
    adrEdge firstEdge;
};

struct edge {
    string destVertexID;
    int gold;
    int xp;
    int jarak;
    bool hidup;
    adrEdge nextEdge;
};

struct graph {
    adrVertex firstVertex;
};

void createVertex(string newVertexID, adrVertex &v);

void initGraph(graph &G);

void addVertex(graph &G, string newVertexID);

void buildGraph(graph &G);

void showVertex(graph G);

adrVertex searchVertex(graph G, string vertexID);

void createEdge(graph &G, string vertexId, string destVertexId, int gold, int xp, int jarak, bool hidup);

void connectVertex(graph &G, string vertexId, string destVertexId, int gold, int xp, int jarak, bool hidup);

void initEdge(graph &G);

void shortestRoute(graph &G, string startVertex);


#endif // GRAF_H_INCLUDED

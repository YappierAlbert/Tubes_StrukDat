#include "graf.h"
using namespace std;

void createVertex(string newVertexID, adrVertex &v){
    v = new vertex;
    v->idVertex = newVertexID;
    nextVertex(v) = NULL;
    firstEdge(v) = NULL;
}

void initGraph(graph &G){
    firstVertex(G) = NULL;
}

void addVertex(graph &G, string newVertexID){
    adrVertex P, Q;
    createVertex(newVertexID, P);

    if (firstVertex(G) == NULL) {
        firstVertex(G) = P;
    } else {
        Q = firstVertex(G);
        while (nextVertex(Q) != NULL) {
            Q = nextVertex(Q);
        }
        nextVertex(Q) = P;
    }
}

void buildGraph(graph &G){
    initGraph(G);
    addVertex(G, "BuffBiru");
    addVertex(G, "BuffMerah");
    addVertex(G, "KadalBiru");
    addVertex(G, "GolemApi");
    addVertex(G, "Kumbang");
    addVertex(G, "KeongXP");
    addVertex(G, "KeongGold");
}

void showVertex(graph G) {
    adrVertex v = firstVertex(G);
    while (v != NULL) {
        cout << "Vertex: " << v->idVertex << endl;
        adrEdge e = firstEdge(v);
        while (e != NULL) {
            cout << "  Edge to " << e->destVertexID << ", Gold: " << e->gold << ", XP: " << e->xp << ", Jarak: " << e->jarak << endl;
            e = nextEdge(e);
        }
        v = nextVertex(v);
    }
}

adrVertex searchVertex(graph G, string vertexID) {
    adrVertex v = firstVertex(G);
    while (v != NULL) {
        if (v->idVertex == vertexID) {
            return v;
        }
        v = nextVertex(v);
    }
    return NULL;
}

void createEdge(adrVertex &v, string destVertexId, int gold, int xp, int jarak, bool hidup) {
    adrEdge e = new edge;
    e->destVertexID = destVertexId;
    e->gold = gold;
    e->xp = xp;
    e->jarak = jarak;
    e->hidup = hidup;
    nextEdge(e) = NULL;

    if (firstEdge(v) == NULL) {
        firstEdge(v) = e;
    } else {
        adrEdge p = firstEdge(v);
        while (nextEdge(p) != NULL) {
            p = nextEdge(p);
        }
        nextEdge(p) = e;
    }
}

void connectVertex(graph &G, string vertexId, string destVertexId, int gold, int xp, int jarak, bool hidup) {
    adrVertex v = searchVertex(G, vertexId);
    if (v != NULL) {
        createEdge(v, destVertexId, gold, xp, jarak, hidup);
    } else {
        cout << "Vertex " << vertexId << " not found!" << endl;
    }
}

void initEdge(graph &G){
    connectVertex(G,"BuffBiru","BuffMerah",123,130,15,true);
    connectVertex(G,"BuffBiru","KadalBiru",100,70,10,true);
    connectVertex(G,"BuffBiru","GolemApi",92,60,17,true);
    connectVertex(G,"BuffBiru","Kumbang",118,50,28,true);
    connectVertex(G,"BuffBiru","KeongXP",0,60,40,true);
    connectVertex(G,"BuffBiru","KeongGold",80,0,17,true);

    connectVertex(G,"BuffMerah","BuffBiru",130,150,15,true);
    connectVertex(G,"BuffMerah","KadalBiru",100,70,30,true);
    connectVertex(G,"BuffMerah","GolemApi",92,60,5,true);
    connectVertex(G,"BuffMerah","Kumbang",118,50,11,true);
    connectVertex(G,"BuffMerah","KeongXP",0,60,28,true);
    connectVertex(G,"BuffMerah","KeongGold",80,0,43,true);

    connectVertex(G,"KadalBiru","BuffBiru",130,150,10,true);
    connectVertex(G,"KadalBiru","BuffMerah",123,130,30,true);
    connectVertex(G,"KadalBiru","GolemApi",92,60,32,true);
    connectVertex(G,"KadalBiru","Kumbang",118,50,45,true);
    connectVertex(G,"KadalBiru","KeongXP",0,60,60,true);
    connectVertex(G,"KadalBiru","KeongGold",80,0,10,true);

    connectVertex(G,"GolemApi","BuffBiru",130,150,17,true);
    connectVertex(G,"GolemApi","BuffMerah",123,130,5,true);
    connectVertex(G,"GolemApi","KadalBiru",100,70,32,true);
    connectVertex(G,"GolemApi","Kumbang",118,50,11,true);
    connectVertex(G,"GolemApi","KeongXP",0,60,21,true);
    connectVertex(G,"GolemApi","KeongGold",80,0,39,true);

    connectVertex(G,"Kumbang","BuffBiru",130,150,28,true);
    connectVertex(G,"Kumbang","BuffMerah",123,130,11,true);
    connectVertex(G,"Kumbang","KadalBiru",100,70,45,true);
    connectVertex(G,"Kumbang","GolemApi",92,60,11,true);
    connectVertex(G,"Kumbang","KeongXP",0,60,15,true);
    connectVertex(G,"Kumbang","KeongGold",80,0,59,true);

    connectVertex(G,"KeongXP","BuffBiru",130,150,40,true);
    connectVertex(G,"KeongXP","BuffMerah",123,130,28,true);
    connectVertex(G,"KeongXP","KadalBiru",100,70,60,true);
    connectVertex(G,"KeongXP","GolemApi",92,60,21,true);
    connectVertex(G,"KeongXP","Kumbang",118,50,15,true);
    connectVertex(G,"KeongXP","KeongGold",80,0,57,true);

    connectVertex(G,"KeongGold","BuffBiru",130,150,17,true);
    connectVertex(G,"KeongGold","BuffMerah",123,130,43,true);
    connectVertex(G,"KeongGold","KadalBiru",100,70,10,true);
    connectVertex(G,"KeongGold","GolemApi",92,60,39,true);
    connectVertex(G,"KeongGold","Kumbang",118,50,59,true);
    connectVertex(G,"KeongGold","KeongXP",0,60,57,true);
}

void shortestRoute(graph &G, string startVertex) {
    adrVertex currentVertex = searchVertex(G, startVertex);
    if (currentVertex == NULL) {
        cout << "Start vertex " << startVertex << " not found!" << endl;
        return;
    }

    cout << "Starting route from " << startVertex << ":" << endl;

    string mark[7];
    int i = 0;

    while (true) {
        mark[i] = currentVertex->idVertex;
        i++;

        adrEdge closestEdge = NULL;
        adrEdge e = firstEdge(currentVertex);
        int minDistance = e->jarak;

        while (e != NULL) {
            bool alreadyVisited = false;
            for (int j = 0; j < i; j++) {
                if (mark[j] == e->destVertexID) {
                    alreadyVisited = true;
                    break;
                }
            }

            if ( e->hidup && e->jarak < minDistance) {
                closestEdge = e;
                minDistance = e->jarak;
            }

            e = nextEdge(e);
        }

        if (closestEdge == NULL) {
            cout << "No more reachable vertices from " << currentVertex->idVertex << "." << endl;
            break;
        }

        cout << "  -> To " << closestEdge->destVertexID
             << " (Distance: " << closestEdge->jarak << ")" << endl;

        closestEdge->hidup = false;
        currentVertex = searchVertex(G, closestEdge->destVertexID);
    }

    cout << "Route completed." << endl;
}



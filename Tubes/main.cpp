#include <iostream>

using namespace std;

#include "graf.h"

int main() {
    string input;
    graph G;
    initGraph(G);
    buildGraph(G);
    initEdge(G);
    showVertex(G);
    cout << "Masukkan Inputan : ";
    cin >> input;
    shortestRoute(G,input);
    return 0;
}

#include <iostream>

using namespace std;

#include "graf.h"

void menu(){
    cout << "=====================================" << endl;
    cout << "       Rute Farm Mobile Legend       " << endl;
    cout << "=====================================" << endl;
    cout << "1.Print Graf             " << endl;
    cout << "2.Rute Farming           " << endl;
    cout << "3.Rute XP Terbanyak      " << endl;
    cout << "4.Rute Gold Terbanyak    " << endl;
    cout << "0.Exit                   " << endl;
    cout << "=====================================" << endl;
    cout << "Masukkan Inputan : ";
}

int main() {
    string input;
    int pilih;
    graph G;
    initGraph(G);
    buildGraph(G);
    initEdge(G);
    menu();
    cin >> pilih;
    while(pilih != 0){
        if(pilih == 1){
            showVertex(G);
        }else if(pilih == 2){
            initEdge(G);
            cout << "Masukkan Titik Awal Anda : ";
            cin >> input;
            shortestRoute(G,input);
        }else if(pilih == 3){
            cout << "Masukkan Titik Awal Anda : ";
            cin >> input;
            initEdge(G);
            highestXp(G,input);
        }else if(pilih == 4){
            cout << "Masukkan Titik Awal Anda : ";
            cin >> input;
            initEdge(G);
            highestGold(G,input);
        }else{
            cout << "Input Salah!!" << endl;
        }
        menu();
        cin >> pilih;
    }

    return 0;
}

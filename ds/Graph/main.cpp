#include <iostream>
#include <ctime>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "Component.h"


using namespace std;

int main() {

/*
    int N = 20;
    int M = 100;

    srand(time(nullptr));

    // Sparse Graph
    SparseGraph g1(N , false);
    for( int i = 0 ; i < M ; i ++ ){
        int a = rand()%N;
        int b = rand()%N;
        g1.addEdge( a , b );
    }

    // O(E)
    for( int v = 0 ; v < N ; v ++ ){
        cout<<v<<" : ";
        SparseGraph::adjIterator adj( g1 , v );
        for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
            cout<<w<<" ";
        cout<<endl;
    }

    cout<<endl;


    // Dense Graph
    DenseGraph g2(N , false);
    for( int i = 0 ; i < M ; i ++ ){
        int a = rand()%N;
        int b = rand()%N;
        g2.addEdge( a , b );
    }

    // O(V^2)
    for( int v = 0 ; v < N ; v ++ ){
        cout<<v<<" : ";
        DenseGraph::adjIterator adj( g2 , v );
        for( int w = adj.begin() ; !adj.end() ; w = adj.next() )
            cout<<w<<" ";
        cout<<endl;
    }
*/

    string filename = "graph.txt";

    SparseGraph g1(7, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename);
    g1.show();

    cout << endl;

    DenseGraph g2(7, false);
    ReadGraph<DenseGraph> readGraph2(g2, filename);
    g2.show();

    //通过DFS查看连通分量数
    Component<SparseGraph> component1(g1);
    cout << "Component count : " << component1.count() << endl;
    if(component1.isConnected(0, 1))
        cout << "Vertex 0 and 1 is connected." << endl;


    return 0;
}

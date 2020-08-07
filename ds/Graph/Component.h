//
// Created by 16435 on 2020/8/7.
//

//TODO 应用:用来求连通分量

#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename Graph>
class Component {
private:
    Graph &G;
    bool *visited;
    int ccount;
    int *id;    //具有相同id值的下标顶点相互连通

    void DFS(int v) {
        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G, v);
        for(int i = adj.begin(); !adj.end(); i = adj.next()) {
            if(!visited[i])
                DFS(i);
        }
    }

public:
    Component(Graph &graph): G(graph) {
        visited = new bool[G.V()];
        id = new int[G.V()];
        ccount = 0;
        for(int i = 0; i < G.V(); i ++) {
            visited[i] = false;
            id[i] = -1;
        }


        for(int i = 0; i < G.V(); i ++)
            if(!visited[i]) {
                DFS(i);
                ccount ++;
            }
    }

    ~Component() {
        delete[] visited;
        delete[] id;
    }

    int count() {
        return ccount;
    }

    bool isConnected(int v, int w) {
        assert(v >= 0 && v < G.V());
        assert(w >= 0 && w < G.V());
        return id[v] == id[w];
    }
};


#endif //GRAPH_COMPONENT_H

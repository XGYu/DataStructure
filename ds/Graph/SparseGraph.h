//
// Created by 16435 on 2020/8/6.
//

#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//TODO 稀疏图 一般使用 邻接表来存储
class SparseGraph {
private:
    int n, m;
    bool directed;
    vector<vector<int>> g;  //使用vector是为了方便
                            //这样表示可能会引入平行边

public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->m = m;
        this->directed = directed;
        for(int i = 0; i < n; i ++)
            g.push_back(vector<int>());

    }

    ~SparseGraph() {

    }

    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        g[v].push_back(w);
        if(v != w && !directed)
            g[w].push_back(v);

        m ++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        for(int i = 0; i < g[v].size(); i ++)
            if(g[v][i] == w)
                return true;

        return false;
    }
};


#endif //GRAPH_SPARSEGRAPH_H
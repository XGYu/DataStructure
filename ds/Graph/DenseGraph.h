//
// Created by 16435 on 2020/8/6
//

#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//TODO 稠密图 一般使用 邻接矩阵来存储
class DenseGraph {
private:
    int n, m;   //n表示点 m表示边
    bool directed;  //表示是否为有向图
    vector<vector<bool>> g;

public:
    //初始化这个邻接矩阵
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for(int i = 0; i < n; i ++) {
            g.push_back(vector<bool>(n, false));
        }
    }

    ~DenseGraph() {

    }

    int V() { return n;}
    int E() { return m;}

    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        assert(v != w);
        if(hasEdge(v, w))   return;

        g[v][w] = true;
        if(!directed)
            g[w][v] = true;

        m ++;   //添加成功，则边数+1
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && v < n);

        return g[v][w];
    }
};

#endif //GRAPH_DENSEGRAPH_H

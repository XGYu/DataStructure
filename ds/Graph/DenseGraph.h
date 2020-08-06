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

    void show() {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++)
                cout << g[i][j] << "\t";
            cout << endl;
        }
    }

    //TODO 邻边迭代器，传入一个图和一个顶点
    class adjIterator {
    private:
        DenseGraph &G;
        int v;
        int index;

    public:
        adjIterator(DenseGraph &graph, int v): G(graph) {
            assert(v >= 0 && v < G.n);
            this->v = v;
            this->index = -1;
        }

        ~adjIterator() {

        }

        //返回图中与顶点v相连的第一个顶点
        int begin() {
            index = -1; //由于要使用next()，所以index从-1开始
            return next();
        }

        //返回与顶点v相连的下一个顶点
        int next() {
            for(index += 1; index < G.V(); index ++)
                if(G.g[v][index])
                    return index;

            return -1;
        }

        //查看是否已经迭代完成了与v相连接的所有顶点
        bool end() {
            return index >= G.V();
        }
    };

};



#endif //GRAPH_DENSEGRAPH_H

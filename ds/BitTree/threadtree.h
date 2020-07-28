//
// Created by yuxingguo on 2020-07-28.
//              线索二叉树
//

#ifndef BITTREE_THREADTREE_H
#define BITTREE_THREADTREE_H

#include <iostream>

using namespace std;

typedef struct ThreadNode {
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;     //*tag = 0, 表示指向左右孩子结点，*tag=1，表示指向前驱或后继
}ThreadNode, *ThreadTree;

ThreadNode *pre = nullptr;  //pre总是指向当前遍历结点的前驱

void visit(ThreadNode *q) {
    if(q->lchild == nullptr) {  //左子树空的时候，就可以利用这个空指针其建立前驱结点了
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre != nullptr && pre->rchild == nullptr) {  //建立后继结点
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

//中序遍历同时创建线索二叉树
void InThread(ThreadTree T) {
    if(T != nullptr) {
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

//完善对开头和结尾的一些处理
void CreateInThread(ThreadTree T) {
    pre = nullptr;
    if(T != nullptr) {
        InThread(T);
        if(pre->rchild == nullptr)
            pre->rtag = 1;  //最后被访问的节点没有后继，所以它的后继结点为null，但是仍把rtag设为1
    }
}




#endif //BITTREE_THREADTREE_H

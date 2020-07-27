//
// Created by yuxingguo on 2020-07-27.
//

#ifndef BITTREE_BITREE_H
#define BITTREE_BITREE_H

#include <iostream>

using namespace std;

typedef struct BiNode {
    int data;
    struct BiNode *lchild, *rchild;
    //如果在使用场景中需要大量遍历父节点，则可以加设*parent，但是考研中一般没有parent
}BiNode, *BiTree;

void visit(BiTree T) {
    cout << T->data << " ";
}

//先序遍历
void PreOrder(BiTree T) {
    if(T != nullptr) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//中序遍历
void InOrder(BiTree T) {
    if(T != nullptr) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

//后序遍历
void PostOrder(BiTree T) {
    if(T != nullptr) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}


#endif //BITTREE_BITREE_H

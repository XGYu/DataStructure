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

//链式队列结点，用于二叉树的层次遍历
typedef struct LinkNode {
    BiNode *data;
    struct LinkNode *next;
}LinkNode;

typedef struct {
    LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q) {
    //带头结点
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = nullptr;
}

bool IsEmpty(LinkQueue Q) {
    return Q.front == Q.rear ? true : false;
}

void EnQueue(LinkQueue &Q, BiNode *e) {
    auto *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = nullptr;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, BiTree &e) {
    if(Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front->next;
    cout << p->data << endl;
    e = p->data;
    Q.front->next = p->next;

    //如果队列只有一个元素，出队后，队尾指针要回到头结点，否则free后会丢失
    if(Q.front == p)
        Q.rear = Q.front;
    free(p);
    return true;
}

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

//层序遍历
void LevelOrder(BiTree T) {
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);
    while(!IsEmpty(Q)) {
        DeQueue(Q, p);
        visit(p);
        if(p->lchild != nullptr)
            EnQueue(Q, p->lchild);
        cout << p->lchild << endl;
        if(p->rchild != nullptr)
            EnQueue(Q, p->rchild);
    }
}

#endif //BITTREE_BITREE_H

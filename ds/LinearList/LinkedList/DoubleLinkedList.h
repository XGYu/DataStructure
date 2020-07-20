//
// Created by yuxingguo on 2020-07-06.
//

#include <iostream>

using namespace std;

#ifndef LINKEDLIST_DOUBLELINKEDLIST_H
#define LINKEDLIST_DOUBLELINKEDLIST_H

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
}DNode, *DLinkedList;   //实际上，DNode * <==> DLinkedList

//初始化一个双链表
bool InitDLinkedList(DLinkedList &L) {
    L = (DNode *)malloc(sizeof(DNode));
    if(L == nullptr)
        return false;
    L->prior = nullptr;
    L->next = nullptr;
    return true;
}

//打印双链表
void PrintDList(DLinkedList L) {
    DNode *p = L;
    p = p->next;
    while(p->next != nullptr) {
        printf("%d<->",p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}

//双链表的插入
//在p结点后面插入新结点s
bool InsertNextDNode(DNode *p, DNode *s) {
    if(p == nullptr || s == nullptr)
        return false;
    s->next = p->next;
    //如果p是双链表最后一个结点，p->next->prior会出现问题
    if(p->next != nullptr)
        p->next->prior = s;
    p->next = s;
    s->prior = p;
    return true;
}


#endif //LINKEDLIST_DOUBLELINKEDLIST_H

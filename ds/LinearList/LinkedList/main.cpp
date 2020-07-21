#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"

int main() {
    while(true) {
        LinkedList L;
        InitList(L);
        ListTailInsert(L);
        PrintList(L);
        if(isSym(L, ListLength(L)))     cout << "中心对称." << endl;
        else    cout << "不对称." << endl;
    }



/*
    DLinkedList dl;
    InitDLinkedList(dl);
    auto *s = (DNode *)malloc(sizeof(DNode));
    s->data = 1;
    InsertNextDNode(dl,s);
    auto *t = (DNode *)malloc(sizeof(DNode));
    t->data = 2;
    InsertNextDNode(dl->next, t);
    PrintDList(dl);
*/
    return 0;
}
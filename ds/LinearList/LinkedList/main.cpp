#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"

int main() {

    LinkedList L;
    InitList(L);
    ListTailInsert(L);
    PrintList(L);
    FindCommonList(L, L);


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
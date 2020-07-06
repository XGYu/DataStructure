#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"

int main() {

    int e;
    LinkedList L = ListHeaderInsert(L);
    PrintList(L);

    ListReverse(L);
    PrintList(L);

    return 0;
}
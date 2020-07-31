#include "bitree.h"
#include "threadtree.h"

int main() {
    BiTree T;

    T = (BiTree)malloc(sizeof(BiNode));
    T->data = 1;
    T->lchild = (BiTree)malloc(sizeof(BiNode));
    T->lchild->data = 2;
    T->lchild->lchild = T->lchild->rchild = nullptr;
    T->rchild = (BiTree)malloc(sizeof(BiNode));
    T->rchild->data = 3;
    T->rchild->lchild = T->rchild->rchild = nullptr;
    PreOrder(T);
    cout << endl;
    InOrder(T);
    cout << endl;
    PostOrder(T);
    cout << endl;
    LevelOrder(T);

    return 0;
}
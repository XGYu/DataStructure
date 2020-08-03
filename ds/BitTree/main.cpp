#include "bitree.h"
#include "threadtree.h"
#include "bst.h"

int main() {
    /*
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
    cout << endl;
     */

    BSTree T;
    int arr[8] = {50, 66, 60, 26, 21, 30, 70, 68};
    CreateBST(T, arr, 8);
    InOrderBST(T);
    cout << endl;

    return 0;
}
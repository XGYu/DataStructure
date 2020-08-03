//
// Created by yuxingguo on 2020/8/2.
//

#ifndef BITTREE_BST_H
#define BITTREE_BST_H

#include <iostream>

using namespace std;

typedef struct BSTNode {
    int key;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

//TODO 二叉排序树的非递归插入
//TODO 最差空间复杂度O(1)
bool BSTInsert(BSTree &T, int key) {
    BSTree temp = T;
    BSTree parent = T;
    BSTNode *value = nullptr;
    while(temp != nullptr && key != temp->key) {
        if(key < temp->key) {
            parent = temp;
            temp = temp->lchild;
        }

        else {
            parent = temp;
            temp = temp->rchild;
        }
    }
    if(temp == nullptr) {
        value = (BSTNode *)malloc(sizeof(BSTNode));
        value->key = key;
        value->lchild =value->rchild = nullptr;
        if(key<parent->key)
            parent->lchild = value;
        else
            parent->rchild = value;

        cout << value->key << endl;
        return true;
    }
    return false;
}

//TODO 二叉排序树的递归插入
//TODO 最差空间复杂度O(h) h:二叉树的深度
bool BSTReverseInsert(BSTree &T, int key) {
    if(T == nullptr) {
        T=(BSTNode *)malloc(sizeof(BSTNode));
        T->key = key;
        T->lchild = T->rchild = nullptr;
        return true;
    }

    else if(key == T->key)
        return false;   //如果BST中已有这个值,则插入失败

    else if(key <T->key)
        return BSTReverseInsert(T->lchild, key);
    else
        return BSTReverseInsert(T->rchild, key);
}

//TODO 创建一棵二叉排序树
void CreateBST(BSTree &T, int arr[], int n) {
    T = nullptr;
    for(int i = 0; i < n; i ++) {
        BSTInsert(T, arr[i]);
    }
}

//TODO 中序打印一棵二叉排序树
//TODO 因为中序遍历二叉排序树是有序的
void InOrderBST(BSTree T) {
    if(T != nullptr) {
        InOrderBST(T->lchild);
        cout << T->key << " ";
        InOrderBST(T->rchild);
    }
}

//TODO 二叉排序树的非递归查找
//TODO 最差空间复杂度O(1)
BSTNode *BSTSearch(BSTree T, int key) {
    while(T != nullptr && key != T->key) {
        if(key < T->key)    T = T->lchild;
        else    T = T->rchild;
    }
    return T;   //最后返回的T,要么为空,要么是需要的结点指针
}

//TODO 二叉排序树的递归查找
//TODO 最差空间复杂度O(h) h:二叉树的深度
BSTNode *BSTReverseSearch(BSTree T, int key) {
    if(T == nullptr)    return nullptr;
    if(key == T->key)   return T;
    if(key < T->key)    return BSTReverseSearch(T->lchild, key);
    else    return BSTReverseSearch(T->rchild, key);
}



#endif //BITTREE_BST_H

//
// Created by yuxingguo on 2020-07-28.
//              线索二叉树
//          这里是比较重要的内容
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

//创建中序线索二叉树：完善对开头和结尾的处理
void CreateInThread(ThreadTree T) {
    pre = nullptr;
    if(T != nullptr) {
        InThread(T);
        if(pre->rchild == nullptr)
            pre->rtag = 1;  //最后被访问的节点没有后继，所以它的后继结点为null，但是仍把rtag设为1
    }
}

//先序遍历同时创建线索二叉树
//TODO 只有先序线索二叉树要解决循环遍历的问题
void PreThread(ThreadTree T) {
    if(T != nullptr) {
        visit(T);
        if(T->ltag != 1)    //如果T->lchild为空，visit(T)会把T的左子树指向前驱结点，如果不加这个条件判断，可能会导致无限循环
            PreThread(T->lchild);
        PreThread(T->rchild);
    }
}

//创建先序线索二叉树：完善对开头和结尾的处理
void CreatePreThread(ThreadTree T) {
    pre = nullptr;
    if(T != nullptr) {
        PreThread(T);
        if(pre->rchild == nullptr)
            pre->rtag = 1;
    }
}

//后序遍历同时创建线索二叉树
void PostThread(ThreadTree T) {
    if(T != nullptr) {
        PostThread(T->lchild);
        PostThread(T->rchild);
        visit(T);
    }
}

//创建后序线索二叉树：完善对开头和结尾的处理
void CreatePostOrder(ThreadTree T) {
    pre = nullptr;
    if(T != nullptr) {
        PostThread(T);
        if(pre->rchild == nullptr)
            pre->rtag = 1;
    }
}

//TODO 利用线索二叉树可以实现的应用：

//TODO 1.通过中序线索二叉树进行非递归的中序遍历

//找到以p为根节点的(子)树中第一个被访问的节点
ThreadNode *FirstNode(ThreadNode *p) {
    //这个循环相当于是找到了根节点的最前驱结点
    while(p->ltag != 1)
        p = p->lchild;
    return p;
}

//找到p结点的直接后继结点，注意，p结点本身可能不包含任何前驱后继信息
ThreadNode *NextNode(ThreadNode *p) {
    if(p->rtag != 1)    return FirstNode(p->rchild);    //找到以p->rchild为根结点的子树的最前驱结点
    else return p->rchild;
}

//中序遍历主函数
void InOrder(ThreadTree T) {
    for(ThreadNode *p = FirstNode(T); p != nullptr;p = NextNode(p))
        cout << p->data << " "; //相当于是visit(p),但这个.h文件visit函数有其他用处
}


//TODO 2.通过中序线索二叉树进行逆向中序遍历

//找到以p为根结点的(子)树中最后一个被访问的结点
ThreadNode *LastNode(ThreadNode *p) {
    //这个循环相当于是找到了根节点的最后继结点
    while(p->rtag != 1)
        p = p->rchild;
    return p;
}

//找到p结点的直接前驱结点
ThreadNode *PreNode(ThreadNode *p) {
    if(p->ltag == 0) return LastNode(p->lchild);
    else return p->lchild;
}

//逆向中序遍历主函数
void ReverseInOrder(ThreadTree T) {
    for(ThreadNode *p = LastNode(T);p != nullptr;p = PreNode(p))
        cout << p->data << " ";
}

#endif //BITTREE_THREADTREE_H

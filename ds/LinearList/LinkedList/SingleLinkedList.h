//
// Created by yuxingguo on 2020-07-06.
//

#include <iostream>

using namespace std;

#ifndef LINKEDLIST_SINGLELINKEDLIST_H
#define LINKEDLIST_SINGLELINKEDLIST_H

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkedList;

//初始化一个空的单链表
//带有头结点
bool InitList(LinkedList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    if(L == nullptr)       //内存分配失败
        return false;
    L->next = nullptr;
    return true;
}

//使用尾插法建立一个新的链表
LinkedList ListTailInsert(LinkedList &L) {
    int e;
    L = (LinkedList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    cin >> e;
    while(e != -1) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        r->next = s;
        r = s;
        cin >> e;
    }
    r->next = nullptr;
    return L;
}

//使用头插法建立一个新链表
//TODO 使用这个思想，可以实现链表的逆置
LinkedList ListHeaderInsert(LinkedList &L) {
    int e;
    L = (LinkedList)malloc(sizeof(LNode));
    L->next = nullptr;  //如果不写这句话，L->next可能会指向某个不确定的内存区域
    LNode *s, *r = L;
    cin >> e;
    while(e != -1) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = r->next;
        r->next = s;
        cin >> e;
    }
    return L;

}

//使用头插法的思想实现链表的逆置
void ListReverse(LinkedList &L) {
    LNode *s, *r = L;
    r = r->next;
    L->next = nullptr;  //如果不写这句话，逆置后的链表尾可能会指向某个不确定的内存区域
    while(r != nullptr) {
        s = r;
        r = r->next;
        s->next = L->next;
        L->next = s;
    }
}


//打印链表
void PrintList(LinkedList L) {
    L = L->next;
    while(L->next != nullptr) {
        printf("%d->",L->data);
        L = L->next;
    }
    printf("%d\n", L->data);
}

//按位查找
LNode *GetElem(LinkedList L, int i) {
    if(i < 0)
        return nullptr;
    LNode *p;
    p = L;
    int j = 0;
    while(p != nullptr && j < i) {
        p=p->next;
        j++;
    }
    return p;
}

//按值查找
LNode *LocateElem(LinkedList L, int e) {
    LNode *p = L->next;
    while(p != nullptr && p->data != e)
        p=p->next;

    return p;
}

//后插法,即在指定的结点之后插入结点
bool InsertNextNode(LNode *p, int e) {
    if(p == nullptr)   //不可以在一个空结点的后面插入新结点
        return false;

    auto *s = (LNode *)malloc(sizeof(LNode));
    if(s == nullptr)   //内存分配失败
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//前插法，即在某个指定结点之前插入结点
//TODO 这是一个非常巧妙的方法，即仍然在p的后面插入一个新的结点，但是把这两个结点交换数据
//TODO 就相当于是在p的前面插入了结点
bool InsertPriorNode(LNode *p, int e) {
    if(p == nullptr)
        return false;

    auto *s = (LNode *)malloc(sizeof(LNode));
    if(s == nullptr)   //内存分配失败
        return false;

    s->data = p->data;
    s->next = p->next;
    p->next = s;
    p->data = e;
    return true;
}

//按位序插入一个结点
//如果要在第i个位置插入结点，只需遍历到第i-1个（不包含头结点）位置即可
bool ListInsert(LinkedList &L, int i, int e){
    if(i < 1)
        return false;
    LNode *p = GetElem(L, i-1);
    InsertNextNode(p, e);
}


//按位序删除一个节点
bool ListDelete(LinkedList &L, int i, int &e) {
    if(i < 1)   //i值不合法
        return false;
    LNode *p = GetElem(L, i-1);

    if(p == nullptr)   //i值不合法
        return false;
    if(p->next == nullptr) //第i-1个结点之后已经无其他结点
        return false;

    LNode *q = p->next; //q就是待删除的结点
    e = q->data;        //传回要删除的结点值
    p->next = q->next;  //直接跨过待删除的结点
    free(q);            //释放掉q结点的内存
    return true;
}

//删除一个指定的结点
//TODO 同样，这也是一个非常巧妙的方法，把p后面的结点数据复制到p上，然后删除掉q结点就好了
//TODO 但是这段代码有bug，就是当p是最后一个结点时，会出现错误
bool DeleteNode(LNode *p) {
    if(p == nullptr)
        return false;
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}


//TODO 习题2 删除单链表中所有值为x的结点并释放空间
void DelX(LinkedList &L, int x) {
    LNode *pre = L, *p = L->next, *q;
    while(p != nullptr) {
        if(p->data == x) {  //删掉结点
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else {      //向前推进
            pre = p;
            p = p->next;
        }
    }
}

//TODO 习题3 使用递归反向输出链表
void ReversePrint_1(LinkedList L) {
    if(L->next!= nullptr) {
        ReversePrint_1(L->next);
    }
    if(L != nullptr && L->data != 0)
        cout << L->data << " ";
}
//TODO 习题3 使用链表逆置反向输出链表
//这个方法会改变链表的指向，如果不希望改变链表，则不要使用这个方法
void ReversePrint_2(LinkedList L) {
    ListReverse(L);
    PrintList(L);
}

//习题8 计算链表长度
int ListLen(LinkedList L) {
    int len = 0;
    while(L->next != nullptr) {
        len ++;
        L = L->next;
    }
    return len;
}

//TODO 习题8 寻找两个单链表的公共部分
//连个单链表若有公共部分，则其拓扑结构应该为Y型
//分别计算两个单链表的长度，从短链表的长度处同时遍历，直到遇到第一个公共结点，后面均为公共结点
void FindCommonList(LinkedList L1, LinkedList L2) {
    int len1 = ListLen(L1), len2 = ListLen(L2), dis = len1>len2?len1-len2:len2-len1;
    LinkedList longList, shortList;
    if(len1 > len2) {
        longList = L1;
        shortList = L2;
    }
    else {
        longList = L2;
        shortList = L1;
    }
    while(dis--)
        longList = longList->next;
    while(longList != nullptr) {
        if(longList == shortList) {
            PrintList(longList);
            return;
        }
        else {  //同时向下一结点推进
            longList = longList->next;
            shortList = shortList->next;
        }
    }
}

#endif //LINKEDLIST_SINGLELINKEDLIST_H

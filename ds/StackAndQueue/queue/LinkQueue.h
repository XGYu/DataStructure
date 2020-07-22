//
// Created by yuxingguo on 2020-07-22.
//

#ifndef QUEUE_LINKQUEUE_H
#define QUEUE_LINKQUEUE_H

#include <iostream>

#define MaxSize 100

using namespace std;

namespace L {

    typedef struct {
        int data;
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

    //带头结点的队列在插入元素时不用区分队列是否空
    //入队一定会成功，所以不用返回值
    void EnQueue(LinkQueue &Q, int e) {
        LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = e;
        s->next = nullptr;
        Q.rear->next = s;
        Q.rear = s;
    }

    bool DeQueue(LinkQueue &Q, int &e) {
        if(Q.front == Q.rear)
            return false;
        LinkNode *p = Q.front->next;
        e = p->data;
        Q.front->next = p->next;
        //如果队列只有一个元素，出队后，队尾指针要回到头结点，否则free后会丢失
        if(Q.front == p)
            Q.rear = Q.front;
        free(p);
        return true;
    }

};



#endif //QUEUE_LINKQUEUE_H

//
// Created by yuxingguo on 2020-07-22.
//

#ifndef QUEUE_SQQUEUE_H
#define QUEUE_SQQUEUE_H

#include <iostream>

#define MaxSize 100

using namespace std;

namespace S {
    typedef struct {
        int data[MaxSize];
        int front, rear;
        int size;
    }SqQueue;

    void InitQueue(SqQueue &Q) {
        //初始时，队头和队尾都指向第一个元素
        //尾指针指向队尾元素位置，而不是队尾的下一个位置
        //本来Q.rear=MaxSize-1，但是由于我们现在增设了size参数，可以很容易的区分空和满
        Q.front = Q.rear = 0;
        Q.size = 0;
    }

    bool QueueEmpty(SqQueue Q) {
        return Q.size == 0 ? true : false;
    }

    bool EnQueue(SqQueue &Q, int e) {
        if(Q.size == MaxSize)
            return false;
        Q.rear = (Q.rear+1)%MaxSize;
        Q.data[Q.rear] = e;
        Q.size ++;
        return true;
    }

    bool DeQueue(SqQueue &Q, int &e) {
        if(Q.size == 0)
            return false;
        e = Q.data[Q.front];
        Q.front = (Q.front+1)%MaxSize;
        Q.size --;
        return true;
    }

    bool GetHead(SqQueue Q, int &e) {
        if(Q.size == 0)
            return false;
        e = Q.data[Q.front];
        return true;
    }

};

#endif //QUEUE_SQQUEUE_H

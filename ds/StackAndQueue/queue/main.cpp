#include "SqQueue.h"

using namespace S;

//TODO 习题3.3.4 车上过江渡船
void manager(SqQueue &q, SqQueue &q1, SqQueue &q2) {
    int i = 0, j = 0;   //i指本轮次上车数，j指船上的总车辆数
    while(j < 10) {
        if(!QueueEmpty(q1) && i < 4) {
            int bus;
            DeQueue(q1, bus);
            EnQueue(q, bus);
            i ++;
            j ++;
        }
        else if(!QueueEmpty(q2) && i == 4) {
            int van;
            DeQueue(q2, van);
            EnQueue(q, van);
            i = 0;  //装载一辆货车后，本轮上车次数应清0
            j ++;
        }

        else {
            //什么时候会来到这个分支呢？
            //①q1空了，可以填装多辆货车
            //②q2空了，不进入while分支，直接赋i=0 然后继续填装汽车
            while(j < 10 && i < 4 && !QueueEmpty(q2)) {
                int van;
                DeQueue(q2, van);
                EnQueue(q, van);
                j ++;
                i ++;
            }
            i = 0;
        }
        if(QueueEmpty(q1) && QueueEmpty(q2))
            j = 10;
    }
}



int main() {
    SqQueue q;      //渡船的队列
    SqQueue q1;     //客车的队列
    SqQueue q2;     //货车的队列

    InitQueue(q);
    InitQueue(q1);
    InitQueue(q2);

    int car = 0, van = 1;
    int i = 0;
    while(i < 5) {
        EnQueue(q1, car);
        EnQueue(q2, van);
        i++;
    }
    manager(q, q1, q2);
    while(!QueueEmpty(q)){
        int e;
        DeQueue(q, e);
        cout << e << " ";
    }
    cout << endl;


    return 0;
}
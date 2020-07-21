#include <iostream>

#define MaxSize 100

using namespace std;

typedef struct{
    int data[MaxSize];
    int top;            //栈顶指针
}Stack;

void InitStack(Stack S) {
    S.top = -1;         //让栈顶指针指向栈顶元素
                        //此时栈顶还没有元素，故为-1
}

bool StackEmpty(Stack S) {
    if(S.top == -1)
        return true;
    else
        return false;
}

//TODO 栈的增删改查操作
bool Push(Stack &S, int x) {
    if(S.top == MaxSize-1)
        return false;

    S.data[++S.top] = x;
    return true;
}

bool Pop(Stack &S, int &e) {
    if(S.top == -1)
        return false;
    e = S.data[S.top--];
    return true;
}

bool GetTop(Stack S, int &e) {
    if(S.top == -1)
        return false;
    e = S.data[S.top];
    return true;
}



int main() {

    return 0;
}
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


int main() {

    return 0;
}
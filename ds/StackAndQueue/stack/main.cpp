#include <iostream>

#define MaxSize 100

using namespace std;

//栈部分的题目大多以选择简答的形式出现，所以代码部分不如上一部分的线性表内容多
//栈就是一种受限的线性表，只要熟练掌握了顺序表和链表，这部分就没问题

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


//TODO 习题3 判断出入栈序列是否合法
//示例 IOIIOIOO IIIIOOOO
bool isLegalIOStack(char arr[]) {
    int i = 0, IONum = 0;
    while(arr[i] != '\0') {
        if(arr[i] == 'I')
            IONum ++;
        else    IONum--;
        if(IONum < 0)
            return false;
        i++;
    }
    if(IONum != 0)
        return false;
    return true;
}


int main() {


    return 0;
}
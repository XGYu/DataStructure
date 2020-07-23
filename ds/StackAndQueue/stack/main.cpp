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

//TODO 栈的应用：括号匹配
//1:[ 2:[ 3:{ 4:) 5:] 6:}
bool IsParMatch(int *arr) {
    int i = 0;
    Stack S;
    InitStack(S);
    while(arr[i] != '\0') {
        if(arr[i] == 1 || arr[i] == 2 || arr[i] == 3) {
            Push(S, arr[i]);
        } else {
            if (StackEmpty(S))
                return false;

            int topPar;
            Pop(S, topPar);
            if (arr[i] == 1 && topPar != 4)
                return false;
            if (arr[i] == 2 && topPar != 5)
                return false;
            if (arr[i] == 3 && topPar != 6)
                return false;
        }

        i ++;
    }
    return StackEmpty(S);
}



int main() {

        int arr[] = {1, 2, 3, 3, 5, 4};

        if(IsParMatch(arr))
            cout << "括号匹配成功！" << endl;
        else
            cout << "括号匹配不成功！" << endl;

    return 0;
}
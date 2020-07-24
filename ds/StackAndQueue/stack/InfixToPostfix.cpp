//
// 栈的应用：中缀表达式转化为后缀表达式并求值
// Created by yuxingguo on 2020-07-23.
//

/*****
 * 中缀表达式转化为后缀表达式的思路：
 * ①遇到操作数，直接加入后缀表达式
 * ②遇到界限符：遇到'('直接入栈，遇到')'弹出运算符并依次加入后缀表达式，但是')'不加入后缀表达式
 * ③遇到运算符：弹出优先级高于或等于当前运算符的所有运算符加入后缀表达式，遇到'('或栈空为止，之后再把当前运算符入栈
 *
 *用栈实现后缀表达式计算的思路：
 *①从左向右扫描所有的元素
 *②扫描到操作数则入栈，回到①；否则执行③
 *③遇到运算符，弹出两个栈顶元素，先弹出的放在运算符右侧，后弹出的放在运算符左侧
 *
 * 默认我们输入的中缀表达式都是正确的
 *****/


#include <iostream>

#define MaxSize 100

using namespace std;

typedef struct{
    char data[MaxSize];
    int size;
}Stack;

bool InitStack(Stack &S) {
    S.size = 0;
    return true;
}

bool StackEmpty(Stack S) {
    return S.size == 0;
}

bool Push(Stack &S, char c) {
    if(S.size == MaxSize)
        return false;
    else
        S.data[S.size++] = c;
    return true;
}

bool Pop(Stack &S, char &c) {
    if(S.size == 0)
        return false;
    else
        c = S.data[--S.size];
    return true;
}

bool GetTop(Stack S, char &c) {
    if(S.size == 0)
        return false;
    else
        c = S.data[--S.size];
    S.size++;
    return true;
}

//判断c2操作符的优先级是否高于或等于c1
bool isHighPriority(char c1, char c2) {
    if(c2 == '*' || c2 == '/')
        return true;
    if((c2 == '+' || c2 == '-') && (c1 == '+' || c1 == '-'))
        return true;
    return false;
}

//TODO 中缀表达式转换成后缀表达式
void InfixToPostfix(char *InStr, char *PostStr) {
    Stack S;
    InitStack(S);
    int j = 0;
    for(int i = 0;InStr[i] != '\0';i ++) {
        //我们把A-Z看成是操作数
        if(InStr[i]>='A' && InStr[i]<='Z')
            PostStr[j++] = InStr[i];
        else if(InStr[i] == '(')
            Push(S, InStr[i]);
        //遇到右括号，弹出运算符，直到弹出左括号为止
        else if(InStr[i] == ')') {
            char c;
            Pop(S, c);
            while(c != '(') {
                PostStr[j++] = c;
                Pop(S, c);
            }
        }
        //判断符号的优先级
        else {
            char c;
            while(GetTop(S, c) && c != '(' && isHighPriority(InStr[i], c)) {
                Pop(S, c);
                PostStr[j ++] = c;
            }
            Push(S, InStr[i]);
        }
    }
    //最后如果栈中还有符号，还需要把这些符号弹出并加入到后缀表达式中
    while(!StackEmpty(S)) {
        char c;
        Pop(S, c);
        PostStr[j++] = c;
    }
}

//TODO 由于栈的类型为char，所以在做后缀表达式的运算时，无法把类似于A+B这种操作数入栈
//TODO 所以在此不再编写后缀表达式求值的函数，不过比较简单，看上面的过程即可



int main(){
    char str[100];
    cout << "Input Infix Expression:";
    cin >> str;
    char str1[100] = {'\0'};
    InfixToPostfix(str, str1);
    cout << str1 << endl;
    return 0;
}

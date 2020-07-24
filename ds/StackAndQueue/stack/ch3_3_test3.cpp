//
// Created by yuxingguo on 2020-07-24.
//

//TODO 3.3习题：用栈实现递归函数的非递归计算

//          1       n=0
//Pn(x) =   2x      n=1
//        2xPn-1(x)-2(n-1)Pn-2(x)  n>1

#include <iostream>

#define MaxSize 100

using namespace std;

double CalRevFunc(int n, double x) {
    typedef struct {
        int no;         //n值
        double val;     //n值对应的函数值
    }Stack;
    Stack st[MaxSize];
    int top = -1, i;       //栈顶
    double val1 = 1, val2 = x * 2;
    for(i = n; i >= 2; i--) {
        top ++;
        st[top].no = i;
    }
    while(top >= 0) {
        st[top].val = 2*x*val2 - 2*(st[top].no-1)*val1;
        val1 = val2;
        val2 = st[top].val;
        top --;
    }

    if(n == 0)
        return 0;

    return val2;
}


int main(){
    cout << "CalRevFunc(2,2.0) = " << CalRevFunc(2, 2.0) << endl;
    return 0;
}

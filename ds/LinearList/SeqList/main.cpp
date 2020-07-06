#include <iostream>

#define MaxSize 10

using namespace std;

typedef struct {
    int length;             //顺序表当前长度
    int data[MaxSize];      //顺序表数组
}SeqList;

//初始化这个顺序表
void InitList(SeqList &L){
    L.length=0;
}

//打印顺序表
void PrintList(SeqList L){
    cout << "The length of seqlist is " << L.length << endl;
    for(int i = 0; i < L.length; i ++)
        printf("data[%d] = %d.\n", i, L.data[i]);

}

//向顺序表中位序为i的位置插入元素e（注意，位序比数组下标大1）
bool ListInsert(SeqList &L, int i, int e) {
    //位序必须是合法值
    if(i < 1 || i > L.length + 1)
        return false;
    //由于这里使用的是静态分配，所以当前长度不能超过顺序表规定的最大长度
    if(L.length >= MaxSize)
        return false;
    //后移插入位置以后的元素
    for(int j = L.length; j>= i; j --)
        L.data[j] = L.data[j-1];

    L.data[i-1] = e;
    L.length ++;
    return true;
}

//删除顺序表中位序为i的元素，并通过e带回这个删除的元素
bool ListDelete(SeqList &L, int i, int &e){

    if(i < 1 || i > L.length)
        return false;
    e = L.data[i-1];
    //元素前移
    for(int j = i -1; j < L.length;j ++)
        L.data[j] = L.data[j + 1];

    L.length --;
    return true;
}

//按位查找顺序表
int GetElem(SeqList L, int i){
    return L.data[i - 1];
}

//按值查找元素，返回位序
int LocataElem(SeqList L, int e){
    for(int i = 0; i < L.length; i ++)
        if(L.data[i] == e)
            return i+1;
    return 0;
}


int main(void) {
    SeqList L;
    InitList(L);
    ListInsert(L, 1, 5);
    ListInsert(L, 1, 4);
    ListInsert(L, 1, 2);
    ListInsert(L, 1, 1);

    PrintList(L);

    ListInsert(L, 3, 3);

    PrintList(L);

    int e = -1;
    ListDelete(L, 3, e);
    PrintList(L);

    return 0;
}
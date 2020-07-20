#include <iostream>

#define MaxSize 100

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


//TODO 习题1 删除并返回顺序表中的最小元素
bool DelMinValue(SeqList &L, int &e) {
    if(L.length <= 0) {
        return false;
    }
    int i  = 0;
    e = L.data[0];
    for(int j = 1; j < L.length; j++)
        if(L.data[j] < e) {
            i = j;              //记录下标
            e = L.data[j];      //记录最小值
        }
    L.data[i] = L.data[L.length-1];
    L.length --;
    return true;
}

//TODO 习题2 空间复杂度为O(1)的顺序表逆置
void ReverseList(SeqList &L) {
    int i = 0, j = L.length - 1;
    int temp;
    while(i < j) {
        temp = L.data[i];
        L.data[i] = L.data[j];
        L.data[j] = temp;
        i ++;
        j --;
    }
}

//TODO 习题3 时间复杂度O(n)、空间复杂度O(1)删除顺序表中所有值为x的元素
//思路：用k记录当前有多少个值为x的元素
void DelX(SeqList &L, int e) {
    int k = 0;
    for(int i = 0; i < L.length;i ++) {
        if(L.data[i] == e)
            k ++;
        else
            L.data[i-k] = L.data[i];
    }
    L.length = L.length - k;
}

//TODO 习题4 删除有序顺序表中值为s到t间的元素
bool DelRangeST(SeqList &L, int s, int t) {
    if(L.length == 0 || s >= t)
        return false;
    int k = 0;
    for(int i = 0; i < L.length; i ++) {
        if(L.data[i] < s);
        else if(L.data[i] >= s && L.data[i] <= t)
            k ++;
        else
            L.data[i-k] = L.data[i];
    }

    L.length = L.length - k;
    return true;
}

//TODO 习题6 删除有序顺序表中重复的元素
void DelRepeatValue(SeqList &L) {
    if(L.length == 0)
        return;

    int temp = L.data[0];   //用于记录上一个元素是否与本元素相同
    int k = 0;              //记录相同元素的总个数
    for(int i = 1; i < L.length;i ++) {
        if(L.data[i] == temp)
            k++;
        else {
            temp = L.data[i];
            L.data[i-k] = L.data[i];    //填充重复元素的位置
        }
    }
    L.length -= k;
}

//习题8的逆置函数
void ReverseList(SeqList &L, int m, int n) {
    int temp;
    while(m < n) {
        temp = L.data[m];
        L.data[m] = L.data[n];
        L.data[n] = temp;
        m ++;
        n --;
    }
}

//TODO 习题8 将A[m+n]中的(a1,a2,..,am)与(b1,b2,..,bn)交换位置
//这道题卡住了，想了半天，其实只要先对整体逆置，再分块逆置，就好办了
//时间复杂度O(m+n)
bool ReverseMN(SeqList &L, int m, int n) {
    if(m+n != L.length)
        return false;
    //整体逆置
    ReverseList(L, 0, L.length - 1);
    //分块逆置
    ReverseList(L, 0, n - 1);
    ReverseList(L, n, m + n - 1);
    return true;
}

//TODO 习题9 折半查找递增线性表中为e的元素并与后继元素交换位置，若没有这个元素，则将其有序插入到线性表中
void FindOrInsert(SeqList &L, int e) {
    int temp;
    int low = 0, mid = 0, high = L.length - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(L.data[mid] == e)
            break;
        else if(L.data[mid] > e)
            high = mid-1;
        else
            low = mid+1;
    }
    if(L.data[mid] == e && mid < L.length - 1) {    //如果e恰好为表的最后一个元素，则无需交换
        L.data[mid] = L.data[mid+1];
        L.data[mid+1] = e;
    }
    else if(L.data[mid] != e)
        ListInsert(L, high+2, e);   //如果顺序表中没有e，则high总是与待插入的位序差2
}

//TODO 习题11 以O(logN)的时间复杂度找到两个升序序列的中位数
int MidSearch(SeqList L1, SeqList L2) {
    int s1 = 0, s2 = 0, d1 = L1.length-1, d2 = L2.length-1, m1, m2;
    while(s1 != d1 || s2 != d2) {
        m1 = (s1+d1)/2;
        m2 = (s2+d2)/2;
        if(L1.data[m1] == L2.data[m2]) {
            return L1.data[m1];
        }
        //L1的中位数大于L2，则丢弃L1的右半部分和L2的左半部分
        else if(L1.data[m1] > L2.data[m2]) {
            if((s2+d2)%2 == 0) {    //分奇偶情况考虑数据，如序列长度为3时
                d1 = m1;
                s2 = m2;
            } else {
                d1 = m1;
                d2 = m2+1;
            }
        }
        //L1的中位数小于L2，则丢弃L1的左半部分和L2的右半部分
        else {
            if((s1+d1)%2 == 0) {
                s1 = m1;
                d2 = m2;
            } else {
                s1 = m1+1;
                d2 = m2;
            }
        }

    }
    return L1.data[s1] < L2.data[s2] ? L1.data[s1] : L2.data[s2];
}

//TODO 习题12 尽可能快的( O(N) )寻找序列的主元素
int FindMainEle(SeqList L) {
    int ele = L.data[0], count = 1;
    for(int i = 1; i < L.length; i ++) {
        if(L.data[i] == ele) {
            count ++;
        }
        else {
            count --;
            if(count == 0) {
                ele = L.data[i];
                count = 1;
            }
        }
    }
    if(count >= 1) {
        count = 0;
        for(int i = 0; i < L.length; i ++) {
            if(L.data[i] == ele)
                count ++;
        }
    }
    if(count > L.length /2)
        return ele;
    else
        return -1;
}




int main(void) {
    int data;
    SeqList L;
    InitList(L);
    ListInsert(L, 1, 5);
    ListInsert(L, 1, 4);
    ListInsert(L, 1, 2);
    ListInsert(L, 1, 1);
    ListInsert(L, 3, 3);

    PrintList(L);

    //DelMinValue(L, data);
    //ReverseList(L);
    //DelX(L, 1);
    //DelRangeST(L, 1, 3);
    //DelRepeatValue(L);
    //ReverseMN(L, 3, L.length - 3);
    //FindOrInsert(L, 0);
    //cout << MidSearch(L, L) << endl;
    cout << FindMainEle(L) << endl;

    PrintList(L);

    return 0;
}
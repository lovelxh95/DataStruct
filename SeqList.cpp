#include<iostream>
#include<stdio.h>

using namespace std;


#define MAXSIZE 100

struct SeqList{
    int *data;
    int capacity;
    int length;
};

// 创建顺序表
void InitList(SeqList &L){
    L.data = new int[MAXSIZE];
    L.capacity = MAXSIZE;
    L.length = 0;
}


// 销毁顺序表
void DestroyList(SeqList &L){
    delete[] L.data;
    L.data = nullptr;
    L.capacity = 0;
    L.length = 0;
}


// 直接在末尾插入元素
bool ListInsert(SeqList &L, int e){
    if(L.length >= L.capacity){
        return false; // 顺序表已满
    }
    L.data[L.length] = e;
    L.length++;
    return true;
}

// 在指定位置插入元素
bool ListInsertAt(SeqList &L, int index, int e){
    if(L.length >= L.capacity || index < 0 || index > L.length){
        return false; // 顺序表已满或索引无效
    }
    for(int i = L.length; i > index; i--){
        L.data[i] = L.data[i - 1]; // 元素后移
    }
    L.data[index] = e;
    L.length++;
    return true;
}

// 删除指定位置的元素
bool ListDeleteAt(SeqList &L, int index, int &e){
    if(index < 0 || index >= L.length){
        return false; // 索引无效
    }
    e = L.data[index];
    for(int i = index; i < L.length - 1; i++){
        L.data[i] = L.data[i + 1]; // 元素前移
    }
    L.length--;
    return true;
}

// 获取指定位置的元素
bool GetElem(SeqList L, int index, int &e){
    if(index < 0 || index >= L.length){
        return false; // 索引无效
    }
    e = L.data[index];
    return true;
}

// 获取顺序表长度
int ListLength(SeqList L){
    return L.length;
}

// 根据值查找元素位置
int LocateElem(SeqList L, int e){
    for(int i = 0; i < L.length; i++){
        if(L.data[i] == e){
            return i; // 返回元素位置
        }
    }
    return -1; // 未找到元素
}

int main(){
    SeqList L;
    InitList(L);

    ListInsert(L, 10);
    ListInsert(L, 20);
    ListInsertAt(L, 1, 15);

    int e;
    GetElem(L, 1, e);
    cout << "Element at index 1: " << e << endl;

    int index = LocateElem(L, 20);
    cout << "Index of element 20: " << index << endl;

    ListDeleteAt(L, 1, e);
    cout << "Deleted element: " << e << endl;

    cout << "List length: " << ListLength(L) << endl;

    DestroyList(L);
    return 0;
}
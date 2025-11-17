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
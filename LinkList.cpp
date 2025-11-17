#include<iostream>
#include<stdio.h>
using namespace std;


struct LinkNode{
    int data;
    LinkNode *next;
};

typedef LinkNode* LinkList;

// 创建链表
LinkList InitList(){
    LinkList L = new LinkNode;
    L->next = nullptr;
    return L;
}

// 销毁链表
void DestroyList(LinkList &L){
    LinkNode *p = L;
    while(p){
        LinkNode *temp = p;
        p = p->next;
        delete temp;
    } // 释放所有节点
    L = nullptr;
}

// 头插法插入元素
void ListInsertHead(LinkList &L, int e){
    LinkNode *newNode = new LinkNode;
    newNode->data = e;
    newNode->next = L->next;
    L->next = newNode;
}

// 尾插法插入元素
void ListInsertTail(LinkList &L, int e){
    LinkNode *p = L;
    while(p->next){
        p = p->next;
    }
    LinkNode *newNode = new LinkNode;
    newNode->data = e;
    newNode->next = nullptr;
    p->next = newNode;
}

// 删除指定位置的元素
bool ListDeleteAt(LinkList &L, int index, int &e){
    if(index < 0){
        return false; // 索引无效
    }
    LinkNode *p = L;
    for(int i = 0; i < index; i++){
        if(!p->next){
            return false; // 索引超出范围
        }
        p = p->next;
    }
    LinkNode *toDelete = p->next;
    if(!toDelete){
        return false; // 索引超出范围
    }
    e = toDelete->data;
    p->next = toDelete->next;
    delete toDelete;
    return true;
}

// 查找指定位置的元素
bool ListGetAt(LinkList L, int index, int &e){
    if(index < 0){
        return false; // 索引无效
    }
    LinkNode *p = L->next;
    for(int i = 0; i < index; i++){
        if(!p){
            return false; // 索引超出范围
        }
        p = p->next;
    }
    if(!p){
        return false; // 索引超出范围
    }
    e = p->data;
    return true;
}

// 修改指定位置的元素
bool ListSetAt(LinkList L, int index, int e){
    if(index < 0){
        return false; // 索引无效
    }
    LinkNode *p = L->next;
    for(int i = 0; i < index; i++){
        if(!p){
            return false; // 索引超出范围
        }
        p = p->next;
    }
    if(!p){
        return false; // 索引超出范围
    }
    p->data = e;
    return true;
}

// 获取链表长度
int ListLength(LinkList L){
    int length = 0;
    LinkNode *p = L->next;
    while(p){
        length++;
        p = p->next;
    }
    return length;
}

// 反转链表
void ReverseList(LinkList &L){
    LinkNode *prev = nullptr;
    LinkNode *current = L->next;
    while(current){
        LinkNode *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    L->next = prev;
}

int main(){
    // 示例用法
    LinkList myList = InitList();
    ListInsertTail(myList, 10);
    ListInsertTail(myList, 20);
    ListInsertHead(myList, 5);

    int value;
    ListGetAt(myList, 1, value);
    cout << "Element at index 1: " << value << endl; // 输出20

    ListSetAt(myList, 1, 15);
    ListGetAt(myList, 1, value);
    cout << "Element at index 1 after update: " << value << endl; // 输出15

    cout << "Length of list: " << ListLength(myList) << endl; // 输出3

    ReverseList(myList);
    ListGetAt(myList, 0, value);
    cout << "Element at index 0 after reversal: " << value << endl; // 输出20

    DestroyList(myList);
    return 0;
}
#include<iostream>

using namespace std;


struct CSNode{
    int data;
    CSNode *next;
};
typedef CSNode* CSList;

// 创建循环单向链表
CSList InitCSList(){
    CSList L = new CSNode;
    L->next = L; // 指向自己形成循环
    return L;
}

// 销毁循环单向链表
void DestroyCSList(CSList &L){
    if(!L) return;
    CSNode *p = L->next;
    while(p != L){
        CSNode *temp = p;
        p = p->next;
        delete temp;
    }
    delete L; // 删除头节点
    L = nullptr;
}

// 在循环单向链表末尾插入元素
void CSListInsertTail(CSList &L, int e){
    CSNode *newNode = new CSNode;
    newNode->data = e;
    if(L->next == L){ // 空表
        L->next = newNode;
        newNode->next = L;
    } else {
        CSNode *p = L;
        while(p->next != L){
            p = p->next;
        }
        p->next = newNode;
        newNode->next = L;
    }
}

// 在循环单向链表头部插入元素
void CSListInsertHead(CSList &L, int e){
    CSNode *newNode = new CSNode;
    newNode->data = e;
    if(L->next == L){ // 空表
        L->next = newNode;
        newNode->next = L;
    } else {
        newNode->next = L->next;
        L->next = newNode;
    }
}

// 删除指定位置的元素
bool CSListDeleteAt(CSList &L, int index, int &e){
    if(index < 0){
        return false; // 索引无效
    }
    CSNode *p = L;
    for(int i = 0; i < index; i++){
        if(p->next == L){
            return false; // 索引超出范围
        }
        p = p->next;
    }
    CSNode *toDelete = p->next;
    if(toDelete == L){
        return false; // 不能删除头节点
    }
    e = toDelete->data;
    p->next = toDelete->next;
    delete toDelete;
    return true;
}

// 查找指定位置的元素
bool CSListGetAt(CSList L, int index, int &e){
    if(index < 0){
        return false; // 索引无效
    }
    CSNode *p = L->next;
    for(int i = 0; i < index; i++){
        if(p == L){
            return false; // 索引超出范围
        }
        p = p->next;
    }
    if(p == L){
        return false; // 索引超出范围
    }
    e = p->data;
    return true;
}


int main(){
    // 示例用法
    CSList myCSList = InitCSList();
    CSListInsertTail(myCSList, 10);
    CSListInsertTail(myCSList, 20);
    CSListInsertHead(myCSList, 5);

    int value;
    CSListGetAt(myCSList, 1, value);
    cout << "Element at index 1: " << value << endl; // 输出10

    CSListDeleteAt(myCSList, 1, value);
    cout << "Deleted element: " << value << endl; // 输出10

    CSListGetAt(myCSList, 1, value);
    cout << "Element at index 1 after deletion: " << value << endl; // 输出20

    DestroyCSList(myCSList);
    return 0;
}
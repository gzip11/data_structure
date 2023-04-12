#include <iostream>

#define INITIALSIZE 10

typedef struct ListNode{
    int data;//节点数据域
    ListNode *next;//指向下一个节点的指针
}LNode,*LinkedList;

//创建单链表(头插法)
void CreateListHead(LNode &L);
//创建单链表(尾插法)
void CreateListTail(LNode &L);
//销毁单链表
void DestoryList(LNode &L);
//查找元素
void GetElem(LNode &L);
//定位元素
void LocateElem(LNode &L);
//插入节点
void InsertNode(LNode &L,int i,int e);
//删除节点
void DeleteNode(LNode &L,int i);
//输出链表元素
void PrintList(LNode &L);


int main() {
    LNode L;
    CreateListHead(L);
    //CreateListTail(L);
    return 0;
}

void CreateListHead(LNode &L){
    L = *new LNode;
    L.next = NULL;
}
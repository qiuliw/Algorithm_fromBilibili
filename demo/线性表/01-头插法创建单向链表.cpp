#include <iostream>
using namespace std;

typedef int ElemType ;//数据类型定义

struct Lnode
{
    ElemType data;//结点的数据域
    Lnode* next;//结点的指针域
};

void CreatListHead(Lnode* &L, const size_t n)
{
    // 循环创建n个节点
    for (int i = 0; i < n; ++i)
    {
        // 动态创建一个新的节点
        Lnode* p = new Lnode;
        // 从输入中读取数据并赋值给节点的data成员
        cin >> p->data;
        // 将新节点插入到链表头部
        // 先保存原头部的下一个节点 
        p->next = L->next;
        // 将新节点设置为链表的头部
        L->next = p; 
    }
}

int main(){
    
    return 0;
}
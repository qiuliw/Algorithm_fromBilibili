#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct ListNode {
    E element;   //保存当前元素
    struct ListNode * next;   //指向下一个结点的指针
    struct ListNode * prev;   //指向上一个结点的指针
};

typedef struct ListNode * Node;

//初始化
void initNode(Node node){
    node->next = node->prev = NULL;
}

//插入节点
_Bool insetList(Node head,E element,int index){
    if(index < 1) return 0;
    //寻找前驱节点
    while(--index){
        head=head->next;
        if(head == NULL) return 0;
    }
    Node node =malloc(sizeof(struct ListNode));
    node->element=element;

    if(head->next){
        head->next->prev=node;
        node->next=head->next;
    }else{
        node->next=NULL;
    }

    head->next=node;
    node->prev=head;
}

//正向反向打印
void printList(Node head){
    while(head->next){
        head=head->next;
        printf("%d ",head->element);
    }
    printf("\n");
    do{
        printf("%d ",head->element);
        head=head->prev;
    }while(head->prev);
}

//删除节点
_Bool deleteList(Node head,int index){
    if(index<1)return 0;
    //寻找前驱
    while(--index){
        head=head->next;
        if(head==NULL)return 0;
    }
    if(!head->next) return 0;
    Node temp = head->next;
    if(head->next->next){//删除的不是最后一个节点
        head->next = head->next->next;
        head->next->prev=head;
    }else{//是最后节点
        head->next=NULL;
    }
    free(temp);
    return 1;
}

void main()
{
    struct ListNode head;
    initNode(&head);
    for(int i=0;i<5;i++){
        insetList(&head,i*100,i);
    }
    printList(&head);

}
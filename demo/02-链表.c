#include <stdio.h>
#include <stdlib.h>

typedef int E;//元素类型

//节点
struct ListNode
{
    E element;
    struct ListNode * next;
};

typedef struct ListNode * Node;

//初始化 头节点
void initList(Node head){
    head->next =NULL;
    
}
//添加节点
_Bool insertList(Node head,E element,int index){
    if(index < 1) return 0;

    //寻找插入节点的前驱节点
    while(--index){

        head=head->next;

        if(head == NULL) return 0;//越界
    }

    Node node = malloc(sizeof(struct ListNode));
    node->element=element;
    
    node->next=head->next;
    head->next=node;

    return 1;
}
//删除节点
_Bool DeleteList(Node head,int index){
    if(index < 1) return 0;

    //寻找删除节点的前驱节点
    while(--index){
        head=head->next;
        if(head == NULL) return 0;//越界
    }

    Node temp=head->next;
    head->next=head->next->next;
    free(temp);
    return 1;
    
}

//遍历链表
void printList(Node head){
    while(head->next){
        head=head->next;
        printf("%d ",head->element);
    }
}


Node getList(Node head, int index){
    if(index < 1) return 0;
    while(index--){
        head = head->next;
        if(head == NULL) return 0;
    }
    return head;
}

int findList(Node head,E element){
    head = head->next;
    int i = 1;
    while (head) {
        if(head->element == element) return i;
        head = head->next;
        i++;
    }
    return -1;
}
int sizeList(Node head){
    int i = -1;
    while (head) {
        head = head->next;
        i++;
    }
    return i;
}

void main()
{
    struct ListNode head;
    initList(&head);
    for(int i=1;i<=4;i++)
        insertList(&head,i,i);
    printList(&head);
    printf("\n");
    Node result=getList(&head,2);
    printf("%d",result->element);
}
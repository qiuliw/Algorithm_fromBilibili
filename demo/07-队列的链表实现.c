#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int E;

struct LNode{
    E element;
    struct Lnode*  next;
};

typedef struct Lnode*  Node;

struct Queue{
    Node front,rear;
};

typedef struct Queue * LinkedQueue;

//初始化程序
bool initQueue(LinkedQueue queue){
    Node node = malloc(sizeof (struct LNode));
    if(node == NULL) return false;
    queue->rear=queue->front =node;
    return true;
};

//插入元素
bool offerQueue(LinkedQueue queue,E element){
    Node node =malloc(sizeof(struct LNode));
    if(node == NULL) return false;
    node->element=element;
    queue->rear->next=node;
    queue->rear = node ;
    node->next=NULL;
    return 1;

}

void printQueue(LinkedQueue queue){
    printf("<<< ");
    Node node=queue->front ->next;
    while(node){
        printf("%d ",node -> element);
        node = node ->next;
    }
    printf("<<<\n");
}

//出队
bool isEmpty(LinkedQueue queue){
    return queue->rear==queue->front;
}

E pollQueue(LinkedQueue queue){
    Node tmp=queue->front->next;
    E e = tmp->element;
    queue->front->next=queue->front->next->next;
    if(queue->rear == tmp) queue->rear = queue -> front;
    free(tmp);
    return e;
}

int main(){
    struct Queue queue;
    initQueue(&queue);

    for(int i=0;i<10;i++){
        offerQueue(&queue,i*100);
    }
    printQueue(&queue);
}
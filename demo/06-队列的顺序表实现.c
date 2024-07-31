#include <stdio.h>
#include <stdlib.h>


//队列的顺序表实现,
//这里采用 【先插入再移动指针】，为了区分数组空还是满，当指针重合时为空，指针相邻时为满，不能将数组填满使指针相邻，故总有一个单元浪费
//如果【先移动指针再插入】，则首单元会被浪费
typedef int E;

struct Queue{
    E * array;
    int capacity;
    int rear,front;

};

typedef struct Queue * ArrayQueue; 


_Bool initQueue(ArrayQueue queue){
    queue->array=malloc(sizeof(E)*10);
    if(queue->array==NULL) return 0;
    queue->capacity=10;
    queue->front = queue->rear =0; 
    return 1;
}

_Bool offerQueue(ArrayQueue queue,E element){
    int next=(queue->rear+1)%queue->capacity;//看下一位置是否到达队首
    if(next==queue->front) return 0;
    queue->array[next-1] = element;//插入元素
    queue->rear=next;//移动队尾指针指向下一个空单元
    return 1;
}

//出栈操作
_Bool isEmpty(ArrayQueue queue){   //在出队之前需要先看看容量是否足够
    return queue->rear == queue->front;
}
E pollQueue(ArrayQueue queue){
    int e=queue->array[queue->front];//先出队
    queue->front = (queue->front + 1) % queue->capacity;  //将队首指针后移
    return e;//完事
}

void printQueue(ArrayQueue queue){
    printf("<<< ");
    int i = queue->front;   //遍历队列需要从队首开始，到队尾，不打印队尾；
    while (i!=queue->rear)
    {
        printf(" %d ", queue->array[i]);
        i=(i+1)%queue->capacity;
    }
    printf(" >>>\n");
}


void main()
{
    struct Queue queue;
    initQueue(&queue);
    for(int i=0;i<12;i++){
        offerQueue(&queue, i * 100);
    }
    //出栈
    printQueue(&queue);
        while (!isEmpty(&queue)) {
        printf("%d ", pollQueue(&queue));
    }

}
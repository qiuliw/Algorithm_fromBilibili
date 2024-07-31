#include <stdio.h>
#include <stdlib.h>

//表中元素类型
typedef int E;  

//表
struct List {
E * array;   //指向顺序表的底层数组
int capacity;   //数组的容量
int size;   //表中的元素数量
};


//初始化函数,申请空间
_Bool initList(struct List *list,int capacity){
    list->array = malloc(sizeof(E) * capacity);   //使用malloc函数申请capacity个 E数据类型 大小的内存空间，作为底层数组使用
    if(list->array == NULL) return 0;
    list->capacity = capacity;   //申请成功，修改容量信息
    list->size = 0;   //元素数量默认为0
    return 1;
}

//插入操作
_Bool insertList(struct List *list,E element,int index){
    //list就是待操作的表，element就是需要插入的元素，index就是插入的位置（注意顺序表的index是按位序计算的，从1开始，一般都是第index个元素）
    
    if(index < 1 || index > list->size + 1) return 0;   //如果在非法位置插入，返回0表示插入操作执行失败
    
    for (int i = list->size; i > index - 1; i--)
        list->array[i] = list->array[i - 1];
    list->array[index - 1] = element;
}

//删除操作
_Bool deleteList(struct List *list, int index){
    if(index < 1 || index > list->size) return 0;
    for (int i = index - 1; i < list->size - 1; ++i)
        list->array[i] = list->array[i + 1];
    list->size--;
    return 1;
}
//编写一个函数用于打印表当前的数据
void printList(struct List *list){   
    for (int i = 0; i < list->size; ++i)   //表里面每个元素都拿出来打印一次
        printf("%d ", list->array[i]);
    printf("\n");
}
void main()
{
    struct List list;
    if(initList(&list,10)){
        insertList(&list, 666, 1);  //每次插入操作后都打印一下表，看看当前的情况 
        printList(&list);
        insertList(&list, 777, 1);
        printList(&list);
        insertList(&list, 888, 2);
        printList(&list);
    }else{
        printf("顺序表初始化失败，无法启动程序");
    }
    

}


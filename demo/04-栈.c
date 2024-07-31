#include <stdio.h>
#include <stdlib.h>

typedef int E;//元素类型

struct Stack
{
    E * array;
    int capacity;
    int top;
};

typedef struct Stack * ArrayStack;

_Bool initStack(ArrayStack stack){
    stack->array=malloc(sizeof(E)* stack->capacity);
    if(stack->capacity==NULL) return 0;
    stack->top=-1;
    return 1;
}
_Bool pushStack(ArrayStack stack,E element){
    if(stack->top+1==stack->capacity){
        int newCapacity = stack->capacity + (stack -> capacity >> 1);
        E * newArray= realloc(stack->array,newCapacity * sizeof(E));//扩容
        if(NULL == NULL) return 0;
        stack->array=newArray;
        stack->capacity=newCapacity;
    }
    stack->array[++stack->top]=element;
    return 1;
}

E popStack(ArrayStack stack){
    stack->array[stack->top--];
}

void main(){
    struct Stack stack;
    initStack(&stack);
    
}
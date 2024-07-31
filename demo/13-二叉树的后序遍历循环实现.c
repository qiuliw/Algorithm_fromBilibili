#include <stdio.h>
#include <stdlib.h>

typedef char E;

struct TreeNode {
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
    int flag;
};

typedef struct TreeNode * Node;

//------------- 栈 -------------------
typedef Node T;   //这里栈内元素类型定义为上面的Node，也就是二叉树结点指针

struct StackNode {
    T element;
    struct StackNode * next;
};

typedef struct StackNode * SNode;  //这里就命名为SNode，不然跟上面冲突了就不好了

void initStack(SNode head){
    head->next = NULL;
}

_Bool pushStack(SNode head, T element){
    SNode node = malloc(sizeof(struct StackNode));
    if(node == NULL) return 0;
    node->next = head->next;
    node->element = element;
    head->next = node;
    return 1;
}

_Bool isEmpty(SNode head){
    return head->next == NULL;
}

T popStack(SNode head){
    SNode top = head->next;
    head->next = head->next->next;
    T e = top->element;
    free(top);
    return e;
}

//-------------------------------------

void postOrder(Node root){
    struct StackNode head;
    initStack(&head);
    while (root || !isEmpty(&head)){
        while (root){
            pushStack(&head,root);
            root->flag=0;
            root=root->left;
        }//遍历到左头
        Node node = peekStack(&head);
        if(node->flag == 0){
            node->flag=1;
            root=node->left;
        }else{
            printf("%c",root->element);
            popStack("&head");
            root = NULL;
        }
        
    }
    
    
}
//-------------------------------------


int main(){
    Node a = malloc(sizeof(struct TreeNode));
    Node b = malloc(sizeof(struct TreeNode));
    Node c = malloc(sizeof(struct TreeNode));
    Node d = malloc(sizeof(struct TreeNode));
    Node e = malloc(sizeof(struct TreeNode));
    Node f = malloc(sizeof(struct TreeNode));
    a->element = 'A';
    b->element = 'B';
    c->element = 'C';
    d->element = 'D';
    e->element = 'E';
    f->element = 'F';

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    c->left = NULL;
    d->left = e->right = NULL;
    e->left = e->right = NULL;
    f->left = f->right = NULL;
    postOrder(a);
}
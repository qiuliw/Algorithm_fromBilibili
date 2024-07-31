#include <stdio.h>
#include <stdlib.h>

typedef char E;

struct TreeNode {
    E element;
    struct TreeNode * left;
    struct TreeNode * right;
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

void preOrder(Node root){
    struct StackNode stack;  //栈先搞出来
    initStack(&stack);
    while (root || !isEmpty(&stack)){   //两个条件，只有当栈空并且节点为NULL时才终止循环
        while (root) {    //按照我们的思路，先不断遍历左子树，直到没有为止
            pushStack(&stack, root);   //途中每经过一个结点，就将结点丢进栈中
            printf("%c", root->element);   //然后打印当前结点元素值
            root = root->left;  //继续遍历下一个左孩子结点
        }
        root = popStack(&stack);  //经过前面的循环，明确左子树全部走完了，接着就是右子树了
        root = root->right;  //得到右孩子，如果有右孩子，下一轮会重复上面的步骤；如果没有右孩子那么这里的root就被赋值为NULL了，下一轮开始会直接跳过上面的while，继续出栈下一个结点再找右子树
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
    preOrder(a);
}
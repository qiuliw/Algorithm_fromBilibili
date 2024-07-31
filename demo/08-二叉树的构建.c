#include <stdio.h>
#include <stdlib.h>

typedef char E;

typedef struct TreeNode
{
    E element;
    struct TreeNode * left;
    struct TreeNode * right; 
}*  Node;


// typedef struct  TreeNode ;
void main(){
    Node a = malloc(sizeof(struct TreeNode));  //依次创建好这五个结点
    Node b = malloc(sizeof(struct TreeNode));
    Node c = malloc(sizeof(struct TreeNode));
    Node d = malloc(sizeof(struct TreeNode));
    Node e = malloc(sizeof(struct TreeNode));
  	a->element = 'A';
    b->element = 'B';
    c->element = 'C';
    d->element = 'D';
    e->element = 'E';
    a->left=b;
    b->left=c;
    b->left=d;
    b->right=e;
    c->left=c->right=NULL;
    d->left=d->right=NULL;
    e->left=e->right=NULL;
}
//P30
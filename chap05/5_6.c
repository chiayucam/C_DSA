// binary tree traversal using stacks

#include <stdio.h>
#include <stdlib.h>

struct binaryTreeNode
{
    struct binaryTreeNode *leftchild;
    char data;
    struct binaryTreeNode *rightchild;
};

struct binaryTreeNode *root;

struct stackNode
{
    struct binaryTreeNode *tree_node;
    struct stackNode *next;
};

struct stackNode *top;

void push_node(struct binaryTreeNode *node, struct stackNode **top)
{
    struct stackNode *old_top;
    old_top = *top;
    *top = (struct stackNode *)malloc(sizeof(struct stackNode));
    (*top)->tree_node = node;
    (*top)->next = old_top;
}

struct binaryTreeNode *pop_node(struct stackNode **top)
{
    struct stackNode *old_top;
    struct binaryTreeNode *treeNode;
    if (*top == NULL)
    {
        printf("  stack empty");
    }
    else
    {
        treeNode = (*top)->tree_node;
        old_top = *top;
        *top = (*top)->next;
        free(old_top);
        return treeNode;
    }
}

void inorder_stack()
{
    struct stackNode *top;
    struct binaryTreeNode *node = root;
    top = (struct stackNode *)malloc(sizeof(struct stackNode));
    top->tree_node = node;
    top->next = NULL;
    do
    {
        
        while (node != NULL)
        {
            push_node(node, &top);
            node = node->leftchild;
        }
        if (top != NULL)
        {
            node = pop_node(&top);
            printf("%c", node->data);
            node = node->rightchild;
        }
    } while (top != NULL);
}

void createLeftchild(struct binaryTreeNode *node, char element)
{
    struct binaryTreeNode *left;
    left = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
    node->leftchild = left;
    left->data = element;
    left->leftchild = NULL;
    left->rightchild = NULL;
}

void createRightchild(struct binaryTreeNode *node, char element)
{
    struct binaryTreeNode *right;
    right = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
    node->rightchild = right;
    right->data = element;
    right->leftchild = NULL;
    right->rightchild = NULL;
}

void main()
{
    root = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
    root->data = 'A';
    createLeftchild(root, 'B');
    createLeftchild(root->leftchild, 'D');
    createRightchild(root->leftchild, 'E');
    createLeftchild(root->leftchild->rightchild, 'G');
    createRightchild(root->leftchild->rightchild, 'H');
    createRightchild(root, 'C');
    createLeftchild(root->rightchild, 'F');
    createRightchild(root->rightchild->leftchild, 'I');
    inorder_stack();
}
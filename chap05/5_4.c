// Binary tree postorder traversal
#include <stdio.h>
#include <stdlib.h>

struct binaryTreeNode
{
    struct binaryTreeNode *leftchild;
    char data;
    struct binaryTreeNode *rightchild;
};

struct binaryTreeNode *root;

void postorder(struct binaryTreeNode *node)
{
    if (node != NULL)
    {
        postorder(node->leftchild);
        postorder(node->rightchild);
        printf("%c ", node->data);
    }
}

void createLeftchild(struct binaryTreeNode *node, char element)
{
    struct binaryTreeNode *left;
    left = (struct binaryTreeNode *) malloc(sizeof(struct binaryTreeNode));
    node->leftchild = left;
    left->data = element;
    left->leftchild = NULL;
    left->rightchild = NULL;
}

void createRightchild(struct binaryTreeNode *node, char element)
{
    struct binaryTreeNode *right;
    right = (struct binaryTreeNode *) malloc(sizeof(struct binaryTreeNode));
    node->rightchild = right;
    right->data = element;
    right->leftchild = NULL;
    right->rightchild = NULL;
}

void main()
{
    root = (struct binaryTreeNode *) malloc(sizeof(struct binaryTreeNode));
    root->data = '+';
    createLeftchild(root, '*');
    createLeftchild(root->leftchild, '+');
    createLeftchild(root->leftchild->leftchild, 'A');
    createRightchild(root->leftchild->leftchild, 'B');
    createRightchild(root->leftchild, 'C');
    createRightchild(root, '/');
    createLeftchild(root->rightchild, 'D');
    createRightchild(root->rightchild, '-');
    createLeftchild(root->rightchild->rightchild, 'E');
    createRightchild(root->rightchild->rightchild, 'F');
    postorder(root);
}
// copy binary tree
#include <stdio.h>
#include <stdlib.h>

struct binaryTreeNode
{
    struct binaryTreeNode *leftchild;
    char data;
    struct binaryTreeNode *rightchild;
};

struct binaryTreeNode *root;

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

void inorder(struct binaryTreeNode *node)
{
    if (node != NULL)
    {
        inorder(node->leftchild);
        printf("%c ", node->data);
        inorder(node->rightchild);
    }
}

struct binaryTreeNode *copy(struct binaryTreeNode *root)
{
    struct binaryTreeNode *copyRoot;
    if (root == NULL)
    {
        return NULL;
    }
    copyRoot = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
    copyRoot->data = root->data;
    copyRoot->leftchild = copy(root->leftchild);
    copyRoot->rightchild = copy(root->rightchild);
    return copyRoot;
}

void main()
{
    root = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
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

    struct binaryTreeNode *copyRoot;
    copyRoot = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
    copyRoot = copy(root);

    printf("binary tree root at %p\n", root);
    inorder(root);
    printf("\ncopy binary tree root at %p\n", copyRoot);
    inorder(copyRoot);
}
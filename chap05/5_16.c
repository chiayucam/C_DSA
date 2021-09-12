// iterative search in binary search tree

#include <stdio.h>
#include <stdlib.h>

struct BSTreeNode
{
    struct BSTreeNode *leftchild;
    int data;
    struct BSTreeNode *rightchild;
};

struct BSTreeNode *root;

struct BSTreeNode *searchBST(struct BSTreeNode *node, int x)
{
    while (node!=NULL)
    {
        if (x == node->data)
        {
            return node;
        }
        if (x < node->data)
        {
            node = node->leftchild;
        }
        else
        {
            node = node->rightchild;
        }
    }
    return NULL;
}

void createLeftchild(struct BSTreeNode *node, int element)
{
    struct BSTreeNode *left;
    left = (struct BSTreeNode *) malloc(sizeof(struct BSTreeNode));
    node->leftchild = left;
    left->data = element;
    left->leftchild = NULL;
    left->rightchild = NULL;
}

void createRightchild(struct BSTreeNode *node, int element)
{
    struct BSTreeNode *right;
    right = (struct BSTreeNode *) malloc(sizeof(struct BSTreeNode));
    node->rightchild = right;
    right->data = element;
    right->leftchild = NULL;
    right->rightchild = NULL;
}

void main()
{
    root = (struct BSTreeNode *) malloc(sizeof(struct BSTreeNode));
    root->data = 14;
    createLeftchild(root, 7);
    createLeftchild(root->leftchild, 2);
    createRightchild(root->leftchild, 10);
    createRightchild(root, 16);
    createRightchild(root->rightchild, 20);


    struct BSTreeNode *searchedNode;
    searchedNode = searchBST(root, 20);
    if (searchedNode == NULL)
    {
        printf("No matching item found");
    }
    else
    {
        printf("Found matching search at %p with value %d", searchedNode, searchedNode->data);
    }
}
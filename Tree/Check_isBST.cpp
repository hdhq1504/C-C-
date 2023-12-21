#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
};

int maxValue(struct node *node)
{
    if (node == NULL)
        return INT_MIN;

    int maxVal = node->data;
    int leftMax = maxValue(node->left);
    int rightMax = maxValue(node->right);

    if (leftMax > maxVal)
        maxVal = leftMax;
    
    if(rightMax > maxVal)
        maxVal = rightMax;

    return maxVal;
}

int minValue(struct node *node)
{
    if (node == NULL)
        return INT_MAX;

    int minVal = node->data;
    int leftMin = minValue(node->left);
    int rightMin = minValue(node->right);

    if (leftMin < minVal)
        minVal = leftMin;
    
    if(rightMin < minVal)
        minVal = rightMin;

    return minVal;
}

int isBST(struct node *node)
{
    if (node == NULL)
        return 1;

    if (node->left != NULL && maxValue(node->left) >= node->data)
        return 0;

    if (node->right != NULL && minValue(node->right) >= node->data)
        return 0;

    if (!isBST(node->left) || !isBST(node->right))
        return 0;

    return 1;
}

int main()
{
    struct node* root = newNode(2);
    root->right = newNode(7);
    root->right->right = newNode(6);
    root->right->right->right = newNode(5);
    root->right->right->right->right = newNode(9);
    root->right->right->right->right->right = newNode(2);
    root->right->right->right->right->right->right = newNode(6);

    if(isBST(root))
        printf("Is BST");
    else
        printf("Not a BST");
    
    getchar();
    return 0;
}
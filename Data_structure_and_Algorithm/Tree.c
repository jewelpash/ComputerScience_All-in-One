#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    TreeNode *left, *right;
}TreeNode;
TreeNode n1={1, NULL, NULL};
TreeNode n2={4, &n1, NULL};
TreeNode n3={16, NULL,NULL};
TreeNode n4={25, NULL,NULL};
TreeNode n5={20, &n3, &n4};
TreeNode n6={15, &n2, &n5};
TreeNode *root = &n6;

void inorder(TreeNode *root)
{
    if(root){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void preorder(TreeNode *root)
{
    if(root){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode *root)

{
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

void main()
{
    inorder(root);
    puts("\n");
    preorder(root);
    puts("\n");
    postorder(root);
    puts("\n");
}
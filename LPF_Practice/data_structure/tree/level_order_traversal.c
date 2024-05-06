#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*Level order traverse a tree using queue iteratively*/
/*Definition of tree node*/
typedef struct treenode{
    int val;
    struct treenode* left;
    struct treenode* right;
} TreeNode;

TreeNode* createNode(int data){
    TreeNode* newnode = malloc(sizeof(TreeNode*));
    newnode -> val = data;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}
void traversal_level(TreeNode* root){
    if (!root)
        return;
    TreeNode** queue = malloc(sizeof(TreeNode*)*100);
    int front = 0, rear = 0;
    /*Put the root node into the queue*/
    queue[rear++] = root;
    while (front < rear){
        /*Dequeue a node from queue*/
        TreeNode* current = queue[front++];
        printf("%d ",current -> val);
        if (current -> left)
            queue[rear++] = current -> left;
        if (current -> right)
            queue[rear++] = current -> right;
    }
    
}
int main(void){
    TreeNode *root = createNode (1);
    root->left = createNode (2);
    root->right = createNode (3);
    root->left->left = createNode (4);
    root->left->right = createNode (5);
    root->right->left = createNode (6);
    root->right->right = createNode (7);
    traversal_level(root);
    return 0;
}


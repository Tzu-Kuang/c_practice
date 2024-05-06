# include <stdio.h>
# include <stdlib.h>

typedef struct tree_node{
    int data;
    struct tree_node* left;
    struct tree_node* right;
} TreeNode;

TreeNode* create_node(int val){
    TreeNode* newnode = malloc(sizeof(TreeNode*));
    newnode -> data = val;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

void invertTree(TreeNode* root){
    if (root == NULL ||(root -> left == NULL && root -> right == NULL))
        return;
    TreeNode* temp = malloc(sizeof(TreeNode*));
    temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
    invertTree(root -> left);
    invertTree(root -> right);
}
void printcurrentlevel(TreeNode* root , int level){
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root -> data);
    else if(level > 1){
        printcurrentlevel(root -> left, level - 1);
        printcurrentlevel(root -> right, level - 1);
    }
}
void printlevelorder(TreeNode* root , int height){
    for(int i = 1; i <= height; i++)
        printcurrentlevel(root, i);
}
void traversal_in(TreeNode* root){
    if (root == NULL)
        return;
    traversal_in(root -> left);
    printf("%d ", root -> data);
    traversal_in(root -> right);
}

int main(void){
    TreeNode* root = create_node(40);
    TreeNode* node1 = create_node(30);
    TreeNode* node2 = create_node(50);
    TreeNode* node3 = create_node(25);
    TreeNode* node4 = create_node(35);
    TreeNode* node5 = create_node(45);
    TreeNode* node6 = create_node(60);
    root -> left = node1;
    root -> right = node2;
    node1 -> left = node3;
    node1 -> right = node4;
    node2 -> left = node5;
    node2 -> right = node6;
    traversal_in(root);
    // invertTree(root);
    // printlevelorder(root, 3);
    return 0;
}
# include <stdio.h>
# include <stdlib.h>
/*Tree data structure*/
/*Why we use tree?*/
/*When there are different level in the data, we can use tree
to find the specific data we want.*/
/*Unlike array and linked list, we don't need to find a specific data
by traversing an array or a linked list*/

/*BST(Binary Search Tree)
以左邊節點 ( left node ) 作為根的子樹 ( sub-tree ) 的所有值都小於根節點 ( root )
以右邊節點 ( right node ) 作為根的子樹 ( sub-tree ) 的所有值都大於根節點 ( root )
任意節點 ( node ) 的左、右子樹也分別符合 BST 的定義不存在任何鍵值 ( key/value ) 相等的節點。
*/
/*Think*/
/*任意查看一個節點，其左邊的節點必須小於該節點，其右邊的節點必須大於該節點*/

/*Declaration of the binary tree*/
typedef struct tree_node{
    int data;
    struct tree_node* left;
    struct tree_node* right;
} Tree_Node;

/*Create node*/
Tree_Node* create_node(int val){
    Tree_Node* newnode = malloc(sizeof(Tree_Node));
    newnode -> data = val;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}
/*Traverse a binary tree*/
/*There are three ways to traverse a binary tree: preorder, inorder, postorder*/
/*preorder traversal (Recursively): follow the Root -> Left -> Right principle*/
void traversal_pre(Tree_Node* root){
    if (root == NULL)
        return;
    printf("%d ", root -> data);
    traversal_pre(root -> left);
    traversal_pre(root -> right);
}
/*Inorder traversal (Recursively): follow the left -> root -> right principle*/
void traversal_in(Tree_Node* root){
    if (root == NULL)
        return;
    traversal_in(root -> left);
    printf("%d ", root -> data);
    traversal_in(root -> right);
}
/*postorder traversal (Recursively): follow the left -> right -> root principle*/
void traversal_post(Tree_Node* root){
    if (root ==NULL) return;
    traversal_post(root -> left);
    traversal_post(root -> right);
    printf("%d ", root -> data);
}

int main(void){
    Tree_Node* node1 = create_node(1);//       1
    Tree_Node* node2 = create_node(2);//     2   3
    Tree_Node* node3 = create_node(3);//       4   5
    Tree_Node* node4 = create_node(4);
    Tree_Node* node5 = create_node(5);
    node1 -> left = node2;
    node1 -> right = node3;
    node3 -> left = node4;
    node3 -> right = node5;
    //traversal_pre(node1);
    traversal_post(node1);
    return 0;
};
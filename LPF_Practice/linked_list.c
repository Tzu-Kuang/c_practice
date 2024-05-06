# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
/*In this practice, we use malloc and free function to get memory or release memory from operation system
becasuse we don't know the data size of the input. Then, we will construct the linked list data structure in
this practice*/

struct list_node{
    int data;
    struct list_node *next;
};
typedef struct list_node List_Node;

/*Traverse the linked_list*/
/*Assume we have a defined linked list, and we want to see
the whole data in the linked list, we can do the following:*/

/*int *ptr; 
ptr = head;
while (ptr != NULL){
    printf("%d\n", *ptr);
    ptr -> next;
}*/
/*Also, we can use for loop to traverse the linked list*/
/*for (ptr = head; ptr != NULL; ptr -> next){
    printf("%d\n", *ptr);
}*/
/*Now, we implement a node with a helper function*/
/*Tips: List_Node = listnode*/
List_Node *genListNode(int data, List_Node *next){
    List_Node *node = (List_Node *)malloc(sizeof(List_Node));
    assert(node != NULL);
    node -> data = data;
    node -> next = next;
    return node;
};
/*main function to generate linked list*/
# define arraysize 10
void printLinkedList(List_Node *node);
void freeLinkedList(List_Node *node);
int main(void){
    int array[arraysize];
    for (int i = 0; i < arraysize; i++){
        scanf("%d", &(array[i]));
    };
    List_Node *head;
    List_Node *previous = NULL;
    for (int i = 0; i < arraysize; i++){
        head = genListNode(array[i], previous);
        previous = head;
    };
    printLinkedList(head);
    freeLinkedList(head);
    return 0;
};

void printLinkedList(List_Node *node){
    for (; node != NULL; node = node -> next){
        printf("data = %d\n", node -> data);
        printf("address = %p\n", node -> next);
    };
};

void freeLinkedList(List_Node *node){
    while (node != NULL){
        List_Node *next = node -> next;
        free(node);
        node = next;}
};
/*For example: Given an array = [0,1,2,3,4,5]
The linked list will generate like this:
5 -> 4 -> 3 -> 2 -> 1 -> 0 -> NULL*/
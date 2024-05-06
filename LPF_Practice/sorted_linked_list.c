# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# define arraysize 10

struct list_node{
    int data;
    struct list_node *next;
};
typedef struct list_node List_Node;

List_Node *genListNode(int data, List_Node *next){
    List_Node *node = (List_Node *)malloc(sizeof(List_Node));
    assert(node != NULL);
    node -> data = data;
    node -> next = next;
    return node;
}; 
/*In this case, we use recursion method to print out the data from 
a definded linked list*/
void printLinkedList(List_Node *node){
    if (node == NULL){
        return;
    };
    printf("data = %d\n", node -> data);
    printLinkedList(node -> next);
};
/*insert and sort linked list*/
List_Node *insertListNode(List_Node *head, int data){
    if (head == NULL || data < head -> data){
        return (genListNode(data, head));
    }
    head -> next = insertListNode(head -> next, data);
    return (head);
};
/*delete linked list*/
List_Node *deleteListNode(List_Node *head, int data){
    List_Node *temp;
    if (head == NULL)
        return NULL;
    if (data == head -> data){
        temp = head -> next;
        free(head);
        return (temp);
    };
    head -> next = deleteListNode(head -> next, data);
    return (head);
};
/*release the memoey*/
void freeLinkedList(List_Node *node){
    if (node == NULL)
        return;
    freeLinkedList(node -> next);
    free(node);
};
/*Practical linked list operation*/
# define inskey 5
# define delkey 3
int main(void){
    int insertkeys[inskey];
    int deletekeys[delkey];
    for (int i = 0; i < inskey; i++)
        scanf("%d", &(insertkeys[i]));
    for (int i = 0; i < delkey; i++)
        scanf("%d", &(deletekeys[i]));

    /*insert data into the linked list data structure*/
    List_Node *head = NULL;
    for (int i = 0; i < inskey; i++){
        head = insertListNode(head, insertkeys[i]);
    };
    printLinkedList(head);
    printf("\n");
    /*delete some specific values from the the linked list defined above*/
    for (int i = 0; i < delkey; i++){
        head = deleteListNode(head, deletekeys[i]);
    };
    printLinkedList(head);
    freeLinkedList(head);
    return 0;
};


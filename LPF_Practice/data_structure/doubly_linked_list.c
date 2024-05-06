#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*Doubly linked list*/
typedef struct doubly_linked_list{
    int data;
    /*Get the next memory address in a linked list*/
    struct doubly_linked_list *next;
    /*Get the prev memory address in a linked list*/
    struct doubly_linked_list *prev;
}Doubly_node;

/*Create a new node in a doubly linked list*/
Doubly_node *create_new_node(int val){
    Doubly_node* newnode = malloc(sizeof(Doubly_node));
    newnode -> data = val;
    newnode -> next = NULL;
    newnode -> prev = NULL;
    return newnode;
}
void printList(Doubly_node *head){
    Doubly_node *temp = head;
    while(temp!=NULL){
        printf("%d - ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
/*Think: if we want to insert a new node at head, how it could be done?*/
/*First, we have a haed of a linked list*/
/*NULL -> head -> NULL*/
/*Second, create a new node for a new head*/
/*second_node = create_new_node(val)*/
/*Then, the second node of the doubly linked list will be the old head of the doubly linked list*/
/*Thus, new_node -> next = *head*/
void insert_at_head(Doubly_node **head, Doubly_node *new_node){
    new_node -> next = *head;
    if((*head != NULL)){
        (*head) -> prev = new_node;
    }
    *head = new_node;
}
/*How to remove the head node of a doubly linked list?*/
/*Assuming we have a linked list:*/
/*head*/
/* 1  ->  2  ->  3  ->  4  ->  5*/
/*Since we want to remove the head node of the linked list(1)*/
/*Firstly, let the head node be the second node of the linked list*/
/* *head  = (*head) -> next*/
/*(*head) -> prev = NULL*/
/*Second, if the node we want to remove is not the haed of the linked node:*/
/*Find the node */
void remove_nodes(Doubly_node **head, Doubly_node *node_to_remove){
    if (node_to_remove == NULL){
        return;
    }
    if ((*head) == node_to_remove){
        *head = node_to_remove -> next;
        (*head) -> prev = NULL;
    }
    else{
        node_to_remove -> prev -> next = node_to_remove -> next;
        //check if the node to remove is not the tail of linked list
        if (node_to_remove -> next != NULL){
            node_to_remove -> next -> prev = node_to_remove -> prev;
        }
    }
    node_to_remove -> next = NULL;
    node_to_remove -> prev = NULL;
    free(node_to_remove);
}

Doubly_node* find_node(Doubly_node* head, int val){
    Doubly_node *temp = head;
    while (temp != NULL){
        if (temp -> data == val){
            return temp;
        }
        temp = temp -> next;
    }
    return NULL;
}
int main(void){
    Doubly_node* head = NULL;
    Doubly_node* temp;
    for (int i = 0; i<= 25 ; i++){
        temp = create_new_node(i);
        insert_at_head(&head,temp);
    }
    temp = find_node(head, 16);
    //remove the element in the linked list
    remove_nodes(&head, temp);
    remove_nodes(&head, NULL);

    //try to remove the head
    remove_nodes(&head, head);
    printList(head);
    return 0;
}


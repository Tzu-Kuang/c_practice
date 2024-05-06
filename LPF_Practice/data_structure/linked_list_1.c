#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*Linked-List is the data structure and it's an array that contains nodes in which
save data and the memory address of the node next to it.*/

/*The declarition of the node in the linked list*/
typedef struct list_node{
    int data;
    struct list_node *next;
} List_Node;

/*First we want to know how to link the nodes to the linked list*/
/*Define the print_nodes function*/
void print_nodes(List_Node *head){
    List_Node *temp = head;
    printf("Head -> ");
    for(; temp != NULL; temp = temp -> next){
        printf("%d -> ", temp -> data);
    }
    printf("NULL\n");
}

/*Intsert a newnode after a given node*/
void insert_node(List_Node* prev_node, int val){
    assert(prev_node != NULL);
    List_Node *newnode = malloc(sizeof(List_Node));
    List_Node *temp = malloc(sizeof(List_Node));
    newnode -> data = val;
    temp = prev_node -> next; 
    prev_node -> next = newnode;
    newnode -> next = temp;
}

/*Find a node with a given value*/
List_Node* find_node(List_Node *head, int val){
    List_Node *temp = head;
    while (temp != NULL){
        if (temp -> data == val){
            printf("Find %d at %p\n", temp -> data, &temp -> data);
            return temp;
        };
        temp = temp -> next;
    };
    printf("Not found %d in the given Linked List\n", val);
    return NULL;
}
/*Deleting a node from a linked list with given value*/
void delete_node(List_Node* head, int val){
    List_Node *temp = head;
    while (temp -> next != NULL){
        if (temp -> next -> data == val){
            temp -> next = temp -> next -> next;
            return;
        };
        temp = temp ->next;
    };
}
/*Find the number of nodes in linked list*/
int number_of_node(List_Node* head){
    List_Node *temp = head;
    int count = 0;
    while (temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

/*Using bubble sort method to sort a given linked list*/
void sort_linked_list(List_Node *head){
    List_Node *i, *j;
    for (i = head; i -> next != NULL; i = i -> next){
        for (j = i -> next; j != NULL; j = j -> next){
            if (i -> data > j -> data){
                int temp = i -> data;
                i -> data = j -> data;
                j -> data = temp;
            }
        }
    }
}
int main(void){
    List_Node *node1 = malloc(sizeof(List_Node));
    List_Node *node2 = malloc(sizeof(List_Node));
    List_Node *node3 = malloc(sizeof(List_Node));
    List_Node *head = malloc(sizeof(List_Node));
    int count;
    node1 -> data = 10;
    node2 -> data = 5;
    node3 -> data = 30;
    // //Link them into the chain: head -> 10 -> 20 -> 30 -> NULL
    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = NULL;
    //Print them out
    print_nodes(head);
    //find node with the given value
    find_node(head, 5);
    //insert a newnode after a given value
    insert_node(find_node(head, 5), 15);
    //Print them out
    print_nodes(head);
    //Delete a node from a linked list
    delete_node(head, 5);
    //Print them out
    print_nodes(head);
    //count the number of nodes in the linked list
    count = number_of_node(head);
    printf("The number of nodes in the linked list is %d\n", count);
    //sort the given linked list
    sort_linked_list(head);
    //Print them out
    print_nodes(head);
    return 0;
}
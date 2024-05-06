#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Queue: It's a data structure that follow the the First-In-First-Out rule
//enqueue(int val): It will add an element to the queue
//dequeue(): It will remove an element from a queue that follows the FIFO rule
#define QUEUE_LENGTH 5
#define EMPTY (-1)
#define INI_MIN (-2147483648)
#define QUEUE_EMPTY INI_MIN
/*Array-Like Method*/
// int front = -1;
// int rear = -1;
// int queue[QUEUE_LENGTH];
// bool enqueue(int val){
//     /*check whether the queue can add an element*/
//     if (rear >= QUEUE_LENGTH - 1)
//         return false;
//     rear++;
//     queue[rear] = val;
//     return true;
// };
// int dequeue(){
//     /*check whether the queue is empty*/
//     if (rear == EMPTY)
//         return QUEUE_EMPTY;
//     int result = queue[front + 1];
//     /*shift all the element forward*/
//     for (int i = 1; i <= rear; i++)
//         queue[i-1] = queue[i];
//     rear --;
//     return result;
// };
// int main(void){
//     enqueue(8);
//     enqueue(78);
//     enqueue(7);
//     printf("%s\n","Before dequeue");
//     for (int i = 0; i <= rear; i++)
//         printf("t = %d\n", queue[i]);
//     dequeue();
//     printf("%s\n","After dequeue");
//     for (int i = 0; i <= rear; i++)
//         printf("t = %d\n", queue[i]);
//     return 0;
// }
/*Array-Like Method*/
struct list_node{
    int data;
    struct list_node *next;
};
typedef struct list_node List_Node;
List_Node *front = NULL;
List_Node *rear = NULL;
bool enqueue(int val){
    List_Node *newnode = malloc(sizeof(List_Node));
    newnode -> data = val;
    newnode -> next = NULL;
    /*The First element add into the queue*/
    if (front == NULL && rear == NULL){
    front = newnode;
    rear = newnode;
    }
    /*Add the second and the third node into the queue*/
    else{
        rear -> next = newnode;
        rear = newnode;
    }
    return true;
};
int dequeue(){
    /*check if the queue is empty*/
    if (front == NULL)
        return QUEUE_EMPTY;
    int result = front -> data;
    front = front -> next;
    if (front == NULL)
        rear == NULL;
    return result;
};
int main(void){
    enqueue(8);
    enqueue(78);
    enqueue(7);
    printf("%p\n", front);
    printf("%s\n","Before dequeue");
    for (; front != NULL; front = front->next)
        printf("t = %d\n", front -> data);   
    return 0;
}
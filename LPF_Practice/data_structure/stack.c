#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define STACK_LENGTH 5
#define EMPTY (-1)
#define INI_MIN (-2147483648)
#define STACK_EMPTY INI_MIN
//Stack is a data structure that follows the First In Last Out(FILO)rule, we will
//use array-like and Linked-List-like method to implement the concept of this data structure.
/*Array Like Method*/
int stack[STACK_LENGTH];
int top = EMPTY;
//push():It will add the element to the stack.
// bool push(int value){
//     if(top >= STACK_LENGTH - 1)
//         return false;
//     top++;
//     stack[top] = value;
//     return true;
// }
// //pop():It will remove the element from top of the stack.
// int pop(){
//     if (top == EMPTY)
//         return STACK_EMPTY;
//     int result = stack[top];
//     top--;
//     return result;
// }

// int main(void){
//     push(56);
//     push(78);
//     push(13);
//     int t;
//     while ((t = pop()) != STACK_EMPTY)
//         printf("t = %d\n", t);
//     return 0;
// };
/*Linked List Like Method*/
typedef struct listnode{
    int data;
    struct listnode *next;
} ListNode;

ListNode *head = NULL;
bool push(int val){
    ListNode *newnode = malloc(sizeof(ListNode));
    newnode ->data = val; 
    newnode->next = head;
    head = newnode;
    return true;
};
int pop(){
    if(head == NULL)
        return STACK_EMPTY;
    int result = head -> data;
    head = head -> next;
    return result;
};
int main(){
    push(56);
    push(78);
    push(13);

    int t;
    while((t=pop())!=STACK_EMPTY){
        printf("t = %d\n", t);
    }
    return 0;
};
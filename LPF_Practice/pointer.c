# include <stdio.h>
/*This program will let you know the practice operation 
of c pointer*/
/*First, we create a function called pointerInc and 
try to know the pointer operation in this function*/

/*&: 取址符號*/
/* *var: Pointer*/

void pointerInc(int *p1, int *p2){
    /*Get the memory address of the pointer p1*/
    printf("The address of i pointer is %p\n", &p1);

    /*Get what value stored in the pointer p1
    Tips: we use %p to show the value because the value 
    stored in the is a memory address points out to a int var*/
    printf("The value of i pointer is %p\n", p1);

    /*Get the memory address of the pointer p2*/
    printf("The address of j pointer is %p\n", &p2);

    /*Get what value stored in the pointer p2
    Tips: we use %p to show the value because the value 
    stored in the is a memory address and it points out to a int var*/
    printf("The value of j pointer is %p\n", p2);
    
    /*Basic pointer operation*/
    *p1 += 1; /*Get the value stored in the p1 int pointer and add 1*/
    p1 = p2;  /*Assign the p2 int pointer to p1*/
    *p1 += 2; /*Get the value stored in p2 and add 2*/
}

int main(void){
    int i , j, *ptr = &i;
    printf("Please enter two number:\n");
    scanf("%d %d", &i, &j);
    /*As the code, this three variables will be stored in different memory address*/
    printf("The address of i is %p\n", &i);
    printf("The address of j is %p\n", &j);
    printf("The address of ptr is %p\n", &ptr);
    printf("i = %d, j = %d\n", i, j);
    pointerInc(ptr, &j);
    printf("i = %d, j = %d\n", i, j);
    *ptr += 5;
    printf("i = %d, j = %d\n", i, j);
    return 0;
}

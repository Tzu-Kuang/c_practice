# include <stdio.h>
# include <assert.h>
# define arraysize 100
/*Problem Description*/
/*Bubble Sort O(n^2)*/
/*Given an unsort array, the user will enter a number of array size and an array with the input data size*/
/*First, we compare the first element and the second element if the first eleemnt is bigger or not*/
/*If it is True, exchange the position*/
/*Second, check the next two element of the array as the same rule in First step
until the end of the array*/
int main(void){
    int array[arraysize];
    int number;
    printf("Please enter a data size:");
    scanf("%d", &number);
    assert(number > 0 && number <= arraysize);
    printf("Please enter the unsort array:\n");
    for (int i = 1; i <= number; i++)
        scanf("%d", &array[i]);
    for (int i = number; i > 1; i--)
        for (int j = 1; j < i; j++)
            if(array[j] > array[j + 1]){
                int temp;    
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            };
    for (int i = 1; i <= number ; i++)
        printf("%d\n", array[i]);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Create a Pointer Array*/
/*Step 1 : create an array of 10 char pointers*/
/*Step 2 : prompt the user for string input*/
/*Step 3 : assign each string input to an address stored in the array*/
/*Step 4 : display the 10 string input*/

int main(void){
char *input[10];
char buffer[32];
printf("Please enter 10 strings:\n");
for (int i = 0; i < 10; i++){
    fgets(buffer, 32, stdin);
    input[i] = (char *)malloc(strlen(buffer) + 1);
    strcpy(input[i], buffer);
};
printf("The 10 strings you input are:\n");
for (int j = 0; j < 10; j++){
    printf("%s\n", input[j]);
};
    return 0;
}
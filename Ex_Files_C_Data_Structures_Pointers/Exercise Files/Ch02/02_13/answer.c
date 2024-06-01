#include <stdio.h>
#include <string.h>
#include<stdlib.h>
/*String manipulation challenge*/
/*First, fetch string input from the user*/
/*Process input and a string literal to generate a phase*/
/*Output the phase*/

/*Part 1*/
/*Prompt for the user to type their name*/
/*Write a loop to process single-character input, storing it
in buffer called name[]*/
/*The buffer can hold up to 32 characters*/

/*Part 2*/
/*Copy input stored in the name[] array into the buffer[] array*/
/*Append text from the last[] array onto the buffer array*/
/*The last[] array contains the string literal "passed the challenge"*/

/*Part 3*/
/*Using putchar() to output the characters in buffer[] array*/


int main(void){
    int i, chr;/*the return value of the getchar() is an integer*/
    char name[32];
    char last[] = "passed the challenge!\n";
    char* buffer = (char*)malloc(sizeof(name) + sizeof(last));
    printf("What is your name?:\n");
    for (i = 0; chr != '\n' ; i++){
        name[i] = (char)chr;
    };
    name[i] = '\0';
    buffer = strcpy(buffer, name);
    buffer = strcat(buffer, last);
    
    for (i = 0; buffer[i] != '\0'; i++){
        putchar(buffer[i]);
    }
    return 0;
}
/*
Question:
Write a program to copy its input to its output => getchar(),putchar(),
repiacing each tab by \t、each backspace by \b、each backslach by \\ 
*/

#include <stdio.h>

int main(void){
    int c;

    while((c = getchar())!= EOF){
        if(c == '\t'){
            printf("\\t");
        }
        else if(c == '\b'){
            printf("\\b");
        }
        else if(c == '\\'){
            printf("\\\\");
        }
        else{
            putchar(c);
        }

    }
    return 0;
}
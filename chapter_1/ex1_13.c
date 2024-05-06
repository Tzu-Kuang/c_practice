/*
Wrute a program to print a histogram of the length of words in its input.
It's is easy to draw the histogram with the bars horizontal; a vertical
orientiation is more challenging.
*/

#include <stdio.h>

int main(void)
{
    int c; /*Current input character*/
    int count = 0;
    int i;
    while((c = getchar()) != EOF)
        {
        if(c != ' ' || c!= '\t' || c != '\n')
        {
            count++;
        }
        }
    printf("The histogram of input words is: %d \n", count);
    for(i = 0; i <= count; i++)
        {
        putchar('#');
        }
    return 0;
}
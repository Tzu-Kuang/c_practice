# include <stdio.h>
# include <stdbool.h>
/*Problem Description: The user will enter an AD year, you need to write a program to 
distinguish the year that user entered if it is a leap year or not.
*/
int main(){
    int input_year;
    printf("Please enter an AD year:");
    scanf("%d", &input_year);
    if ((input_year % 400 == 0) || ((input_year % 4 == 0) && (input_year % 100 != 0)))
        printf("The AD year you input (%d) is leap year!", input_year);
    else
        printf("The AD year you input (%d) is not leap year!", input_year);

    return 0;
}
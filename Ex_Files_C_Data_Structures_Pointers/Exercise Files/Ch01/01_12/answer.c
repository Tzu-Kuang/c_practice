#include <stdio.h>
#include <stdlib.h>
/*Construct an array of structures:
1.The array has four elements, each of which is a structure.
2.Display the four structures
3.Swap two elemeents in the array.
4.Display the four structures again.
*/
/*Tips:
1.You need to create two structures
2.struct person: name, a string of 32 characters.
3.structure tookoffice: year, month, day with int data type.
4.Set the data provided into an array of person named presidents.
5.Display all array elements.
6.Swap the second and third elements.
7.Display all the elements again.
*/
/*
[George Washington, April 30, 1789];
[Thomas Jefferson, March 4, 1801];
[Abraham Lincoln, March 4, 1861];
[Theodore Roosevelt,September 14, 1901];
*/
/*Think: Nested structure, array and function challenge*/
typedef struct tookoffice{
    int month;
    int day;
    int year;
} Date;

typedef struct person{
    char name[32];
    Date date;
} President;
void show_result(President p[]){
    puts("Presidents:");
    for (int x = 0; x < 4; x++){
        printf("Presiednt %s took office on %d/%d/%d\n", 
        p[x].name, 
        p[x].date.month, 
        p[x].date.day, 
        p[x].date.year);
    };
    return;
};
void swap(President p[]){
    President temp;
    temp = p[1];
    p[1] = p[2];
    p[2] = temp;
    puts("Swapping......Done!!!\n");
    return;
};

int main(void){
    President  presidents[4] = {
        {"George Washington", 4, 30, 1789},
        {"Thomas Jefferson", 3, 4, 1801},
        {"Abraham Lincoln", 3, 4, 1861},
        {"Theodore Roosevelt",9 , 14, 1901},
    };
    show_result(presidents);
    swap(presidents);
    show_result(presidents);
    return 0;
};

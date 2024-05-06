# include <stdio.h>
# include <stdbool.h>
# include <assert.h>
/*Problem Description*/
/*The user will enter year and month,*/
/*First, we want to check the input year and month is legal or not*/
/*Second, depending the input year and month, output the days for the given information*/
bool leapyear(int year){
    return ((year % 400 == 0) || ((year % 4 == 0)&& !(year % 100 == 0)));
}
int howmanydays(int year, int month){
    int days;
    switch(month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31;
            break;
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
        case 2:
            days = leapyear(year)? 29: 28;
    }
    return days;
}
int main(void){
    int year, month;
    printf("Please Enter the year:");
    scanf("%d", &year);
    printf("Please Enter the month:");
    scanf("%d", &month);
    assert((month > 0 && month <= 12)&&(year > 0));
    printf("The number of days in %d/%d is: %d\n", year, month, howmanydays(year, month));
    return 0;
}
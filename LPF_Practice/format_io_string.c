# include <stdio.h>
# define N 4096
/*This program will show you how to use format string &
sprintf & sscanf to write and read the input string*/

int main(void){
    char filename[N];
    int year[2], month[2], days[2];
    scanf("%d%d%d", &year[0], &month[0], &days[0]);
    sprintf(filename, "file-%4d-%02d-%02d", year[0], month[0], days[0]);
    printf("The filename is %s\n", filename);
    
    /*using sscanf to get the format string written in 'filename' char array and 
    placed them to the defined int array*/
    sscanf(filename, "file-%4d-%02d-%02d", &year[1], &month[1], &days[1]);
    printf("year %d month %d day %d\n", year[1], month[1], days[1]);
    return 0;
}
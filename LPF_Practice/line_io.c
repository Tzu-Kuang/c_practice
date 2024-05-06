# include <stdio.h>
# include <assert.h>
#define stringlength 128
int main(void){
    FILE *fp;
    char string[stringlength];
    fp = fopen("./line_io.c", "r");
    assert(fp != NULL);
    /*The fgets(char *string, int num, FILE *fp) function will return 
    the string read successfully to the string arg, else return NULL*/
    while ((fgets(string, stringlength, fp)) != NULL){
        /*The fputs will return a non-negative int while
        reading a string successfully, else return NULL*/
        /*You can also using puts(string) to display the string in the screen*/
        fputs(string, stdout);
    };
    fclose(fp);
    return 0;
};
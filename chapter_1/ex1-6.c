#include <stdio.h>

int main(){

    int c;
    int f = EOF;
    c = getchar() != EOF;
    printf("%d\n", c);
    printf("%d\n", f);
    return 0;
}
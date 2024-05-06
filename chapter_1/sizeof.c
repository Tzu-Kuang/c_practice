# include <stdio.h>

int main(){
    char i;
    printf("%ld Byte\n", sizeof(i));
    scanf("%d\n", &i);
    printf("%d\n", i);
    i++;
    printf("%d\n", i);
}
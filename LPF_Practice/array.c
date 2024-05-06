# include <stdio.h>
# define arraysize 10

int main(){
    int a[arraysize];
    for (int i = 0; i < arraysize; i++){
        scanf("%d", &(a[i]));  
    }
    for (int i = 0; i < arraysize; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}
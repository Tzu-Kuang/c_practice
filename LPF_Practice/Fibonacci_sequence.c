# include <stdio.h>
# include <assert.h>
#define arraysize 100
/*Problem Description*/
/*When user enter a number that how long will the sequence can be
First we check the input number if it is smaller than the array size
Second we follow the rule of the Fibonacci sequence to print out the first
input number of terms in the sequence*/

int main(){
    int fib[arraysize];
    int n;
    printf("Please Enter a number:\n");
    scanf("%d", &n);
    assert(n > 2 && n < arraysize);
    fib[1] = 0;
    fib[2] = 1;
    for(int i = 3 ; i <= n ; i++){
        fib[i] = fib[i-1] + fib[i-2];
    };
    for(int i = 1 ; i <= n ; i++){
        printf("%d\n", fib[i]);
    };
    return 0;
}
#include <stdio.h>

/*Print Fahrenheit-Celsius table
for fahr = 0, 20, 40, ......, 300
*/
int main(){
    float cel, fahr; 
    int step = 20;
    int lower = 0;
    int upper = 300;
    fahr = lower;
    while(fahr <= upper){
        cel = 5*(fahr - 32) / 9;
        printf("%3.0f %6.2f\n", fahr, cel);
        fahr = fahr + step;
    };

    return 0;
}
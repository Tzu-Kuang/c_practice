/*As the problem description of the Temperature convertion, print out the
Fahrenheit-Celsius table for fahr = a to farh = b with the specific interval 
*/
#include <stdio.h>
float temperature_convertor(float);

int main(void){
    float lower = 0;      /*The lower limit of the convertion table*/
    float step = 20;      /*The interval of the temperature series*/
    float upper = 300;    /*The upper limit of the convertion table*/
    float fahr = lower;
    while(fahr <= upper){
        printf("%7.0f  %10.2f\n", fahr, temperature_convertor(fahr));
        fahr = fahr + step;
    }
    return 0;
}

float temperature_convertor(float fahr){
    return 5.0*(fahr - 32.0)/9.0;
}
# include <stdio.h>
# include "complex.h"
/*Add*/
void addcomplex(const Complex *a, const Complex *b, 
Complex *c){
    c -> real = a -> real + b -> real;
    c -> imag = a -> imag + b -> imag;
    return;
};

/*Multiply*/
void mulcomplex(const Complex *a, const Complex *b, 
Complex *c){
    c -> real = a -> real * b -> real - a -> imag * b -> imag;
    c -> imag = a -> real * b -> imag + a -> imag * b -> real;
    return;
};

void printcomplex(const Complex *a){
    printf("%d + %di\n", a -> real, a -> imag);
    return;
}

/*main function*/
int main(void){
    Complex a, b, c;
    printf("Please enter the real part of a:");
    scanf("%d", &(a.real));
    printf("Please enter the imaginary part of a:");
    scanf("%d", &(a.imag));
    printf("%d + %di\n", a.real, a.imag);
    printf("Please enter the real part of b:");
    scanf("%d", &(b.real));   
    printf("Please enter the imaginary part of b:");
    scanf("%d", &(b.imag));
    printf("%d + %di\n", b.real, b.imag);
    addcomplex(&a, &b, &c);
    printcomplex(&c);
    mulcomplex(&a, &b, &c);
    printcomplex(&c);
    return 0;
};
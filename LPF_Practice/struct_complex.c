# include <stdio.h>
struct complex{
    int real;
    int imag;
};
/*Add*/
struct complex addcomplex(struct complex a, struct complex b){
    struct complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
};

/*Multiply*/
struct complex mulcomplex(struct complex a, struct complex b){
    struct complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
};

void printcomplex(struct complex a){
    printf("%d + %di\n", a.real, a.imag);
    return;
};

/*main function*/
int main(void){
    struct complex a, b, c;
    printf("Please enter the real part of a:");
    scanf("%d", &(a.real));
    printf("Please enter the imaginary part of a:");
    scanf("%d", &(a.imag));
    printf("Please enter the real part of b:");
    scanf("%d", &(b.real));   
    printf("Please enter the imaginary part of b:");
    scanf("%d", &(b.imag));
    c = addcomplex(a, b);
    printcomplex(c);
    c = mulcomplex(a, b);
    printcomplex(c);
    return 0;  
};
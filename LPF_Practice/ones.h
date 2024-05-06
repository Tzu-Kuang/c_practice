/*Define a struct that records the value of number
 and it's number of one bits*/
typedef struct number{
    int value;
    int bit;
}Number;

# define arraysize 1000

/*Define a struct that records the input number array and
the number of input numbers*/
typedef struct numberset{
    Number numbers[arraysize];
    int count;
}Numberset;
# include <stdio.h>
# include "ones.h"

/*The numberbit function will calculate 
how many one bit in the input number*/
int numberbit(int n){
    int bit = 0;
    for (int i = 0; i < sizeof(int) * 8 ; i++){
        if(n & 1 != 0)
            bit++;
        n >>= 1;
    };
    return bit;
};

void readcomputeones(Numberset *numberset){
    numberset -> count = 0;
    /*/////////////////////////////////*/
    Number *ptr = numberset -> numbers;
    while (scanf("%d", &(ptr -> value)) != EOF){
        ptr -> bit = numberbit(ptr -> value);
        ptr++;
        numberset -> count++;
    };
};

void sortnumberset(Numberset *numberset){
    for (int i = numberset -> count - 2; i >= 0; i--){
        for (int j = 0; j <= i ; j++){
            Number *ptr0 = &(numberset -> numbers[j]);
            Number *ptr1 = &(numberset -> numbers[j+1]);
            if (ptr0 -> bit > ptr1 -> bit || (ptr0 -> bit == ptr1 -> bit)
            && (ptr0 -> value > ptr1 -> value)){
                Number temp = *ptr0;
                *ptr0 = *ptr1;
                *ptr1 = temp;
            };
        };
    };
};

void printnumberset(Numberset *numberset){
    for (int i = 0; i < numberset -> count; i++){
        printf("%d\n", numberset -> numbers[i].value);
    };
};

int main(void){
    Numberset numberset;
    readcomputeones(&numberset);
    sortnumberset(&numberset);
    printnumberset(&numberset);
    return 0;
};
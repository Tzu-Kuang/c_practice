#include <stdio.h>
#include <stdlib.h>
//think:如何動態改變陣列大小?

int main() {
    int *numbers;
    int length = 0;
    while(1){
        int input;
        scanf("%d", &input);
        if(input == 0){
            break;
        }
        int larger[length + 1];
        for (int i = 0; i < length; i++){
            larger[i] = numbers[i];
        }
        numbers[length] = input;
        length++;
    }
    printf("Numbers: ");
    for (int i = 0; i < length; i++){
        printf("%d", numbers[i]);
    }
    printf("\n");
    return 0;
}
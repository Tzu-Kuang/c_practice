#include <stdio.h>
#define FALSE 0
#define TRUE 1

typedef struct sexType {
    enum tagfield{Female, Male} sex;
    union {
        int children;
        int beard;
    } u;
} sextype;
typedef struct humanbeing {
    char name[10];
    int age;
    float salary;
    sextype sexInfo;
} human_being;

human_being person1, person2;

int main(void){
    person1.sexInfo.sex = Male;
    person1.sexInfo.u.beard = FALSE;
    person2.sexInfo.sex = Female;
    person2.sexInfo.u.children = 4;
    printf("The sex type of person1 is %d\n", person1.sexInfo.sex);
    printf("The number of child that person2 has is %d\n", person2.sexInfo.u.children);
    return 0;
}
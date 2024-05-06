# include <stdio.h>
# define NAMELEN 20
# define PHONELEN 10
# define YEAR 4
struct student {
    char name [NAMELEN];
    int id;
    char phone [PHONELEN];
    float grade [YEAR];
    int birthyear, birthmonth, birthday;
};

int main(void){
    struct student john = {
        "John Smith", 12345, "0987753586",
        {4.0, 3.8, 3.78, 4.02}, 2000, 1, 1};
    printf("%s\n", john.name);
    printf("%d\n", john.id);
    printf("%s\n", john.phone);
    printf("%f,%f,%f,%f\n", john.grade[0],john.grade[1],john.grade[2],john.grade[3]);
    return 0;
} 
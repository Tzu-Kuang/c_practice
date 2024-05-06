# include <stdio.h>
# include <assert.h>
# define namelen 20
# define phonenum 10
# define Grade 10
struct student {
    char name[namelen];
    int id;
    char phone[phonenum];
    float grade[Grade];
    int year, month, day;
};

typedef struct student Student;

void print_student(Student *s){
    puts(s -> name);
    printf("id = %d\n", s -> id);
    puts(s -> phone);
    printf("grade = %f %f %f %f\n", s -> grade[0], 
    s -> grade[1], s -> grade[2], s -> grade[3]);
    printf("%d %d %d\n", s-> year, s -> month, s -> day);
};

int main(void){
    Student a[3] = {
    {"John Smith", 12345, "0987775462", {3.0,3.0,3.2,3.8}, 2000, 1, 1},
    {"Mary Smith", 14554, "0911456101", {3.7,3.4,3.7,4.0}, 2005, 10, 1},
    {"Smith Smith", 47423, "0954782134", {3.0,3.4,2.7,4.3}, 2004, 4, 7},
    };
    Student b;

    FILE *fp = fopen("./test_file/fseek.bin", "wb");
    assert(fp != NULL);
    fwrite(a, sizeof(Student), 3, fp);
    fclose(fp);
    /*seek*/
    fp = fopen("./test_file/fseek.bin", "rb");
    assert(fp != NULL);
    fseek(fp, 1*sizeof(Student), SEEK_SET);
    fread(&b, sizeof(Student), 1, fp);
    print_student(&b);
    fseek(fp, -2*sizeof(Student), SEEK_CUR);
    fread(&b, sizeof(Student), 1, fp);
    print_student(&b);
    fseek(fp, -1*sizeof(Student), SEEK_END);
    fread(&b, sizeof(Student), 1, fp);
    print_student(&b);
    return 0; 
}
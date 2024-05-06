# include <stdio.h>
# include <assert.h>

int main(void){
    FILE *fp1 = fopen(".test_file/file_1.txt", "w");
    assert(fp1 != NULL);
    for (int i = 0; i < 10; i++){
        /*write "1" to the file_1.txt file*/
        fputc('1', fp1);
    };
    fclose(fp1);

    FILE *fp2 = fopen(".test_file/file_2.txt", "w");
    assert(fp2 != NULL);
    for (int i = 0; i < 20; i++){
        fputc('2', fp2);
    };
    fclose(fp2);

    fp1 = fopen(".test_file/file_1.txt", "r");
    assert(fp1 != NULL);
    fp2 = fopen(".test_file/file_2.txt", "w");
    assert(fp2 != NULL);
    int c;
    while ((c = fgetc(fp1)) != EOF){
        fputc(c, fp2);
    }
    fclose(fp1);
    fclose(fp2);

    fp2 = fopen("./file_2.txt", "r");
    assert(fp2 != NULL);
    while ((c = fgetc(fp2)) != EOF){
        /*stdout will display the result to the screen*/
        /*you can also use putchar(c)*/
        fputc(c, stdout);
    };
    fclose(fp2);
    return 0;
};
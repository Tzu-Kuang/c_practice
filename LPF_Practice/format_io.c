# include <stdio.h>
# include <assert.h>
/*This program shows how to use fprintf and fscanf function*/

int main(void){
    FILE *fp = fopen(".test_file/format_io_1.txt", "w");
    assert(fp != NULL);
    
    /*write number 0-9 to file fp*/
    for(int i = 0; i < 10; i++)
        fprintf(fp, "%d\n", i);
    fclose(fp);

    /*Read the file fp*/
    fp = fopen(".test_file/format_io_1.txt", "r");
    assert(fp != NULL);
    int sum = 0, n; 
    while(fscanf(fp, "%d", &n) != EOF)
        sum += n;
    fclose(fp);

    /*Create file 2 and write data to file 2*/
    FILE *fp2 = fopen(".test_file/format_io_2.txt", "w");
    assert(fp2 != NULL);
    fprintf(fp2, "%d\n", sum);
    fclose(fp2);

    /*Check if the data we wrote successfully saved in file 2*/
    fp2 = fopen(".test_file/format_io_2.txt", "r");
    assert(fp2 != NULL);
    int another_sum;
    fscanf(fp2, "%d", &another_sum);
    fprintf(stdout, "%d\n", another_sum);
    return 0;
}
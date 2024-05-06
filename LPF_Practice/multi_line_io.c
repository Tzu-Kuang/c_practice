# include <stdio.h>
# include <assert.h>
/*Think: Why we use pointer to declare the mode to treat the file?
A: The stnadard c function library define the 'mode' argument as the pointer. 
*/
void dump_file(char *filename, char *mode){
    FILE *fp = fopen(filename, mode);
    assert(fp != NULL);
    int c;
    int count = 0;
    /*the fgetc will get file path as a argument and return the 
    characters read in the file*/
    while((c = fgetc(fp)) != EOF){
        /*利用16進位顯示程式讀取到的字元*/
        printf("%02x ", c);
        count ++;
        if (count % 16 ==0)
            putchar('\n');
    }
    fclose(fp);
    printf("\nThere are %d bytes in file %s \n", count, filename);
};

int main(void){
    #define arraysize 10
    int a[arraysize], b[arraysize];
    for (int i = 0; i < arraysize; i++)
        a[i] = i;
    FILE *fp = fopen("./test_file/multi_a_io.bin", "wb");
    assert(fp != NULL);
    fwrite(a, sizeof(int), arraysize, fp);
    fclose(fp);
    fp = fopen("./test_file/multi_a_io.bin", "rb");
    assert(fp != NULL);
    fread(b, sizeof(int), arraysize, fp);
    fclose(fp);
    for (int i = 0; i < arraysize; i++)
        printf("%d\n", b[i]);
    dump_file("./test_file/multi_a_io.bin", "rb");
    return 0;
};
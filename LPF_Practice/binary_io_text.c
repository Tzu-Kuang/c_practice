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
        if (count %8 ==0)
            putchar('\n');
    }
    fclose(fp);
    printf("\nThere are %d bytes in file %s \n", count, filename);
};

int main(void){
    FILE *fp = fopen("./test_file/binary_io.txt", "wb");
    assert(fp != NULL);
    fputs("hello\n", fp);
    fclose(fp);
    fp = fopen("./test_file/text_io.txt", "wt");
    assert(fp != NULL);
    fputs("hello\n", fp);
    fclose(fp);
    dump_file("./test_file/binary_io.txt", "rb");
    dump_file("./test_file/text_io.txt", "rb");
    dump_file("./test_file/text_io.txt", "rt");
    return 0;
};
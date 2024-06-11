#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
/*This program will prompt the user to input a directory to open
and seek the dircetory if there are file in that or not
Finally, put these file names to "Filenemes.txt" to the same directory*/

/*For open and read the specific directory*/
char path[520];
DIR* file;
struct dirent* names;
char ch;
int i = 0;
/*For write the file names to the Filenames.txt*/
FILE* handle;
const char filename[] = "Filenames.txt";
int main(void){
    /*Step1 : Prompt the user to input a file directory*/
    /*"C:\Users\s1250\Desktop\deep_learning\image_recognition"*/
    printf("Prompt a directory to search files:\n");
    while ((ch = getchar()) != '\n'){
        path[i] = ch;
        i++;
    }
    /*Step 2: search the file in the file directory*/
    file = opendir(path);
    printf("The files in the directory are:\n");
    handle = fopen(filename, "w+");
    while ( (names = readdir(file)) != NULL){
        printf("%s\n", names -> d_name);
        /*Step 3: write these file names to "Filenames.txt"*/
        fprintf(handle,"%s\n", names ->d_name);
    };
    fclose(handle);    
    return 0;
}
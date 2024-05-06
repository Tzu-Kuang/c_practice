# include <stdio.h>
# include <string.h>
# include <assert.h>
# define PATH_LENGTH 200
# define FILE 200
/*Problem Description*/
/*We need to extract the subfolder of the directory and desplay
on the commend window*/
/*First, the user will enter the directory on the commend window*/
/*Then, the program will seperate the dircetory by the slash('/')*/
/*Once we get the subfolder name, saving it to an 2-d array*/
/*Finally, show the result on the commend window*/
int main(void){
    char path_name[PATH_LENGTH];
    char sub_folder[FILE][PATH_LENGTH];
    printf("Plaese enter the directory:\n");
    scanf("%s", path_name);
    char *start = path_name;
    int folder_count = 0;
    if (*start == '\\'){
        start++;
    }
    while(start != NULL){
        /*The strchr(string, 'char') function will return the address of the char you want to find*/
        char *slash = strchr(start, '\\');
        if (slash == NULL){
            /*The srtcpy(des, source) function will copy the source string to des*/
            strcpy(sub_folder[folder_count], start);
            folder_count++;
            start = NULL;
        }
        else {
            /*The strncpy(des, source, number of char) will copy the specific number of chars from source to des*/
            strncpy(sub_folder[folder_count], start, slash - start);
            sub_folder[folder_count][slash - start] = '\0';
            folder_count++;
            start = slash + 1;
        assert(folder_count < FILE);
    }
    }
    for (int i = 1; i <= folder_count; i++){
        printf("%s\n", sub_folder[i]);
    }
    return 0;
} 
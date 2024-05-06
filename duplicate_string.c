#include <stdio.h>
#include <string.h>


// int main() {
//     char source[5] = "test";
//     char *duplicate;
//     duplicate = source;
//     printf("%s\n", duplicate);
//     return 0;
// }

//使用函式
int main() {
    const char source[5] = "test";
    char duplicate[5];
    strcpy(duplicate, source);
    printf("%s\n", duplicate);
    return 0;
}
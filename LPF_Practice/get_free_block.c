/*what is the practical application for linked list?
當我們需要管理一個區塊的記憶體時，可以使用linked list紀錄使用者佔用
了哪些區塊的記憶體，如此便能掌握記憶體的使用情形，才能處理使用者的
要求與歸還。
*/
# include <stdio.h>
# include <assert.h>
/*Define a structure to get the continous free memory 
block from operation system*/
typedef struct freeblock{
    int start;
    int length;
    struct freeblock *next;
} FreeBlock;

FreeBlock *getfreeblock(int start, int length, FreeBlock *next){
    FreeBlock *block = (FreeBlock *)malloc(sizeof(FreeBlock));
    block -> start = start;
    block -> length = length;
    block -> next = next;
    return (block);
};
/*After defining the function to get free blocks of memory,
the following code will initialize a block of free memory*/
/*Think: FreeBlock **head為資料型態為 FreeBlock *的 pointer(head) => memory address*/
void initialMemory(FreeBlock **head, int length){
    assert( length > 0);
    *head = getfreeblock(0, length, NULL);
};
# include <stdio.h>
# include <assert.h>
# define ROW_A 2
# define COL_A 2
# define ROW_B COL_A
# define COL_B 2
# define ROW_C ROW_A
# define COL_C COL_B
/*Problem Description*/
/*Given two matrices, We want to multiply this two matrices O(n^3)*/
/*First,the user will enter two matrices*/
/*Second, we follow the rule of matrices multiplication to get the answer we are expected*/
int main(void){
    int a[ROW_A][COL_A];
    int b[ROW_B][COL_B];
    int c[ROW_C][COL_C];
    /*Enter the element in matrix a*/
    printf("Please enter the elements of matrix a:\n");
    for (int i = 1; i <= ROW_A; i++)
        for (int j = 1; j <= COL_A; j++)
            scanf("%3d", &(a[i][j]));
        printf("\n");
    /*Enter the element in matrix b*/
    printf("Please enter the elements of matrix b:\n");
    for (int i = 1; i <= ROW_B; i++)
        for (int j = 1; j <= COL_B; j++)
            scanf("%3d", &(b[i][j]));
        printf("\n");
    /*Initial the element in matrix c*/
    for (int i = 1; i <= ROW_C; i++)
        for (int j = 1; j <= COL_C; j++)
            c[i][j] = 0;
    /*Do the matrix multiplication to get the answer matrix c*/
    for (int i = 1 ; i <= ROW_C; i++)
        for (int j = 1; j <= COL_C; j++)
            for (int k = 1; k <= COL_A; k++)
                c[i][j] += a[i][k] * b[k][j];
    /*Print out the result c matrix*/
    printf("The result matrix c is:\n");
    for (int i = 1; i <= ROW_C; i++){
        for (int j = 1; j <= COL_C; j++)
            printf("%3d", c[i][j]);
        printf("\n");
    }
    return 0;
}
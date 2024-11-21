// 2차원 행렬 (2D Array practice)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 100
#define COL 100

int main()
{
    int matrix[ROW][COL];
    int row, col;
    scanf("%d %d", &row, &col);
    
    for (int i=0;i<row;i++) {
        for(int j=0;j<col;j++) matrix[i][j] = rand()%1000;
    }
    
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) printf("[%3d] ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}



// 2차원 행렬 덧셈
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 100
#define COL 100

void input2DArray(int array[][100], int row, int col){
    for (int i=0;i<row;i++){
        for(int j=0;j<col;j++) array[i][j] = rand()%1000;
    }
}
void print2DArray(int array[][100], int row, int col){
    printf("===============================\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++) printf("[%4d] ", array[i][j]);
        printf("\n");
    }
}
void addMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col)
{
    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++)  target[i][j] = s1[i][j] + s2[i][j];
    }
}
int main()
{
    int matrix1[ROW][COL];
    int matrix2[ROW][COL];
    int result[ROW][COL];
    
    int row, col;
    srand(time(NULL));
    scanf("%d %d", &row, &col);
    
    
    input2DArray(matrix1,row,col);
    input2DArray(matrix2,row,col);
    addMatrix(matrix1, matrix2, result, row, col);
    
    print2DArray(matrix1,row,col);
    print2DArray(matrix2,row,col);
    print2DArray(result,row,col);
    
    return 0;
}



//

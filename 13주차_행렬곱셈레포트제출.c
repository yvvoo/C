#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 100
#define COL 100
void input2DArray(int array[][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = rand() % 100;
        }
    }
}
void print2DArray(int array[][COL], int row, int col) {
    printf("===============================\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("[%5d] ", array[i][j]);
        }
        printf("\n");
    }
}
void multiMatrix(int matrix1[ROW][COL], int matrix2[ROW][COL], int result[ROW][COL], int row1, int col1, int row2, int col2) {
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
int main() {
    int matrix1[ROW][COL];
    int matrix2[ROW][COL];
    int result[ROW][COL];    
    int row1, col1, row2, col2;
    srand(time(NULL));

    do {
        printf("input matrix 1 row & col: ");
        scanf("%d %d", &row1, &col1);
        printf("input matrix 2 row & col: ");
        scanf("%d %d", &row2, &col2);
        
        if (col1 == row2) {
            input2DArray(matrix1, row1, col1);
            print2DArray(matrix1, row1, col1);
            input2DArray(matrix2, row2, col2);
            print2DArray(matrix2, row2, col2);

            multiMatrix(matrix1, matrix2, result, row1, col1, row2, col2);

            print2DArray(result, row1, col2);
            break;
        } else {
            printf("다시 입력해주세요.\n");
        }
    } while (1);
    
    return 0;
}

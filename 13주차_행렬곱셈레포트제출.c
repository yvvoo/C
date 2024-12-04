#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 100
#define COL 100

// 2차원 배열을 생성하여 각 요소에 랜덤값(0~99)을 생성하는 함수
void input2DArray(int array[][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = rand() % 100;
        }
    }
}

// 2차원 배열을 출력하는 함수
void print2DArray(int array[][COL], int row, int col) {
    printf("===============================\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("[%5d] ", array[i][j]);
        }
        printf("\n");    // 각 행 출력 후 줄바꿈 
    }
}

// 두 행렬을 곱하고 result 행렬에 저장하는 함수. (1번째 행 x 2번째 열)하고 그 값을 result에 더함
void multiMatrix(int matrix1[ROW][COL], int matrix2[ROW][COL], int result[ROW][COL], int row1, int col1, int row2, int col2) {
    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];        // 행렬 곱셈 진행 
            }
        }
    }
}
int main() {
    int matrix1[ROW][COL];            // 1번째 행렬 선언
    int matrix2[ROW][COL];            // 2번째 행렬 선언
    int result[ROW][COL];             // 행렬 곱셈 결과를 저장할 배열 선언
    int row1, col1, row2, col2;       // 변수 선언
    srand(time(NULL));                

    // 행렬의 크기를 올바르게 입력 받을 때까지 반복
    do {
        // 1번째 행,열 입력
        printf("input matrix 1 row & col: ");
        scanf("%d %d", &row1, &col1);
        // 2번째 행,열 입력
        printf("input matrix 2 row & col: ");
        scanf("%d %d", &row2, &col2);

        // (1번째 열 = 2번째 행)이어야 행렬곱셈 가능 그리고 진행
        if (col1 == row2) {
            input2DArray(matrix1, row1, col1);        // 1번째 행렬에 난수로 값 입력
            print2DArray(matrix1, row1, col1);        // 1번째 행렬 출력
            input2DArray(matrix2, row2, col2);        // 2..........
            print2DArray(matrix2, row2, col2);

            multiMatrix(matrix1, matrix2, result, row1, col1, row2, col2);    // 행렬 곱셈 함수 호출

            print2DArray(result, row1, col2);         // 행렬 곱셈 함수 출력
            break;
        } else {
            printf("다시 입력해주세요.\n");
        }
    } while (1);    // 올바른 입력을 받을 때까지 무한반복
    
    return 0;
}

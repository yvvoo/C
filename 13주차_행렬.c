// 2차원 행렬 (2D Array practice)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 100    // 행 100
#define COL 100    // 열 100

int main()
{
    int matrix[ROW][COL];        // 2차원 배열, 100x100 크기의 정수형 행렬 선언
    int row, col;
    scanf("%d %d", &row, &col);  // 사용자로부터 행열 크기를 입력받음
    
    for (int i=0;i<row;i++) {
        for(int j=0;j<col;j++) matrix[i][j] = rand()%1000;   // 0~999
    }
    
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) printf("[%3d] ", matrix[i][j]);
        printf("\n");    // 한 행이 출력된 후 줄바꿈 
    }
    return 0;
}

-------------------------------------------------------------------------------------------

// 2차원 행렬 덧셈
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 100
#define COL 100

// 2차원 배열 array에 랜덤 값을 입력하는 함수
void input2DArray(int array[][100], int row, int col){
    for (int i=0;i<row;i++){
        for(int j=0;j<col;j++) array[i][j] = rand()%1000;    // 0~999
    }
}

// 2차원 배열 array를 출력하는 함수
void print2DArray(int array[][100], int row, int col){
    printf("===============================\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++) printf("[%4d] ", array[i][j]);
        printf("\n");
    }
}

// 두 개의 2차원 배열 s1, s2를 더해서 target 배열에 저장하는 함수
void addMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col)
{
    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++)  target[i][j] = s1[i][j] + s2[i][j];
    }
}
int main()
{
    int matrix1[ROW][COL];    // 1번째 행렬
    int matrix2[ROW][COL];    // 2번째 행렬
    int result[ROW][COL];     // 덧셈 결과를 저장할 행렬
    
    int row, col;            
    srand(time(NULL));                 // 랜덤 함수 초기화
    scanf("%d %d", &row, &col);        // 사용자로부터 행과 열의 크기를 입력받음
    
    input2DArray(matrix1,row,col);     // 1번째, 2번째 행렬을 랜덤값으로 초기화
    input2DArray(matrix2,row,col);
    
    addMatrix(matrix1, matrix2, result, row, col);    // 두 행렬을 더하여 결과를 result 배열에 저장
    
    print2DArray(matrix1,row,col);    // 1번째 행렬 출력
    print2DArray(matrix2,row,col);    // 2번째 행렬 출력
    print2DArray(result,row,col);     // 두 행렬의 덧셈 결과 출력
    
    return 0;
}



//

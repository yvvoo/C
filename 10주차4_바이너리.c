#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct point{
    int x;
    int y;
}POINT;                                  // 정수형 변수 x,y 2D 좌표.


POINT makePoint(void){                    // 사용자로부터 2개의 정수값을 입력받아서 POINT 구조체로 반환하는 함수.
    POINT p;
    scanf("%d %d", &p.x, &p.y);            // 좌표 입력 받은 후 POINT p 구조체에 저장.
    return p;                               // p는 x,y값을 가진 점.
}                                     


void makeRandomPoints(POINT p[], int size){    // 랜덤으로 점 생성 후 배열 p[]에 저장하는 함수. (size는 배열의 크기)
    srand(time(NULL));                     
    for(int i=0;i<size;i++){                   // 좌표 0~99 랜덤값.
        p[i].x = rand() % 100;
        p[i].y = rand() % 100;
    }
}


void printPoints(POINT p[], int size){            // 배열p[]에 저장된 점들을 출력하는 함수.
    for(int i=0;i<size;i++)
        printf("point[%d] = x : %d, y : %d\n", i, p[i].x, p[i].y);
}


void saveFile(POINT p[], int size){                // 배열 p[]에 저장된 점들을 파일에 저장하는 함수. fwrite
    FILE* fp;
    fp = fopen("struct.bin", "wb");
    if(fp == NULL) exit(-1);                       // 파일 열기 실패 -> 프로그램 종료. (struct.bin 파일 필요)
    fwrite(p, sizeof(POINT), size, fp);            // p[]에 있는 POINT 구조체 데이터를 파일에 씀. 
    fclose(fp);
}


void loadFile(POINT p[], int size){                // 파일에서 점들의 데이터를 읽어오는 함수. fread
    FILE* fp;
    fp = fopen("struct.bin", "rb");
    if(fp == NULL) exit(-1);
    fread(p, sizeof(POINT), size, fp);            // 파일에서 점 데이터들을 배열 p[]에 읽어옴.
    fclose(fp);
}


int main()
{
    POINT p[10];
    loadFile(p, 10);                        // 파일에서 10개의 점을 읽어옴.
    makeRandomPoints(p, 10);                // 10개의 랜덤 점 생성.
    printPoints(p, 10);                     // 생성된 점들을 출력.
    saveFile(p, 10);                        // 생성된 점들을 파일에 저장.
    return 0;
}

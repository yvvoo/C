// fseek, ftell 사용.  sizeof(POINT)는 8바이트.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct point{
    int x;
    int y;
}POINT;

POINT makePoint(void){
    POINT p;
    scanf("%d %d", &p.x, &p.y);
    return p;
}

void makeRandomPoints(POINT p[], int size){
    srand(time(NULL));
    for(int i=0;i<size;i++){
        p[i].x = rand() % 100;
        p[i].y = rand() % 100;
    }
}

void printPoints(POINT p[], int size){
    for(int i=0;i<size;i++)
        printf("point[%d] = x : %d, y : %d\n", i, p[i].x, p[i].y);
}

void saveFile(POINT p[], int size){
    FILE* fp;
    fp = fopen("struct.bin", "wb");
    if(fp == NULL) exit(-1);
    fwrite(p, sizeof(POINT), size, fp);
    fclose(fp);
}

void loadFile(POINT p[], int size){
    FILE* fp;
    fp = fopen("struct.bin", "rb");
    if(fp == NULL) exit(-1);
    fread(p, sizeof(POINT), size, fp);
    fclose(fp);
}

int main()
{
    FILE* fp;
    POINT p[10];
    POINT p2;
    int pi;
    loadFile(p, 10);
    printPoints(p, 10);
    
    fp = fopen("struct.bin", "rb");               
    if(fp == NULL) exit(-1);
                                                   
    fseek(fp, sizeof(POINT)*3, SEEK_SET);          // 파일의 시작에서 3칸.
    pi = ftell(fp);                                // 현재 파일 포인터의 위치. 
    printf("pi = %d\n", pi);                       // pi=24 (=8*3)
    fread(&p2, sizeof(POINT), 1, fp);
    printf("p2 -> x : %d, y : %d\n", p2.x, p2.y);
    
    fseek(fp, sizeof(POINT)*-2, SEEK_END);         // 파일의 끝에서 2번째. (시작이랑 끝이랑 세는게 다름)
    printf("pi = %d\n", ftell(fp));                // pi=64
    fread(&p2, sizeof(POINT), 1, fp);
    printf("p2 -> x : %d, y : %d\n", p2.x, p2.y);
    
    fseek(fp, 0, SEEK_END);                        // 파일 전체 크기 
    printf("size = %ld\n", ftell(fp));             // size = 80 (=8*10)
    fclose(fp);
    return 0;
}

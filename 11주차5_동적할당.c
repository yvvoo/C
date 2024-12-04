// 동적할당 실습 #3 - 동적할당 활용하기

#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x;
    int y;
} POINT;

// 사용자로부터 메뉴를 입력받고 해당 값을 반환하는 함수
int inputMenu(void){
    int input;
    printf("1. 만들기, 2. 출력하기, 3. 클리어, 4. 파일저장, 5. 파일로드, -1. 종료 : ");
    scanf("%d", &input);
    return input;
}

// POINT 구조체를 동적 할당, x,y값을 랜덤으로 설정하는 함수
POINT* makePoint(void){
    POINT* p = (POINT*)malloc(sizeof(POINT));
    p->x = rand() % 100;
    p->y = rand() % 100;
    return p;
}

// 동적 할당된 POINT 구조체 배열을 출력하는 함수 
void printPoint(POINT* p[], int size){        // p[]는 POINT* 타입의 배열, size는 구조체 배열의 크기
    for(int i = 0; i<size; i++)
        printf("x:%d, y:%d\n", p[i]->x, p[i]->y);
}

// 동적 할당된 메모리 해제 함수
void freePoints(POINT* p[], int size){
    for(int i = 0; i<size; i++) free(p[i]);
}

// 동적 생성된 POINT 구조체 배열을 파일에 저장하는 함수
int saveFile(POINT* p[], int count){
    FILE* fp;
    fp = fopen("points.bin", "ab");            // 파일을 "ab" 모드로 열어 기존 파일에 덧붙여 저장
    if(fp == NULL) return 0;                   // 파일 열기 실패 시 0 반환
    for(int i=0;i<count;i++)
        fwrite(p[i], sizeof(POINT), 1, fp);    // fwrite함수로 각 POINT 구조체를 파일에 저장
    fclose(fp);
    return 1;        // 저장 성공
}

// 파일에서 POINT 구조체 데이터를 로드하는 함수
int loadFile(POINT* p[], int max){
    FILE* fp;
    int fSize, fCount;
    fp = fopen("points.bin", "rb");        // 파일을 "rb" 모드로 열고, 파일 크기를 구한 후 POINT 구조체의 개수를 계산
    if(fp == NULL) return 0;
    
    fseek(fp, 0, SEEK_END);                // 파일 끝으로 이동
    fSize = ftell(fp);                     // 파일 크기 계산
    fCount = fSize / sizeof(POINT);        // POINT 개수 계산
    rewind(fp);                            // 파일 포인터를 다시 처음으로 이동
    
    for(int i=0; i<fCount; i++){
        if(i == max) break;                       // 최대 저장 가능한 크기를 초과하면 중단
        p[i] = (POINT*)malloc(sizeof(POINT));
        fread(p[i], sizeof(POINT), 1, fp);        // fread로 각 구조체를 읽어 p[] 배열에 동적 할당하여 저장
    }
    fclose(fp);
    return fCount;
}
int main()
{
    int menu;
    int count = 0;                // POINT 개수
    POINT* points[100];           // 최대 100개의 POINT를 저장할 배열
    do{
        menu = inputMenu();
        switch(menu){
            case 1:    // 새로운 POINT 생성
                points[count] = makePoint();
                count++;
                break;
            case 2:    // POINT 출력
                printPoint(points, count);
                break;
            case 3:    // 화면 지우기
                system("clear"); //windows - system("cls")
                break;
            case 4:    // POINT 파일에 저장
                if(!saveFile(points, count)) 
                    printf("file open error...\n");
                else 
                    printf("file writing success...\n");
                break;
            case 5:    // 파일에서 POINT 로드
                count = loadFile(points, 100);
                break;
            case -1:    // 프로그램 종료
                freePoints(points, count);
                printf("프로그램을 종료합니다.\n");
                break;
        }
    } while(menu > 0);    // 메뉴가 양수일 때 계속 실행
    
    return 0;
}

// 동적할당 실습 #3 - 동적할당 활용하기

#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x;
    int y;
} POINT;

// 사용자로부터 메뉴 번호 입력받고 반환하는 함수
int inputMenu(void){              
    int input;
    printf("메뉴입력 (1. 구조체 만들기, 2. 구조체 출력하기, -1. 종료) : ");
    scanf("%d", &input);
    return input;
}

// 동적할당 이용해서 POINT 구조체 생성, x,y 랜덤값으로 초기화 , 생성된 구조체의 포인터 반환하는 함수
POINT* makePoint(void){
    POINT* p = (POINT*)malloc(sizeof(POINT));        // POINT 구조체 크기만큼 메모리 할당 
    p->x = rand() % 100;                    // x값 랜덤 초기화
    p->y = rand() % 100;                    // y값 랜덤 초기화
    return p;                               // 생성된 POINT 구조체의 주소 반환 (POINT*는 동적으로 할당된 구조체의 주소)
}

// POINT 구조체 배열을 받아 x,y값을 출력하는 함수
void printPoint(POINT* p[], int size){
    for(int i = 0; i<size; i++)
        printf("x:%d, y:%d\n", p[i]->x, p[i]->y);
}

// POINT 배열 메모리 해제 함수
void freePoints(POINT* p[], int size){
    for(int i = 0; i<size; i++) free(p[i]);
}

int main()
{
    int menu;
    int count = 0;
    POINT* points[100];    // POINT 포인터 배열 (최대 100개의 POINT 저장 가능)
    do{
        menu = inputMenu();
        if(menu == 1){
            //구조체 만들기 
            points[count] = makePoint();     // 새로운 POINT 생성
            count++;                         // POINT 개수 증가
            printf("잘 만들었습니다. \n");
            
        }else if(menu == 2){
            //구조체 출력하기
            printPoint(points, count);       // 생성된 POINT 모두 출력
    
        }else if(menu == -1){
            freePoints(points, count);       // 모든 POINT 메모리 해제
            printf("프로그램을 종료합니다.\n");    
        }
        
      } while(menu > 0);
    
    return 0;
}

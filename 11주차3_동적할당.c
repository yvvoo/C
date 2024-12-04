// 동적할당 실습 #2 - 구조체 배열 동적 생성하기
#include <stdio.h>
#include <stdlib.h>    // 동적 메모리 할당, 난수 생성, 메모리 해제

typedef struct point{        // POINT는 x,y 정수형 변수를 가지는 구조체
    int x;
    int y;
} POINT;

int main()
{
    POINT* points;            // 동적 메모리로 관리될 POINT 구조체 배열을 위한 포인터 선언
    int count;                // 배열의 크기 저장 변수
    scanf("%d", &count);      // 배열의 크기 입력받기
    
    points = (POINT*)malloc(sizeof(POINT) * count);     // 동적 메모리 할당: POINT 크기 * count만큼 메모리 확보   ---> 배열의 크기를 사용자의 입력에 따라 마음대로
    if (points == NULL) {                               // 할당 메모리 없을 때 프로그램 종료
        printf("Memory allocation failed.\n");            
        return -1;
    }
    
    for(int i=0; i<count; i++){            // 0~99 난수 생성, 각 구조체 저장
        points[i].x = rand()%100;
        points[i].y = rand()%100;
    }
    for(int i=0; i<count; i++){            // 출력
        printf("x - %d, y - %d\n", points[i].x, points[i].y);
    }
    free(points);        // 동적 메모리 해제
    return 0;
}




// 동적할당 실습 #3 - 동적할당 활용하기
#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x;
    int y;
} POINT;

int inputMenu(void){                        // 사용자로부터 메뉴 번호를 입력받아 반환하는 함수
    int input;
    printf("메뉴입력 (1. 구조체 만들기, 2. 구조체 출력하기, -1. 종료) : ");
    scanf("%d", &input);
    return input;
}

int main()
{
    int menu;
    
    do{
        menu = inputMenu();                        // 메뉴 번호 입력받음
        if(menu == 1){
            //구조체 만들기 
        }else if(menu == 2){
            //구조체 출력하기
        }else if(menu == -1){
            printf("프로그램을 종료합니다.\n");
        }
        
        printf("%d\n", menu);        // 메뉴 번호 출력
    } while(menu > 0);               // 메뉴 번호가 양수일 때만
    
    return 0;
}

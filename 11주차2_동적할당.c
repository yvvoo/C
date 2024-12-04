// malloc 활용방법.1

#include <stdio.h>
#include <stdlib.h> // 동적 메모리 할당 및 난수 생성을 위한 헤더

//#define gets(input) fgets(input, sizeof(input), stdin)

int main()
{
    char* pChar;        // char 포인터 (문자열을 위한 메모리)
    int* pInt;          // int 포인터 (정수 배열을 위한 메모리)  
    int count;          // 배열의 크기

    // 배열의 크기 입력받기
    scanf("%d", &count);

    // 동적으로 int 배열 크기만큼 메모리 할당
    pInt = (int*)malloc(count*sizeof(int));

    // 배열에 랜덤 값 넣기 (0~99 사이)
    for(int i = 0; i<count; i++) pInt[i] = rand() % 100;

    // 배열에 저장된 랜덤값 출력
    for(int i = 0; i<count; i++) {
        printf("%d ", pInt[i]);
    }
    printf("\n");
    
    // pInt를 char 포인터로 형변환 (1바이트씩 접근)
    pChar = (char*)pInt;

    // 버퍼에 남아있는 개행문자 처리
    while(getchar() != '\n');        // 읽은 문자가 \n이 아니면 반복이 계속, \n 발견 시 반복문 종료.
    gets(pChar);        // 문자열 입력받기
    puts(pChar);        // 입력받은 문자열 출력하기
    
    free(pInt);         // 동적 메모리 해제
    return 0;
}

// 실습레포트
#include <stdio.h>
#include <time.h>
#include "report.h"

void week2(int year, int month, int day)
{
    time_t current;
    struct tm* timeinfo;
    timeinfo = malloc(sizeof(struct tm));
    
    current = time(NULL);
    
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    
    mktime(timeinfo);
    
    double difference = difftime(mktime(timeinfo), current);
    int days_difference = difference/(60*60*24);
    
    if (days_difference != 0) {
        printf("%d %d %d -> 오늘로부터 %d일 후(-전)입니다.\n", year, month, day, days_difference);
    } else {
        printf("%d %d %d -> 오늘입니다.\n", year, month, day);
    }
  
    free(timeinfo);
}

int main(int argc, char* argv[])
{
    week2(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
}




-----------------------------------------------------------------------------------------------

// 명령라인 실습
// Practice 1. 명령라인 입력방법과 atoi 함수 사용
#include <stdio.h>
#include <stdlib.h>
// argc = 명령라인에서 프로그램으로 전달된 인자의 개수.
// argv = 명령라인에서 전달된 인자들을 문자열 배열로 저장.
int main(int argc, char* argv[])
{
    int a, b;

    // 명령라인 입력으로 전달된 인자들을 정수로 변환
    a = atoi(argv[1]);
    b = atoi(argv[2]);

    // 두 정수의 합을 출력
    printf("a + b = %d", a + b);

    return 0;
}


// 소스코드 관리 실습
#include "파일명"

-------------------------------------------------------------------------------------------------

// 입력한 날짜의 해당 요일을 출력해주는 프로그램
// 실습 후 입력한 날짜가 오늘로부터 며칠 남았는지(전인지) 출력한다.(실습레포트)
#include <stdio.h>
#include <time.h>
#include "report.h"

int main(int argc, char* argv[])
{
    time_t current;                    // 현재 시간을 저장할 변수
    struct tm* timeinfo;               // 시간 정보 구조체 포인터     
        
    int year, month, day;              // 사용자가 입력을 받을 변수
    char* WEEK[] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};        //요일 배열

    // 사용자로부터 날짜 입력 받기
    printf("Enter YYYY MM DD : ");
    scanf("%d %d %d", &year, &month, &day);

    // 현재 시간을 가져와서 timeinfo에 저장
    current = time(NULL);
    timeinfo = localtime(&current);

    // 사용자 입력으로 받은 연,월,일로 timeinfo 수정
    timeinfo->tm_year = year-1900;    // 연도는 1900년을 기준으로 하므로 1900 뺌
    timeinfo->tm_mon = month - 1;     // 월은 0부터 시작하므로 1을 뺌
    timeinfo->tm_mday = day;          // 날짜는 그대로

    // 수정된 날짜를 바탕으로 요일 계산
    mktime(timeinfo);

    // 결과 출력
    printf("%d %d %d -> %s\n", year, month, day, WEEK[timeinfo->tm_wday]);

    return 0;
}

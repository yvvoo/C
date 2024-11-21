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





// 실습코드도 적었습니다.
#include <stdio.h>
#include <time.h>
#include "report.h"

int main(int argc, char* argv[])
{
    time_t current;
    struct tm* timeinfo;
    
    int year, month, day;
    char* WEEK[] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};
    
    printf("Enter YYYY MM DD : ");
    scanf("%d %d %d", &year, &month, &day);
    
    current = time(NULL);
    timeinfo = localtime(&current);
    
    timeinfo->tm_year = year-1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    
    mktime(timeinfo);
    
    printf("%d %d %d -> %s\n", year, month, day, WEEK[timeinfo->tm_wday]);

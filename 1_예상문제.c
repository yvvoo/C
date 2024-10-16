<배열>

문제 1: 5개의 정수로 이루어진 배열을 선언하고, 사용자로부터 입력을 받아 배열에 저장한 후, 배열의 평균을 출력하는 프로그램
#include <stdio.h>

int main() {
    int arr[5], sum = 0;
    float avg;

    printf("5개의 정수를 입력하세요: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    avg = (float)sum / 5;
    printf("배열의 평균은: %.2f\n", avg);

    return 0;
}

문제 2: 10개의 정수를 저장하는 배열을 선언한 뒤, 배열에 들어있는 홀수만 출력하는 프로그램
#include <stdio.h>

int main() {
    int arr[10];

    printf("10개의 정수를 입력하세요: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    printf("홀수만 출력합니다: ");
    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
    return 0;
}

문제 3: 10개의 정수로 구성된 배열을 내림차순으로 정렬하는 프로그램. (선택 정렬 사용)
#include <stdio.h>

int main() {
    int arr[10], temp, i, j, max_idx;

    printf("10개의 정수를 입력하세요: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // 선택 정렬로 내림차순 정렬
    for (i = 0; i < 9; i++) {
        max_idx = i;
        for (j = i + 1; j < 10; j++) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }
        // swap
        temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }

    printf("내림차순으로 정렬된 배열: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

-----------------------------------------------------------------------------------------
<포인터>

문제 1: 두 정수 a와 b의 값을 서로 교환하는 함수를 포인터를 사용해서 작성
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    printf("교환 전: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("교환 후: x = %d, y = %d\n", x, y);

    return 0;
}

문제 2: 포인터를 사용하여 문자열의 길이를 구하는 함수를 작성
#include <stdio.h>

int string_length(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    char str[] = "Hello, World!";
    printf("문자열의 길이는: %d\n", string_length(str));
    return 0;
}

문제 3: 포인터 배열을 사용하여 5개의 숫자를 저장한 후 출력하는 프로그램
#include <stdio.h>

int main() {
    int *ptr[5];
    int nums[5] = {10, 20, 30, 40, 50};
    
    for (int i = 0; i < 5; i++) {
        ptr[i] = &nums[i];
    }

    printf("배열 값들: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr[i]);
    }
    printf("\n");

    return 0;
}

--------------------------------------------------------------------------------------
<문자열>
  
문제 1: 문자열을 입력받아, 그 문자열이 회문(palindrome)인지 확인하는 프로그램
#include <stdio.h>
#include <string.h>

int is_palindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    printf("문자열을 입력하세요: ");
    scanf("%s", str);

    if (is_palindrome(str)) {
        printf("회문입니다.\n");
    } else {
        printf("회문이 아닙니다.\n");
    }

    return 0;
}

문제 2: 두 개의 문자열을 입력받아, 첫 번째 문자열이 두 번째 문자열의 접미사인지 확인하는 프로그램
#include <stdio.h>
#include <string.h>

int is_suffix(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len2 > len1) return 0;  // str2가 str1보다 길면 접미사가 될 수 없음

    return strcmp(&str1[len1 - len2], str2) == 0;
}

int main() {
    char str1[100], str2[100];
    printf("첫 번째 문자열을 입력하세요: ");
    scanf("%s", str1);
    printf("두 번째 문자열을 입력하세요: ");
    scanf("%s", str2);

    if (is_suffix(str1, str2)) {
        printf("두 번째 문자열은 첫 번째 문자열의 접미사입니다.\n");
    } else {
        printf("두 번째 문자열은 첫 번째 문자열의 접미사가 아닙니다.\n");
    }

    return 0;
}

문제 3: 알파벳 모음 자음 개수 세기
#include <stdio.h>

int is_vowel(char c) {
    // 문자를 소문자로 변환한 후 모음인지 확인
    c = (c >= 'A' && c <= 'Z') ? c + 32 : c;  // 대문자를 소문자로 변환
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    char str[100];
    int vowel_count = 0, consonant_count = 0;
    
    printf("문자열을 입력하세요: ");
    scanf("%s", str);
    
    // 문자열의 각 문자를 순차적으로 검사
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {  // 알파벳인지 확인
            if (is_vowel(c)) {
                vowel_count++;
            } else {
                consonant_count++;
            }
        }
    }

    printf("모음: %d개\n", vowel_count);
    printf("자음: %d개\n", consonant_count);

    return 0;
}

문제 4: 두 문자열 이어 붙이기
#include <stdio.h>

void my_strcat(char *dest, char *src) {
    while (*dest) {
        dest++;  // dest가 끝에 도달할 때까지 이동
    }
    while (*src) {
        *dest = *src;  // src의 문자를 dest에 복사
        dest++;
        src++;
    }
    *dest = '\0';  // 이어 붙인 후 문자열의 끝에 NULL 추가
}

int main() {
    char str1[100], str2[100];

    printf("첫 번째 문자열을 입력하세요: ");
    scanf("%s", str1);

    printf("두 번째 문자열을 입력하세요: ");
    scanf("%s", str2);

    my_strcat(str1, str2);  // 두 문자열 합치기

    printf("두 문자열을 이어 붙인 결과: %s\n", str1);

    return 0;
}

문제 5: 포인터로 문자열을 뒤집기
#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
    int length = strlen(str);
    char *start = str;
    char *end = str + length - 1;
    char temp;

    // 문자열 뒤집기
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    char str[100];

    printf("문자열을 입력하세요: ");
    scanf("%s", str);

    reverse_string(str);  // 문자열 뒤집기

    printf("뒤집힌 문자열: %s\n", str);

    return 0;
}

문제 6: 배열과 문자열을 이용한 단어 개수 세기
#include <stdio.h>
#include <string.h>

int count_words(char *str) {
    int count = 0;
    while (*str != '\0') {
        while (*str == ' ') str++;  // 공백 무시
        if (*str != '\0') count++;  // 단어의 시작
        while (*str != ' ' && *str != '\0') str++;  // 단어의 끝
    }
    return count;
}

int main() {
    char str[200];

    printf("문자열을 입력하세요: ");
    gets(str);

    int word_count = count_words(str);  // 단어 개수 세기

    printf("입력한 문자열의 단어 개수는 %d입니다.\n", word_count);

    return 0;
}

----------------------------------------------------------------------
<구조체>

문제 1: 구조체를 이용해 학생 정보를 저장하고, 이름, 나이, 학번을 출력하는 프로그램
#include <stdio.h>

struct Student {
    char name[50];
    int age;
    int id;
};

int main() {
    struct Student student1 = {"홍길동", 20, 20190001};

    printf("학생 이름: %s\n", student1.name);
    printf("학생 나이: %d\n", student1.age);
    printf("학생 학번: %d\n", student1.id);

    return 0;
}

문제 2: 구조체를 이용해 두 점을 좌표로 갖는 직사각형을 정의하고, 직사각형의 넓이와 둘레를 계산하는 프로그램
#include <stdio.h>

typedef struct point {
    int x;
    int y;
} POINT;

typedef struct rectangle {
    POINT lb;  // 왼쪽 아래 좌표 (left bottom)
    POINT rt;  // 오른쪽 위 좌표 (right top)
} RECTANGLE;

int calculate_area(RECTANGLE rect) {
    int width = rect.rt.x - rect.lb.x;
    int height = rect.rt.y - rect.lb.y;
    return width * height;
}

int calculate_perimeter(RECTANGLE rect) {
    int width = rect.rt.x - rect.lb.x;
    int height = rect.rt.y - rect.lb.y;
    return 2 * (width + height);
}

int main() {
    RECTANGLE rect;
    
    // 사용자로부터 직사각형의 좌표를 입력받음
    printf("왼쪽 아래 좌표 (x, y)를 입력하세요: ");
    scanf("%d %d", &rect.lb.x, &rect.lb.y);
    
    printf("오른쪽 위 좌표 (x, y)를 입력하세요: ");
    scanf("%d %d", &rect.rt.x, &rect.rt.y);
    
    // 넓이와 둘레 계산
    int area = calculate_area(rect);
    int perimeter = calculate_perimeter(rect);
    
    printf("직사각형의 넓이: %d\n", area);
    printf("직사각형의 둘레: %d\n", perimeter);
    
    return 0;
}

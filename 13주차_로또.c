//로또실습_들어가기
#include <stdio.h>

typedef struct _lotto {
    int number[6];        // 로또 번호 6개 저장하는 배열    
    int bonus;            // 보너스 번호를 저장하는 변수
    int NO;               // 로또 번호를 나타내는 식별 번호 
}LOTTO;

// LOTTO 구조체를 초기화하는 함수
void initLotto(LOTTO* l){
    for(int i=0;i<6;i++) l->number[i] = 0;    // 로또 번호 배열의 각 원소를 0으로 초기화
    l->bonus = 0;                             // 보너스 번호를 0으로 초기화
    l->NO;                                    // 로또 번호 식별자 설정
}

// 사용자가 수동으로 로또 번호를 입력, 값을 LOTTO 구조체에 저장하여 반환
LOTTO createManual(int NO){
    LOTTO l;
    int num;
    initLotto(&l);    // 구조체 초기화
    l.NO = NO;        // 로또 번호 식별자로 NO 할당
    for(int i=0;i<6;i++){
        printf("input number #%d : ", i+1);
        scanf("%d", &num);    // 번호 입력 받기
        l.number[i] = num;    // 입력 받은 번호를 배열에 저장
    }
    return l;        // 초기화된 구조체 반환
}

// 로또 번호와 보너스 번호 출력 함수
void printLotto(LOTTO l){
    printf("#%d lotto number : %2d, %2d, %2d, %2d, %2d, %2d\n", l.NO,
        l.number[0], l.number[1], l.number[2], l.number[3], l.number[4], l.number[5]);
    printf("BONUS : %d\n", l.bonus);
}

int main()
{
    LOTTO l;
    
    l = createManual(20241034);    // 로또 번호와 보너스 번호 입력
    printLotto(l);                 // 출력
    
    return 0;
}

-------------------------------------------------------------------

//로또실습_중복제거
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _lotto {
    int number[6];
    int bonus;
    int NO;
}LOTTO;

// LOTTO 구조체를 초기화하는 함수
void initLotto(LOTTO* l){
    for(int i=0;i<6;i++) l->number[i] = 0;
    l->bonus = 0;
    l->NO;
}

// 중복 확인 함수
int dup(LOTTO l, int num, int n){
    for(int i=0;i<=n;i++){
        if(l.number[i] == num) return 1;    // 중복된 번호가 있으면 1 반환
    }
    return 0;        // 중복 없으면 0 반환
}

// 로또 번호 자동 생성
LOTTO createAuto(int NO){
     LOTTO l;
    int num;
    initLotto(&l);
    l.NO = NO;            // 로또 번호 식별자로 NO 할당
    for(int i=0;i<6;i++){
        num = rand() % 45 + 1;                                   // 1~45 랜덤 번호 생성
        if (i==0) l.number[i] = num;                             // 첫 번째 번호는 무조건 저장
        else if(i>0 && !dup(l, num, i-1) ) l.number[i] = num;    // 중복이 없으면 저장
        else{
            i--;            // 중복 발생 시 다시 뽑기 위해 i 감소
            printf("중복발생.. 다시 뽑으세요..\n");
        }
    }
    return l;
}

// 사용자가 수동 번호 입력, 중복 방지를 위한 dup 함수 사용됨
LOTTO createManual(int NO){
    LOTTO l;
    int num;
    initLotto(&l);
    l.NO = NO;
    for(int i=0;i<6;i++){
        printf("input number #%d : ", i+1);
        scanf("%d", &num);
        if (i==0) l.number[i] = num;                                 // 첫 번째 번호는 바로 저장
        else if(i>0 && !dup(l, num, i-1) ) l.number[i] = num;        // 중복 없으면 저장
        else{
            i--;                // 중복 발생 시 다시 뽑기 위해 i 감소
            printf("중복발생.. 다시 뽑으세요..\n");
        }
    }
    return l;
}

// 로또 번호와 보너스 번호 출력 함수
void printLotto(LOTTO l){
    printf("#%d lotto number : %2d, %2d, %2d, %2d, %2d, %2d\n", l.NO,
        l.number[0], l.number[1], l.number[2], l.number[3], l.number[4], l.number[5]);
    printf("BONUS : %d\n", l.bonus);
}
int main()
{
    LOTTO l;
    srand(time(NULL));
    l = createAuto(20241034);        // 로또 번호와 보너스 번호 입력
    printLotto(l);                   // 출력
    
    
    return 0;
}

-------------------------------------------------------------------

//로또실습_추첨하기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _lotto {
    int number[6];
    int bonus;
    int NO;
}LOTTO;

void initLotto(LOTTO* l){
    for(int i=0;i<6;i++) l->number[i] = 0;
    l->bonus = 0;
    l->NO;
}

// 중복된 번호가 있는지 확인하는 함수
int dup(LOTTO l, int num, int n){
    for(int i=0;i<=n;i++){
        if(l.number[i] == num) return 1;    // 중복된 번호가 있으면 1 반환
    }
    return 0;            // 중복 없으면 0 반환
}

// 로또 번호를 자동으로 생성하는 함수
LOTTO createAuto(int NO){
     LOTTO l;
    int num;
    initLotto(&l);        // 로또 초기화
    l.NO = NO;            // 로또 번호 식별자로 NO 할당 
    for(int i=0;i<6;i++){
        num = rand() % 45 + 1;        // 1~45
        if (i==0) l.number[i] = num;
        else if(i>0 && !dup(l, num, i-1) ) l.number[i] = num;        // 중복 없으면 저장
        else{
            i--;        // 중복 발생 시 다시 뽑기 위해 i 감소
            printf("중복발생.. 다시 뽑으세요..\n");
        }
    }
    return l;
}

// 사용자가 수동으로 번호를 입력하는 함수
LOTTO createManual(int NO){
    LOTTO l;
    int num;
    initLotto(&l);
    l.NO = NO;
    for(int i=0;i<6;i++){
        printf("input number #%d : ", i+1);
        scanf("%d", &num);
        if (i==0) l.number[i] = num;                                // 첫 번째 번호는 바로 저장
        else if(i>0 && !dup(l, num, i-1) ) l.number[i] = num;       // 중복 없으면 저장
        else{
            i--;        // 중복 발생 시 다시 뽑기 위해 i 감소
            printf("중복발생.. 다시 뽑으세요..\n");
        }
    }
    return l;
}

// 로또 번호와 보너스를 출력하는 함수
void printLotto(LOTTO l){
    printf("#%d lotto number : %2d, %2d, %2d, %2d, %2d, %2d\n", l.NO,
        l.number[0], l.number[1], l.number[2], l.number[3], l.number[4], l.number[5]);
    printf("BONUS : %d\n", l.bonus);
}

// 로또 추첨을 시뮬레이션하는 함수
LOTTO drawingLotto(){
    LOTTO l;
    int num;
    initLotto(&l);        
    for(int i=0;i<6;i++){
        num = rand() % 45 + 1;
        if (i==0) l.number[i] = num;
        else if(i>0 && !dup(l, num, i-1) ) l.number[i] = num;
        else{
            i--;
        }
    }
    do{
        l.bonus = rand() % 45 + 1;        // 보너스 번호 생성
        
    }while(dup(l, l.bonus, 5));           // 중복되면 다시 뽑기 
    return l;
}

// 일치하는 번호의 개수를 반환하는 함수
int matchCount(LOTTO l1, LOTTO l2){
    int mcount = 0;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(l1.number[i] == l2.number[j]) mcount++;    // 번호가 일치하면 카운트 증가
        }
    }
    return mcount;        // 일치하는 번호 개수 반환
}

int main()
{
    LOTTO l, l2;
    int count;
    srand(time(NULL));
    l = createAuto(20241034);        // 자동 생성 로또 번호 생성
    l2 = drawingLotto();             // 로또 추첨 번호 생성
    printLotto(l);                   // 자동 생성된 로또 번호 출력
    printLotto(l2);                  // 추첨된 로또 번호 출력
    count = matchCount(l,l2);        // 일치하는 번호 개수 계산
    printf("match : %d\n", count);   // 일치하는 번호 개수 출력
    return 0;
}

#include <stdio.h>
#include <stdlib.h>


#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 100             // 상품명 최대 길이

// 전역 변수
int received[MAX_PRODUCTS] = { 0 };     // 입고 수량
int sold[MAX_PRODUCTS] = { 0 };         // 판매 수량
int stock[MAX_PRODUCTS] = { 0 };        // 재고 수량
int num_products = 5;                   // 상품 종류 수 (임의로 5종류)
char productname[MAX_PRODUCTS][MAX_NAME_LENGTH]; //상품명 배열

// 함수 선언
void in_received();                     // 입고 함수
void in_sold();                         // 판매 함수
void show_products();                   // 상품현황 출력 함수
void product_name();                    //상품명 입력 함수
void exit_program();                    // 종료 함수

int main() {
    int choice;
    void (*menu_functions[5])() = { in_received, in_sold, show_products, product_name, exit_program }; // 함수 포인터 배열

    while (1) {
        // 메뉴 출력
        printf("\n> 원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 상품명 입력, 5. 종료)\n");
        scanf_s("%d", &choice);

        if (choice >= 1 && choice <= 5) {
            menu_functions[choice - 1]();  // 선택한 메뉴에 해당하는 함수 호출
        }
        else {
            printf("잘못된 선택입니다. 다시 선택하세요.\n");
        }
    }

    return 0;
}

// 1. 입고 함수
void in_received() {
    int option;
    printf("입고수량 입력: 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n");
    scanf_s("%d", &option);

    if (option == 1) {
        printf("전체 상품의 입고수량을 입력하세요: ");
        for (int i = 0; i < num_products; i++) {
            scanf_s("%d", &received[i]);
            stock[i] += received[i];  // 입고된 수량을 재고에 추가
        }
    }
    else if (option == 2) {
        int id, quantity;
        printf("상품ID를 입력하세요: ");
        scanf_s("%d", &id);
        if (id >= 1 && id <= num_products) {
            printf("입고수량을 입력하세요: ");
            scanf_s("%d", &quantity);
            received[id - 1] += quantity;
            stock[id - 1] += quantity;
        }
        else {
            printf("잘못된 상품ID입니다.\n");
        }
    }
    else {
        printf("잘못된 선택입니다.\n");
    }
}

// 2. 판매 함수
void in_sold() {
    int option;
    printf("판매수량 입력: 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택\n");
    scanf_s("%d", &option);

    if (option == 1) {
        printf("전체 상품의 판매수량을 입력하세요: ");
        for (int i = 0; i < num_products; i++) {
            scanf_s("%d", &sold[i]);
            if (sold[i] <= stock[i]) {
                stock[i] -= sold[i];  // 재고에서 판매량만큼 차감
            }
            else {
                printf("상품 %d의 재고가 부족합니다. (재고: %d)\n", i + 1, stock[i]);
            }
        }
    }
    else if (option == 2) {
        int id, quantity;
        printf("상품ID를 입력하세요: ");
        scanf_s("%d", &id);
        if (id >= 1 && id <= num_products) {
            printf("판매수량을 입력하세요: ");
            scanf_s("%d", &quantity);
            if (quantity <= stock[id - 1]) {
                sold[id - 1] += quantity;
                stock[id - 1] -= quantity;
            }
            else {
                printf("상품 %d의 재고가 부족합니다. (재고: %d)\n", id, stock[id - 1]);
            }
        }
        else {
            printf("잘못된 상품ID입니다.\n");
        }
    }
    else {
        printf("잘못된 선택입니다.\n");
    }
}

// 3. 상품현황 출력 함수
void show_products() {
    float total_sold = 0, total_received = 0;
    int max_sold = sold[0], min_sold = sold[0];
    int max_id = 1, min_id = 1;
    float sold_percent;

    // 재고수량, 총 판매량, 최대/최소 판매량 계산
    printf("재고수량: ");
    for (int i = 0; i < num_products; i++) {
        printf("%d ", stock[i]);
        total_sold += sold[i];
        total_received += received[i];

        // 최대 판매량 계산
        if (sold[i] > max_sold) {
            max_sold = sold[i];
            max_id = i + 1;
        }
        // 최소 판매량 계산
        if (sold[i] < min_sold) {
            min_sold = sold[i];
            min_id = i + 1;
        }
    }

    // 판매율 계산 및 출력
    if (total_received > 0) {
        sold_percent = (total_sold / total_received) * 100;
        printf("\n총 판매량: %d (판매율 %.2f%%)\n", (int)total_sold, sold_percent);
    }
    else {
        printf("\n총 판매량 : %d (판매율 계산 불가, 판매된 상품 없음)\n", (int)total_sold);
    }

    // 최대 및 최소 판매량 상품 출력
    printf("가장 많이 판매된 상품: ID %d, 상품명: %s, 판매량 %d\n", max_id, productname[max_id-1], max_sold);
    printf("가장 적게 판매된 상품: ID %d, 상품명: %s, 판매량 %d\n", min_id, productname[min_id-1], min_sold);

    // 재고 부족 경고 출력
    for (int i = 0; i < num_products; i++) {
        if (stock[i] <= 2) {
            printf("상품 ID %d : 상품명: %s 재고부족(%d)\n", i + 1, productname[i], stock[i]);
        }
    }
}

// 4. 상품명 입력 함수
void product_name() {
    printf("상품명을 입력하세요. \n");
    for (int i = 0; i < num_products; i++) {
        printf("상품 %d의 이름: ", i + 1);
        scanf_s("%s", productname[i], MAX_NAME_LENGTH);
    }
    printf("\n입력된 상품명:\n");
    for (int i = 0; i < num_products; i++) {
        printf("상품 %d: %s\n", i + 1, productname[i]);
    }

}

// 5. 종료 함수
void exit_program() {
    printf("프로그램을 종료합니다.\n");
    exit(0);
}

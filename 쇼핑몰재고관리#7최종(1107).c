#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 5
#define MAX_NAME_LENGTH 100
#define DATA_FILE "products.dat" 

typedef struct {
    int id;                     // 상품 ID
    char name[MAX_NAME_LENGTH]; // 상품명
    float price;                // 판매 가격
    int received;               // 입고량
    int sold;                   // 판매량
    float total_sales;          // 총 판매 금액
} Product;

Product products[MAX_PRODUCTS] = { 0 }; // 상품 정보 배열
int num_products = 0;                   // 등록된 상품 수

void in_received();             // 입고 함수
void in_sold();                 // 판매 함수
void show_product();            // 개별 상품 정보 출력
void show_all_products();       // 전체 상품 정보 출력
void exit_program();            // 프로그램 종료
void load_products();           // 불러오기
void save_products();           // 저장하기

int main() {
    int choice;
    void (*menu_functions[6])() = { in_received, in_sold, show_product, show_all_products, save_products, load_products };

    while (1) {
        printf("\n> 원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 저장, 6. 불러오기, 7. 종료)\n");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 7) {
            if (choice == 7) {
                exit_program(); 
            } else {
                menu_functions[choice - 1](); 
            }
        } else {
            printf("잘못된 선택입니다. 다시 입력하세요.\n");
        }
    }

    return 0;
}

void load_products() {
    FILE *file = fopen(DATA_FILE, "rb");
    if (!file) {
        printf("상품 정보를 불러올 수 없습니다. 파일이 존재하지 않거나 열 수 없습니다.\n");
        return;
    }

    num_products = fread(products, sizeof(Product), MAX_PRODUCTS, file);
    fclose(file);
    printf("상품 정보를 성공적으로 불러왔습니다. (총 %d개 상품)\n", num_products);
}

void save_products() {
    FILE *file = fopen(DATA_FILE, "wb");
    if (!file) {
        printf("상품 정보를 저장할 수 없습니다. 파일을 열 수 없습니다.\n");
        return;
    }

    fwrite(products, sizeof(Product), num_products, file);
    fclose(file);
    printf("상품 정보를 성공적으로 저장했습니다.\n");
}

// 1. 입고 함수
void in_received() {
    int id, quantity;
    float price;
    char name[MAX_NAME_LENGTH];

    if (num_products >= MAX_PRODUCTS) {
        printf("상품 개수를 초과하였습니다. 더 이상 추가할 수 없습니다.\n");
        return;
    }

    printf("상품 ID를 입력하세요 (1~%d): ", MAX_PRODUCTS);
    scanf("%d", &id);

    if (id < 1 || id > MAX_PRODUCTS) {
        printf("잘못된 상품 ID입니다. ID는 1에서 %d 사이여야 합니다.\n", MAX_PRODUCTS);
        return;
    }

    printf("상품명을 입력하세요: ");
    getchar(); 
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; 

    printf("입고량을 입력하세요: ");
    scanf("%d", &quantity);

    if (quantity <= 0) {
        printf("입고량은 0보다 커야 합니다.\n");
        return;
    }

    printf("판매 가격을 입력하세요: ");
    scanf("%f", &price);

    if (price <= 0) {
        printf("판매 가격은 0보다 커야 합니다.\n");
        return;
    }

    int index = id - 1;
    if (products[index].id == 0) {
        products[index].id = id;
        strncpy(products[index].name, name, MAX_NAME_LENGTH);
        products[index].price = price;
        num_products++;
    }

    products[index].received += quantity;
    printf("상품 ID %d: '%s' (입고량: %d, 가격: %.2f원)이 업데이트되었습니다.\n",
           id, products[index].name, products[index].received, products[index].price);
}

// 2. 판매 함수
void in_sold() {
    int id, quantity;

    printf("상품 ID를 입력하세요: ");
    scanf("%d", &id);

    if (id < 1 || id > MAX_PRODUCTS || products[id - 1].id == 0) {
        printf("잘못된 상품 ID입니다. 해당 상품이 존재하지 않습니다.\n");
        return;
    }

    printf("판매량을 입력하세요: ");
    scanf("%d", &quantity);

    int index = id - 1;
    if (quantity <= 0 || quantity > (products[index].received - products[index].sold)) {
        printf("판매량이 재고를 초과하거나 잘못된 값입니다. (재고: %d)\n",
               products[index].received - products[index].sold);
        return;
    }

    products[index].sold += quantity;
    products[index].total_sales += quantity * products[index].price;
    printf("상품 ID %d: '%s' (판매량: %d, 총판매금액: %.2f원)\n",
           id, products[index].name, products[index].sold, products[index].total_sales);
}

// 3. 개별 상품 정보 출력
void show_product() {
    int id;

    printf("상품 ID를 입력하세요: ");
    scanf("%d", &id);

    if (id < 1 || id > MAX_PRODUCTS || products[id - 1].id == 0) {
        printf("잘못된 상품 ID입니다. 해당 상품이 존재하지 않습니다.\n");
        return;
    }

    int index = id - 1;
    printf("상품 ID: %d\n상품명: %s\n판매가격: %.2f\n입고량: %d\n판매량: %d\n재고량: %d\n총판매금액: %.2f\n",
           products[index].id, products[index].name, products[index].price,
           products[index].received, products[index].sold,
           products[index].received - products[index].sold, products[index].total_sales);
}

// 4. 전체 상품 현황 출력
void show_all_products() {
    printf("\n전체 상품 현황:\n");

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        Product p = products[i];

        if (p.id != 0) {
            float sales_rate = 0.0f;
            if (p.received > 0) {
                sales_rate = (float)p.sold / p.received * 100;
            }

            printf("ID: %d, 상품명: %s, 가격: %.2f, 입고량: %d, 판매량: %d, 총 판매 금액: %.2f, 판매율: %.2f%%\n",
                   p.id, p.name, p.price, p.received, p.sold, p.total_sales, sales_rate);
        }
    }
}

// 5. 종료 함수
void exit_program() {
    save_products();
    printf("프로그램을 종료합니다.\n");
    exit(0);
}

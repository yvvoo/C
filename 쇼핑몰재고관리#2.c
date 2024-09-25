#include <stdio.h>
#include <stdlib.h>



int main(void)
{
    int num_products;                       //상품 종류
    int received[100];                      //입고 수량
    int sold[100];                          //판매 수량
    int stock[100];                         //재고 수량
    int ID = 0;                             //고유 ID 
    float total_sold = 0;                   //총 판매량
    int total_received = 0;                 //총 입고량
    float sold_percent = 0;                 //판매율
    int max_s = 0;                          //최대 판매수량
    int min_s = 0;                          //최소 판매수량   
    int max_id = 0;                         //최대 판매수량 ID
    int min_id = 0;                         //최소 판매수량 ID



    //상품의 종류 입력
    printf("상품의 종류(개수)를 입력하세요(1~100): ");
    scanf_s("%d", &num_products);
    printf("입력한 상품의 종류: %d\n", num_products);

    if (num_products < 1 || num_products>100)
    {
        printf("상품의 종류(개수)는 1에서 100사이로 입력해주세요.");
        return 1;
    }

    //상품 별 입고 수량 입력
    printf("%d종류의 상품에 대한 입고 수량을 입력하세요: ", num_products);
    for (int i = 0; i < num_products; i++)
    {
        scanf_s("%d", &received[i]);
        total_received += received[i];
    }

    //상품 별 판매 수량 입력
    printf("%d종류의 상품에 대한 판매 수량을 입력하세요: ", num_products);
    for (int i = 0; i < num_products; i++)
    {
        scanf_s("%d", &sold[i]);
        if (sold[i] > received[i])
        {
            printf("\n판매 수량은 입고 수량보다 많을 수 없습니다. 다시 시도해주세요.\n");
            return 1;
        }
    }

    //재고 수량 계산
    for (int i = 0; i < num_products; i++)
    {
        stock[i] = received[i] - sold[i];
    }

    //특정 ID에 해당하는 상품의 재고 수량 출력
    printf("\n");            //공백
    printf("재고를 확인할 상품 ID를 입력하세요(1~%d): ", num_products);
    scanf_s("%d", &ID);

    if (ID<1 || ID>num_products)
    {
        printf("유효하지 않은 상품 ID입니다.\n");
        return 1;
    }
    //ID에 해당하는 재고 수량 출력
    printf("해당 재고 수량: %d\n", stock[ID - 1]);
    //모든 상품의 재고 수량 출력
    printf("전체 재고 수량: ");
    for (int i = 0; i < num_products; i++)
    {
        printf("%d ", stock[i]);
    }
    printf("\n");


    //총 판매량
    for (int i = 0; i < num_products; i++)
    {
        total_sold += sold[i];
    }
   // printf("총 판매량: %d\n", total_sold);

    //전체 판매율 계산 (판매수량/입고수량)*100
    sold_percent = (total_sold / total_received) * 100;
    printf("총 판매량: %d (판매율: %.2f%)\n", total_sold, sold_percent);

    //최대, 최소 판매량 상품 ID과 수량 출력
    max_s = sold[0];
    min_s = sold[0];
    max_id = 1;
    min_id = 1;

    for (int i = 1; i < num_products; i++)
    {
        if (sold[i] > max_s)
        {
            max_s = sold[i];
            max_id = i + 1;
        }
        if (sold[i] < min_s)
        {
            min_s = sold[i];
            min_id = i + 1;
        }
    }

    //최대 및 최소 판매량 상품 출력
    printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", max_id, max_s);
    printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", min_id, min_s);

    //재고 부족 경고
    for (int i = 0; i < num_products; i++)
    {
        if (stock[i] <= 2) {
            printf("상품 ID %d: 재고부족(%d)\n", i + 1, stock[i]);
        }
    }



    return 0;
}

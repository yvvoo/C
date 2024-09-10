#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int num_products;			//상품 종류
	int received[100];			//입고 수량
	int sold[100];				//판매 수량
	int stock[100];				//재고 수량
	int ID;						//고유 ID

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
	}

	//상품 별 판매 수량 입력
	printf("%d종류의 상품에 대한 판매 수량을 입력하세요: ", num_products);
	for (int i = 0; i < num_products; i++)
	{
		scanf_s("%d", &sold[i]);
	}

	//재고 수량 계산
	for (int i = 0; i < num_products; i++)
	{
		stock[i] = received[i] - sold[i];
	}

	//특정 ID에 해당하는 상품의 재고 수량 출력
	printf("\n");				//공백
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

	return 0;
}

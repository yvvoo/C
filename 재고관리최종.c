#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int num_products;			//��ǰ ����
	int received[100];			//�԰� ����
	int sold[100];				//�Ǹ� ����
	int stock[100];				//��� ����
	int ID;						//���� ID

	//��ǰ�� ���� �Է�
	printf("��ǰ�� ����(����)�� �Է��ϼ���(1~100): ");
	scanf_s("%d", &num_products);
	printf("�Է��� ��ǰ�� ����: %d\n", num_products);

	if (num_products < 1 || num_products>100)
	{
		printf("��ǰ�� ����(����)�� 1���� 100���̷� �Է����ּ���.");
		return 1;
	}

	//��ǰ �� �԰� ���� �Է�
	printf("%d������ ��ǰ�� ���� �԰� ������ �Է��ϼ���: ", num_products);
	for (int i = 0; i < num_products; i++)
	{
		scanf_s("%d", &received[i]);
	}

	//��ǰ �� �Ǹ� ���� �Է�
	printf("%d������ ��ǰ�� ���� �Ǹ� ������ �Է��ϼ���: ", num_products);
	for (int i = 0; i < num_products; i++)
	{
		scanf_s("%d", &sold[i]);
	}

	//��� ���� ���
	for (int i = 0; i < num_products; i++)
	{
		stock[i] = received[i] - sold[i];
	}

	//Ư�� ID�� �ش��ϴ� ��ǰ�� ��� ���� ���
	printf("\n");				//����
	printf("��� Ȯ���� ��ǰ ID�� �Է��ϼ���(1~%d): ", num_products);
	scanf_s("%d", &ID);

	if (ID<1 || ID>num_products)
	{
		printf("��ȿ���� ���� ��ǰ ID�Դϴ�.\n");
		return 1;
	}
	//ID�� �ش��ϴ� ��� ���� ���
	printf("�ش� ��� ����: %d\n", stock[ID - 1]);
	//��� ��ǰ�� ��� ���� ���
	printf("��ü ��� ����: ");
	for (int i = 0; i < num_products; i++)
	{
		printf("%d ", stock[i]);
	}
	printf("\n");

	return 0;
}
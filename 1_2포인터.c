//***************포인터는 함수와 함수간에 데이터를 주고 받아야 할 때에만 사용됨
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int number[SIZE];
	int most;
	int temp;

	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		number[i] = (rand() % 10000)+1;
	}

	for (int i = 0; i < SIZE-1; i++) {
		most = i;
		for (int j = i + 1; j < SIZE; j++) {
			if (number[most] < number[j])	most = j;
		}
		swap(&number[i], &number[most]);
	}

	for (int i = 0; i < SIZE; i++) {
		printf("%5d\t", number[i]);
		if ((i + 1) % 10 == 0) printf("\n");
	}
	return 0;
}


//기본 
#include <stdio.h>

int main(void)
{
	int i = 10;
	int *p;
	p = &i;

	printf("i = %d\n", i);
	printf("address of i = %d\n", p);
	printf("*p = %d\n", *p);

	return 0;
}


#include <stdio.h>

int main(void)
{
	int i = 10;
	int* p;

	p = &i;
	*p = 20;

	printf("%d\n", i);

	return 0;
}




#include <stdio.h>
#include <stdlib.h>	
#include <time.h>	
#define SIZE 100

//배열을 입력받는 함수
void inputRandomArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		*(array + i) = rand() % 100; //*(array + i)는 array[i]와 같음
	}
}
//출력 함수
void printArray(int* array, int size) {
	for (int i = 0; i < SIZE; i++) {
		printf("%3d\t", array[i]);
		if ((i + 1) % 10 == 0) printf("\n");
	}
}

int main(void)
{
	int number[SIZE];

	srand(time(NULL));
	inputRandomArray(number, SIZE);
	printArray(number, SIZE);

	return 0;
}

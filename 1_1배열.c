//*******************난수 rand()함수 반환
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int number[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		number[i] = (rand() % 10) + 1;
		printf("number =  %d\n", number[i]);
	}
	return 0;
}



//*******************성적
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main(void)
{
	int number[SIZE];
	int total =0 ;
	int max, min;
	float avg=0.0;

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		number[i] = rand() % 101; //0~100 랜덤생성
	}

	for (int i = 0; i < SIZE; i++) {
		printf("%3d\t", number[i]);
		if ((i + 1) % 10 == 0) printf("\n");
	}
	for (int i = 0; i < SIZE; i++) {
		total += number[i];
	}
	avg = (float)total / SIZE;

	max = number[0];
	min = number[0];
	for (int i = 1; i < SIZE; i++) {
		if (max < number[i]) max = number[i];
		if (min > number[i]) min = number[i];
	}

	printf("\n평균 = %f\n", avg);
	printf("최고점 = %d\n", max);
	printf("최저점 = %d", min);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main(void)
{
    int number[SIZE];
    int total = 0;
    int max_index = 0, min_index = 0;  // 인덱스를 저장할 변수
    float avg = 0.0;

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        number[i] = rand() % 101; // 0~100 랜덤 생성
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%3d\t", number[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    for (int i = 0; i < SIZE; i++) {
        total += number[i];
    }
    avg = (float)total / SIZE;

    // 최고점과 최저점을 인덱스로 찾기
    for (int i = 1; i < SIZE; i++) {
        if (number[max_index] < number[i]) {
            max_index = i;  // 최고값의 인덱스를 저장
        }
        if (number[min_index] > number[i]) {
            min_index = i;  // 최저값의 인덱스를 저장
        }
    }

    printf("\n평균 = %f\n", avg);
    printf("최고점 = %d (인덱스 %d)\n", number[max_index], max_index);
    printf("최저점 = %d (인덱스 %d)", number[min_index], min_index);

    return 0;
}




//*******************정렬
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

int main(void) {
	int number[SIZE];
	int most;
	int temp;

	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		number[i] = (rand() % 1000)+1;
	}

	for (int i = 0; i < SIZE-1; i++) {
		most = i;
		for (int j = i + 1; j < SIZE; j++) {
			if (number[most] < number[j])	most = j;
		}
		temp = number[i];
		number[i] = number[most];
		number[most] = temp;
	}

	for (int i = 0; i < SIZE; i++) {
		printf("%5d\t", number[i]);
		if ((i + 1) % 10 == 0) printf("\n");
	}

	return 0;
}

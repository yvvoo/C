배열: 동일한 자료형 여러 개를 하나의 이름으로 관리
구조체: 서로 다른 자료형 여러 개를 하나의 이름으로 관리

//기본, 두 점의 좌표
#include <stdio.h>
struct point {
	int x;
	int y;
};

int main(void)
{
	struct point p1 = { 10, 20 };
	struct point p2;
	printf("구조체 p1의 멤버변수 x,y의 값: (%d, %d)\n", p1.x, p1.y);
	printf("구조체 p2의 멤버변수 x,y의 값: (%d, %d)\n", p2.x, p2.y);
	p2.x = 30;
	p2.y = 45;
	printf("구조체 p1의 멤버변수 x,y의 값: (%d, %d)\n", p1.x, p1.y);
	printf("구조체 p2의 멤버변수 x,y의 값: (%d, %d)\n", p2.x, p2.y);

	return 0;
}



//두 점 사이의 거리
#include <stdio.h>
#include <math.h>

struct point {
	int x;
	int y;
};

double dist(struct point p1, struct point p2) {                    //함수 dist : 거리 계산하는
	return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

int main(void)
{
	struct point p1 = { 10, 20 };
	struct point p2 = { 0,0 };

	p1.x = 20;
	p2.x = 30;
	p2.y = 40;

	printf("p1.x = %d, p1.y = %d\n", p1.x, p1.y);
	printf("p2.x = %d, p2.y = %d\n", p2.x, p2.y);

	printf("p1, p2 사이의 거리 : %lf", dist(p1, p2));

	return 0;
}
 
 
//두 점 사이의 거리 (근데 이제 typedef를 쓴)
#include <stdio.h>
#include <math.h>

typedef struct point {
	int x;
	int y;
}POINT;

//함수 dist : 거리 계산하는
double dist(POINT p1, POINT p2) {
	return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

int main(void)
{
	POINT p1 = { 10, 20 };
	POINT p2 = { 0,0 };

	p1.x = 20;
	p2.x = 30;
	p2.y = 40;

	printf("p1.x = %d, p1.y = %d\n", p1.x, p1.y);
	printf("p2.x = %d, p2.y = %d\n", p2.x, p2.y);

	printf("p1, p2 사이의 거리 : %lf", dist(p1, p2));

	return 0;
}



//점, 원(좌표값이 원 안의 영역에 포함하는지), 사각형
#include <stdio.h>
#include <math.h>

typedef struct point {
	int x;
	int y;
} POINT;

typedef struct circle {
	POINT center;		//원의 중심
	double radius;		//원의 반지름
} CIRCLE;

typedef struct rect {
	POINT lb;		//left bottom
	POINT rt;		//right top
};

double dist(POINT p1, POINT p2) {
	return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

int main(void)
{
	CIRCLE c1 = { {10,10}, 4.5 };
	CIRCLE c2;
	c2.radius = 5.5;
	c2.center.x = 10;
	c2.center.y = 20;
	POINT point = { 10,15 };
	double distance;

	printf("CIRCLE1 = (%d, %d), r : %lf\n", c1.center.x, c1.center.y, c1.radius);
	printf("CIRCLE2 = (%d, %d), r : %lf\n", c2.center.x, c2.center.y, c2.radius);
	printf("point = (%d, %d)\n", point.x, point.y);

	distance = dist(c1.center, point);		//원C1의 중심좌표와 두 점의 좌표point의 거리를 계산
	printf("distance = %lf\n", distance);
	
	if (distance <= c1.radius) {			//그것이 반지름보다 작거나 같을 때
		printf("원 안에 있습니다. \n");
	}
	else {
		printf("원 밖에 있습니다. \n");
	}
	return 0;
}




//구조체 + 배열
//10개의 POINT를 생성, POINT 좌표값은 0~100 사이의 난수로
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100

typedef struct point {
	int x;
	int y;
} POINT;

int main(void)
{
	POINT point[SIZE] = { 0 };	//10개 배열 생성
	POINT temp = { 0,0 };		//임시변수
	int least;

	srand(time(NULL));			//출력할 때마다 seed값이 달라짐
	for (int i = 0; i < SIZE; i++) {
		point[i].x = rand() % 101;
		point[i].y = rand() % 101;
	}							//난수 생성

	for (int i = 0; i < SIZE; i++) {
		printf("point[%3d] : (%3d, %3d)\n", i, point[i].x, point[i].y);
	}

	for (int i = 0; i < SIZE; i++) {
		least = i;
		for (int j = i + 1; j < SIZE; j++) {
			if (point[least].x > point[j].x) least = j;
			else if(point[least].x ==point[j].x && (point[least].y > point[j].y))
				least = j;
		}
		temp = point[least];
		point[least] = point[i];
		point[i] = temp;
	}

	printf("\nafter sorting --------------->\n");
	for (int i = 0; i < SIZE; i++) {
		printf("point[%3d] : (%3d, %3d)\n", i, point[i].x, point[i].y);
	}

	return 0;
}




구조체 + 배열 + 포인터(new!)
10개의 POINT를 생성, POINT 좌표값은 0~100 사이의 난수로
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 100
typedef struct point {
	int x;
	int y;
} POINT;

void input_random_point(POINT* p, int size)		//int size: 배열의 크기
{
	srand((time(NULL)));
	for (int i = 0; i < size; i++) {
		(p+i)->x = rand() % 101;
		(p+i)->y = rand() % 101;
	}
}

void swap_point(POINT* p1, POINT* p2)	
{
	POINT temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void print_point_array(POINT p[], int size)
{
	for (int i = 0; i < size; i++) {
		printf("point[%3d] : (%3d, %3d)\n", i, p[i].x, p[i].y);
	}
}

void selection_sort_point(POINT* point, int size)
{
	int least;
	for (int i = 0; i < SIZE; i++) {
		least = i;
		for (int j = i + 1; j < SIZE; j++) {
			if ((point+least)->x > point[j].x) least = j;
			else if (point[least].x == point[j].x && (point[least].y > point[j].y))
				least = j;
		}
		swap_point(&point[i], point + least);
	}
}

int main(void)
{
	POINT point[SIZE] = { 0 };	//10개 배열 생성
	POINT temp = { 0,0 };		//임시변수
	int least;

	input_random_point(point, SIZE);		//배열에 랜덤 좌표 할당
	print_point_array(point, SIZE);			//배열 내용 출력
	selection_sort_point(point, SIZE);		//선택 정렬

	printf("\nafter sorting --------------->\n");
	print_point_array(point, SIZE);

	return 0;
}

//기본
#include <stdio.h>

int main(void)
{
	char message[20] = "hello world\n";
	printf("%s", message);

	return 0;
}


#include <stdio.h>

int main(void)
{
	char message[5] = { 'a', 'b', 'c', 'd', 'e' };
	char message2[5] = { 'a', 'b', 'c', '\0' };

	printf("%s, %s", message, message2);

	return 0;
}

#include <stdio.h>

int main(void)
{
	int ch;
	do {
		ch = getchar();
		putchar(ch);
	} while (ch != EOF);

	return 0;
}

//getchar(), putchar() 함수 사용
//문자열 한줄 입력(마지막에 NULL잊지말기)
#include <stdio.h>

int main(void)
{
	int ch;
	char message[100];
	int i = 0;
	while ((ch = getchar()) != '\n') {
		message[i++] = ch;
		
	}
	message[i] = '\0';
	printf("%s", message);

	return 0;
}

//문자열 비교
#include <stdio.h>
#include <string.h>

int main(void)
{
	char src[100];
	char dest[100];
	int result;
	gets(src);
	gets(dest);

	result=strcmp(src, dest);
	printf("result = %d\n", result);

	return 0;
}


//문자열 (알파벳 개수?)카운팅 코드
#include <stdio.h>

int main(void)
{
	char input[200] = "";
	int count[26] = { 0 };
	int ch;
	int i = 0;

	while ((ch = getchar()) != EOF) {
		input[i++] = ch;
	}
	i = 0;
	while (input[i] != '\0') {
		if (input[i] >= 'a' && input[i] <= 'z') {
			count[input[i] - 'a']++;
		}
		i++;
	}

	printf("입력문자열 : %s\n", input);
	for (int i = 0; i < 26; i++) printf("%c 출현횟수 : %d\n", 'a' + i, count[i]);

	return 0;
}

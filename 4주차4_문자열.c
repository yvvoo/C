#include <stdio.h>

int main()
{
	int ch;
	ch = getchar();
	putchar(ch);

	return 0;
}



#include <stdio.h>

int main()
{
	int ch;
	while ((ch = getchar()) != '\n') {
		putchar(ch);
	}

  return 0;
}



#include <stdio.h>
int main()
{
	int ch;
	char message[100];
	int i = 0;

	while ((ch = getchar()) != '\n') {
		message[i++] = ch;
	}
	message[i] = '\0';				// NULL문자 꼭 넣기!!
	printf("%s", message);

	return 0;
}

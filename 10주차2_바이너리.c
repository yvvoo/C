// 사용자로부터 입력을 받아 output.bin이라는 파일에 이진 형식으로 저장하는 프로그램

#include <stdio.h>
#include <string.h>
#define gets(input) fgets(input, sizeof(input), stdin)
#define SIZE 100
int main(void)
{
    char input[SIZE];
    FILE* fp = NULL;
    
    if ((fp=fopen("output.bin", "wb")) == NULL){
        printf("error...");
        return 0;
    }
    gets(input);
    fwrite(input, strlen(input), 1, fp);
    
    fclose(fp);
    
    return 0;
}

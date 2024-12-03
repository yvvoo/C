// 파일을 복사하는 프로그램. 
// output.txt 파일의 내용을 읽어서 output2.txt 파일에 복사하는 기능

#include <stdio.h>
int getLine(char* line)
{
    int ch;
    int i = 0;
    while ((ch=getchar()) != '\n') line[i++] = ch;
    line[i] = '\0';
    return i;
}
int main()
{
    char input[100];
    FILE* fp_src;
    FILE* fp_dest;
    
    if((fp_src = fopen("output.txt", "r")) == NULL){
        printf("error....");
        return 0;
    }
    if((fp_dest = fopen("output2.txt", "w")) == NULL){
        printf("error....");
        return 0;
    }
    
    while(!feof(fp_src)){
        fgets(input, 100, fp_src);
        printf("출 력 중\n");
        fputs(input, fp_dest);
    }
    
    fclose(fp_src);
    fclose(fp_dest);
    return 0;
}

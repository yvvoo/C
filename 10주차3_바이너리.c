// output.bin이라는 바이너리 파일에서 데이터를 읽어와 문자열로 변환한 뒤 출력하는 프로그램. 
// output.bin에 텍스트입력 후 콘솔에 출력.
#include <stdio.h>
#include <string.h>
#define gets(input) fgets(input, sizeof(input), stdin)
#define SIZE 100
int main(void)
{
   char input[SIZE];
   FILE* fp = NULL;
   int i = 0;
   if((fp=fopen("output.bin", "rb")) == NULL){
       printf("error...");
       return 0;
   }
   while (!feof(fp)){
       fread(&input[i], sizeof(char), 1, fp);
       i++;
   }
   input[--i] = '\0';               // 파일 끝에 도달하면서 증가한 인덱스를 감소시켜 \0을 설정. 끝에 이상한 문자 나오는걸 방지.
   puts(input);                     // input 배열에 저장된 문자열을 화면에 출력.
   
   fclose(fp);
   
   return 0;
}



// array.bin이라는 바이너리 파일에 배열 데이터를 저장하는 프로그램.
// 문자열 읽기가 포인트.
#include <stdio.h>
int main()
{
    int array[100];
    FILE* fp;
    
    for(int i=0;i<100;i++) array[i] = i;
    
    fp = fopen("array.bin", "wb");
    if(fp == NULL) return -1;
    
    fwrite(array, sizeof(array), 1, fp);      // fwrite(array, sizeof(int), 100, fp); 와 같음. 4*100=400(바이트)
    fclose(fp);
    
    return 0;
}



// 바이너리 파일 array.bin에서 데이터를 읽어와 정수 배열에 저장하고, 그 데이터를 화면에 출력하는 프로그램. 
// 정수형 데이터를 읽고 출력하는게 포인트.
#include <stdio.h>
int main()
{
    int array[1000];
    FILE* fp;
    int i = 0;
    fp = fopen("array.bin", "rb");   // 파일 열기.
    if(fp == NULL) return -1;
    
    fread(array, sizeof(int), 100, fp);   //데이터 읽기: 파일에서 처음 100개의 정수를 읽어 array 배열에 저장.
    
    for (int i=0;i<100;i++) printf("%d ", array[i]);   // 데이터 출력: 배열의 처음 100개의 데이터를 화면에 출력.
    fclose(fp);   // 파일 닫기.
    return 0;
}


// 바이너리 파일 array.bin에서 데이터를 읽어와 정수 배열에 저장하고, 그 데이터를 화면에 출력하는 프로그램. 
// 위의 코드와 다른 점 : 파일 읽기 방식에서 반복문을 사용하여 파일 끝까지 데이터를 읽는 것.
#include <stdio.h>
int main()
{
    int array[1000];
    FILE* fp;
    int i = 0;
    
    fp = fopen("array.bin", "rb");
    if(fp == NULL) return -1;
    
    while(fread(&array[i++], sizeof(int), 1, fp));      // fread : 파일에서 데이터를 읽어 array[i]에 저장.
                                                        // 파일 끝에 도달하면 0을 반환하여 반복문을 종료.ㅣ
    
    i--;      // 반복문 종료 후 i는 마지막으로 읽은 데이터 위치 +1을 가리킴. 유효한 데이터의 개수 조정.
              // 99다음 0이 나오는 것을 없애줌.
    for(int j=0; j<i; j++) printf("%d ", array[j]);      // 배열의 처음부터 i번째 요소까지 출력.
    fclose(fp);
    return 0;
}

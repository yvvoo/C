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
   input[--i] = '\0';
   puts(input);
   
   fclose(fp);
   
   return 0;
}



#include <stdio.h>
int main()
{
    int array[1000];
    FILE* fp;
    int i = 0;
    fp = fopen("array.bin", "rb");
    if(fp == NULL) return -1;
    
    fread(array, sizeof(int), 100, fp);
    
    for (int i=0;i<100;i++) printf("%d ", array[i]);
    fclose(fp);
    return 0;
}



#include <stdio.h>
int main()
{
    int array[1000];
    FILE* fp;
    int i = 0;
    
    fp = fopen("array.bin", "rb");
    if(fp == NULL) return -1;
    
    while(fread(&array[i++], sizeof(int), 1, fp));
    
    i--;
    for(int j=0; j<i; j++) printf("%d ", array[j]);
    fclose(fp);
    return 0;
}

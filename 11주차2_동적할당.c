// malloc 활용방법.1

#include <stdio.h>
#include <stdlib.h>

#define gets(input) fgets(input, sizeof(input), stdin)

int main()
{
    char* pChar;
    int* pInt;
    int count;
    
    scanf("%d", &count);
    pInt = (int*)malloc(count*sizeof(int));
    
    for(int i = 0; i<count; i++) pInt[i] = rand() % 100;
    for(int i = 0; i<count; i++) printf("%d ", pInt[i]);
    
    pChar = (char*)pInt;
    
    while(getchar() != '\n');
    gets(pChar);
    puts(pChar);
    
    free(pInt);
    return 0;
}

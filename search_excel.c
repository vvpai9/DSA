#include <stdio.h>
int main() 
{
    FILE *inputFile;
    int values[10];
    int searchValue,is_found=0;
    inputFile=fopen("input.csv","r");
    if (inputFile==NULL) 
    {
        printf("404:file not found\n");
        return 1;
    }
    printf("Value to find: ");
    scanf("%d", &searchValue);
    for (int i=0;i<10;i++) 
    {
        fscanf(inputFile,"%d,",&values[i]);
        if(values[i]==searchValue) 
        {
            is_found=1;
            break;
        }
    }
    if(is_found) 
        printf("Element is present.\n");
    
    else
        printf("Element is absent.\n");

    fclose(inputFile);
    return 0;
}
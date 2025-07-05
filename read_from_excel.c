#include <stdio.h>
#include <stdlib.h>

void sort(int arr[],int n,int ascending) 
{
    for(int i=0;i<n-1;i++) 
    {
        for(int j=0;j<n-i-1;j++)
        if (ascending && arr[j]>arr[j+1]) 
        {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
        else if(!ascending && arr[j]<arr[j+1]) 
        {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}

int main() 
{
    FILE *inputFile;
    int values[10];
    
    inputFile=fopen("input.csv","r+");
    if(inputFile==NULL)
    {
        printf("File not found\n");
        return 0;
    }
    for (int i=0;i<10;i++)
        fscanf(inputFile,"%d,",&values[i]);
    
    sort(values,10,1);
    fseek(inputFile,0,SEEK_END);
    fprintf(inputFile,"\nAscending: ");

    for (int i=0;i<10;i++)
        fprintf(inputFile,"%d,",values[i]);
    
    sort(values,10,0);
    fprintf(inputFile,"\nDescending: ");

    for (int i=0;i<10;i++)
        fprintf(inputFile,"%d,",values[i]);

    fclose(inputFile);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void readFile(int arr[],int n, char *filename);
int bucketSort(int arr[], int n);

int main()
{
    int n;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    int arr[n];
    readFile(arr,n,"input.txt");
    printf("array before sorting:\n");
    
    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
    
       printf("\n");
    
    bucketSort(arr,n);
    printf("array after sorting:\n");
    
    for(int i=0;i<n;i++)
       printf("%d ",arr[i]);
    
       printf("\n");
    return 0;
}

void readFile(int arr[],int n,char *filename)
{
    FILE *input;
    input=fopen(filename,"r");
    if (input == NULL) 
    {
        printf("File couldn't be found\n");
        exit(1);
    }
    else
    {
        for(int i=0;i<n;i++)
            fscanf(input, "%d", &arr[i]);

        fclose(input);
    }
}

int bucketSort(int arr[], int n) 
{
    int i,j;
    int max=arr[0];
    int is_sorted=1;
    for(i=0;i<n-1;i++)
    {
        if(arr[i]<arr[i-1])
        {
            is_sorted=0;
            break;
        }
    }

    for(i=1;i<n;i++)
    {
        if (arr[i]>max)
            max=arr[i];
    }
    int bucket[max+1];
    for (i=0;i<=max;i++)
        bucket[i] = 0;

    for (i=0;i<n;i++)
        bucket[arr[i]]++;

    for(i=0,j=0;i<=max;i++)
    {
        while(bucket[i]>0)
        {
            arr[j++]=i;
            bucket[i]--;
        }
    }
}
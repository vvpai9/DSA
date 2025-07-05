#include <stdio.h>
#include <stdlib.h>

void readFile(int ar[],int n,char *filename);
void insertionSort(int ar[],int n);

int main()
{
    int n = 10;
    int ar[n];
    readFile(ar, n, "input.txt");
    printf("My list before:\n");

    for (int i=0;i<n;i++)
        printf("%d ", ar[i]);
    printf("\n");

    insertionSort(ar, n);
    printf("My list after:\n");

    for (int i=0;i<n;i++)
        printf("%d ", ar[i]);

    printf("\n");
    return 0;
}

void readFile(int ar[], int n, char *filename)
{
    FILE *input;
    input=fopen(filename, "r");
    if (input==NULL) 
    {
        printf("File couldn't be found\n");
        exit(1);
    }
    else
    {
        for(int i=0;i<n;i++)
            fscanf(input,"%d",&ar[i]);

        fclose(input);
    }
}

void insertionSort(int ar[], int n) 
{
    int is_sorted=1;
    for (int i=1;i<n;i++)
    {
        if (ar[i]<ar[i-1])
        {
            is_sorted=0;
            break;
        }
    }
    if (is_sorted)
        return;
    for (int i =1;i<n;i++)
    {
        int a=ar[i];
        int j=i-1;
        while (j>=0 && ar[j]>a) 
        {
            ar[j+1]=ar[j];
            j=j-1;
        }
        ar[j+1]=a;
    }
}

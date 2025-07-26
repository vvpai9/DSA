#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void SortAsc(int arr[], int n) 
{
    int i, j, temp;
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void SortDesc(int arr[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] < arr[j + 1]) 
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int num[SIZE], asc[SIZE], desc[SIZE], i;
    FILE *file = fopen("Input.csv", "r");
    if (file) 
    {
        printf("Reading numbers from Input.csv...\n");
        for (i = 0; i < SIZE; i++) 
        {
            if (fscanf(file, "%d,", &num[i]) != 1) 
            {
                printf("Error: Input.csv does not contain 10 valid numbers.\n");
                fclose(file);
                return 1;
            }
        }
        fclose(file);
        for (i = 0; i < SIZE; i++) 
        {
            asc[i] = num[i];
            desc[i] = num[i];
        }
        SortAsc(asc, SIZE);
        SortDesc(desc, SIZE);
        file = fopen("Output.csv", "w");
        if (file)
        {
            fprintf(file, "Original,Ascending,Descending\n");
            for (i = 0; i < SIZE; i++) 
            {
                fprintf(file, "%d,%d,%d\n", num[i], asc[i], desc[i]);
            }
            fclose(file);
            printf("Sorting complete. Check Output.csv for results.\n");
        }
        else
            printf("Error opening Output.csv\n");
    }
    else
        printf("Error opening Input.csv\n");
    return 0;
}
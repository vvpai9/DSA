#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void shellSort(int arr[], int n) 
{
    int i, j, temp, gap;
    for ( gap = n / 2; gap > 0; gap /= 2) 
    {
        for (i = gap; i < n; i++) 
        {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int readNum(const char *filename, int arr[])
{
    FILE *file = fopen(filename, "r");
    int count = 0;
    if (file) 
    {
        while (fscanf(file, "%d", &arr[count]) != EOF && count < MAX_SIZE)
            count++;
        fclose(file);
    }
    else
        printf("Error opening file: %s\n", filename);
    return count;
}

void writeFile(const char *filename, int arr[], int n) 
{
    FILE *file = fopen(filename, "w");
    int i;
    if (file) 
    {
        for (i = 0; i < n; i++)
            fprintf(file, "%d\n", arr[i]);
        fclose(file);
        printf("Sorted numbers written to %s\n", filename);
    }
    else
        printf("Error opening file: %s\n", filename);
}

int main() 
{
    int numbers[MAX_SIZE], count;
    count = readNum("Input.txt", numbers);
    if (count) 
    {
        shellSort(numbers, count);
        writeFile("Sorted.txt", numbers, count);
        printf("Sorting complete. Check Sorted.txt for results.\n");
    }
    else
        printf("File is empty");
    return 0;
}

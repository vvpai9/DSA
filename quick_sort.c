#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high], i = low - 1, j, temp;
    for (j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1); 
}

void quickSort(int arr[], int low, int high) 
{
    int pi;
    if (low < high) 
    {
        pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high);
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
        quickSort(numbers, 0, count - 1);
        writeFile("Sorted.txt", numbers, count);
        printf("Sorting complete. Check Sorted.txt for results.\n");
    }
    else
        printf("File is empty");
    return 0;
}

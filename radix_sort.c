#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int findMax(int arr[], int n) 
{
    int max = arr[0], i;
    for (i = 1; i < n; i++) 
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSortByDigit(int arr[], int n, int exp) 
{
    int output[n], count[10] = {0}, i;
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) 
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) 
{
    int max = findMax(arr, n), exp;
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortByDigit(arr, n, exp);
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
        radixSort(numbers, count);
        writeFile("Sorted.txt", numbers, count);
        printf("Sorting complete. Check Sorted.txt for results.\n");
    }
    else
        printf("File is empty");
    return 0;
}
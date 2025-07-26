#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define BUCKET_SIZE 10

typedef struct {
    int *array, count;
} Bucket;

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

void insertionSort(int arr[], int n) 
{
    int i, j, key;
    for (i = 1; i < n; i++) 
    {
        for (key = arr[i], j = i - 1; j >= 0 && arr[j] > key; j--) 
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

void bucketSort(int arr[], int n) 
{
    int max, min, i, j, range, bucketIndex, index;
    Bucket buckets[BUCKET_SIZE];
    if (n >= 0) 
    {
        max = findMax(arr, n);
        min = arr[0];
        for (i = 1; i < n; i++) 
        {
            if (arr[i] < min)
                min = arr[i];
        }
        range = (max - min) / BUCKET_SIZE + 1;
        for (i = 0; i < BUCKET_SIZE; i++) 
        {
            buckets[i].array = (int *)malloc(n * sizeof(int));
            buckets[i].count = 0;
        }
        for (i = 0; i < n; i++) 
        {
            bucketIndex = (arr[i] - min) / range;
            buckets[bucketIndex].array[buckets[bucketIndex].count++] = arr[i];
        }
        for (index = i = 0; i < BUCKET_SIZE; i++) 
        {
            insertionSort(buckets[i].array, buckets[i].count);
            for (j = 0; j < buckets[i].count; j++)
                arr[index++] = buckets[i].array[j];
            free(buckets[i].array);
        }
    }
    else
        printf("No numbers to sort\n");
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
        bucketSort(numbers, count);
        writeFile("Sorted.txt", numbers, count);
        printf("Sorting complete. Check Sorted.txt for results.\n");
    }
    else
        printf("File is empty");
    return 0;
}

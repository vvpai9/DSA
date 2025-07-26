#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void merge(int arr[], int left, int mid, int right) 
{
    int i, j, k, n1 = mid - left + 1, n2 = right - mid, L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    for (i = j = 0, k = left; i < n1 && j < n2;) 
    {
        if (L[i] <= R[j]) 
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) 
{
    int mid;
    if (left < right) 
    {
        mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
        mergeSort(numbers, 0, count - 1);
        writeFile("Sorted.txt", numbers, count);
        printf("Sorting complete. Check Sorted.txt for results.\n");
    }
    else
        printf("File is empty");
    return 0;
}

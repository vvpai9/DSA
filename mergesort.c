#include <stdio.h>
#include <stdlib.h>

void loadArrayFromFile(int arr[], int n, char *filename);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main() {
    int n = 10;
    int arr[n];

    loadArrayFromFile(arr,n,"input.txt");

    printf("before sorting:\n");
    for (int i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr,0,n-1);

    printf("after sorting:\n");
    for (int i=0;i<n;i++)
        printf("%d",arr[i]);
    printf("\n");

    return 0;
}

void loadArrayFromFile(int arr[], int n, char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    printf("Reading numbers from file...\n");  // Debug message

    for (int i = 0; i < n; i++)
    {
        if (fscanf(file, "%d", &arr[i])!=1)
        {  // Handle file read errors
            printf("Error: Failed to read number at index %d\n", i);
            fclose(file);
            exit(1);
        }
    }

    fclose(file);
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;  // Midpoint calculation

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    
    // Merge the two halves back into arr[]
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from leftArr[]
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements from rightArr[]
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

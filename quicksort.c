#include <stdio.h>
#include <stdlib.h>

void loadArrayFromFile(int arr[], int n, char *filename);
void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
    int n = 10;
    int arr[n];

    loadArrayFromFile(arr, n, "input.txt");

    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("Array after sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void loadArrayFromFile(int arr[], int n, char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    printf("Reading numbers from file...\n");  // Debugging print

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {  // Handle file read errors
            printf("Error: Failed to read number at index %d\n", i);
            fclose(file);
            exit(1);
        }
    }

    fclose(file);
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array, and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort left and right subarrays
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = low - 1;        // i will track the position for swapping

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;  // Move the smaller element to the correct position
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap pivot into its correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;  // Return the pivot index
}

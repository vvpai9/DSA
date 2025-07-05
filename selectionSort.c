#include <stdio.h>
#include <stdlib.h>

void loadArrayFromFile(int arr[], int n, char *filename);
void selectionSort(int arr[], int n);

int main() {
    int n = 10;
    int arr[n];

    loadArrayFromFile(arr, n, "input.txt");

    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    selectionSort(arr, n);

    printf("Array after sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
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

    printf("Reading numbers from file...\n");  // Debugging print

    for (int i = 0; i < n; i++)
    {
        if (fscanf(file, "%d", &arr[i]) != 1)
        {  // Handle file read errors
            printf("Error: Failed to read number at index %d\n", i);
            fclose(file);
            exit(1);
        }
    }

    fclose(file);
}

void selectionSort(int arr[], int n)
{
    int isSorted = 1;  // Assume the array is already sorted

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        // minimum element in the unsorted portion
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
                isSorted = 0;  // If smaller element, array isn't sorted
            }
        }

        // Swap only if needed
        if (minIndex != i) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }

        // If no swaps were needed, the array is already sorted
        if (isSorted) {
            printf("Array is already sorted, exiting early.\n");  // Debug message
            return;
        }

        isSorted = 1;  // Reset sorted flag
    }
}

#include <stdio.h>
#include <stdlib.h>

void loadArrayFromFile(int arr[], int n, char *filename);
void radixSort(int arr[], int n);
int getMax(int arr[], int n);
void countSort(int arr[], int n, int digitPlace);

int main()
{
    int n = 10;
    int arr[n];

    loadArrayFromFile(arr, n, "input.txt");

    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    radixSort(arr, n);

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

void radixSort(int arr[], int n)
{
    int maxVal = getMax(arr, n);

    // Process each digit's place value using counting sort
    for (int digitPlace = 1; maxVal / digitPlace > 0; digitPlace *= 10) {
        countSort(arr, n, digitPlace);
    }
}

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

void countSort(int arr[], int n, int digitPlace) {
    int output[n];  
    int count[10] = {0};  // Count occurrences of digits (0-9)

    // Count occurrences of each digit at the current place value
    for (int i = 0; i < n; i++)
        count[(arr[i] / digitPlace) % 10]++;

    // Convert count[] into a cumulative frequency array
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array using the count array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / digitPlace) % 10] - 1] = arr[i];
        count[(arr[i] / digitPlace) % 10]--;
    }

    // Copy sorted elements back into the original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

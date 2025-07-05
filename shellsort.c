#include <stdio.h>
#include <stdlib.h>

void loadArrayFromFile(int arr[], int n, char *filename);
void shellSort(int arr[], int n);

int main() {
    int n = 10;
    int arr[n];

    loadArrayFromFile(arr, n, "input.txt");

    printf("Array before sorting:\n");
    for (int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    shellSort(arr, n);

    printf("Array after sorting:\n");
    for (int i=0;i<n;i++)
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

    printf("Reading numbers from file...\n");  // Debugging message

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1)
        {  // Handle file read errors
            printf("Error: Failed to read number at index %d\n", i);
            fclose(file);
            exit(1);
        }
    }

    fclose(file);
}

void shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce it
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Perform insertion sort for the current gap size
        for (int i=gap;i<n;i++)
        {
            int temp = arr[i];
            int j;

            // Shift elements of the gap-sorted array
            for (j=i;j>=gap && arr[j-gap]>temp;j-=gap)
                arr[j] = arr[j - gap];

            // Insert temp
            arr[j]=temp;
        }
    }
}

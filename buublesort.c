#include <stdio.h>
#include <stdlib.h>

void loadArrayFromFile(int arr[], int n, char *filename);
void bubbleSort(int arr[], int n);

int main()
{
    int n=10;
    int arr[n];

    loadArrayFromFile(arr,n,"input.txt");

    printf("Before sorting:\n");
    for (int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    printf("Sorting in progress...\n");

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void loadArrayFromFile(int arr[], int n, char *filename) {
    FILE *input = fopen(filename, "r");
    if (input == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    printf("Loading numbers from file...\n"); //debug print

    for (int i = 0; i < n; i++)
    {
        if (fscanf(input, "%d", &arr[i]) != 1)
        {  // Handle read errors
            printf("Error reading number at index %d\n", i);
            fclose(input);
            exit(1);
        }
    }

    fclose(input);
}

void bubbleSort(int arr[], int n)
{
    int swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;  // Assume no swaps
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap adjacent elements if out of order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;  // Mark that a swap occurred
            }
        }

        // printf("After pass %d: ",i+1);
        // for(int k=0;k<n;k++)
        // printf("%d ", arr[k]);
        // printf("\n");

        if (!swapped)
        { 
            // break if no swaps were made
            break; 
        }
    }
}

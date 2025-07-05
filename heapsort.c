#include <stdio.h>
#include <stdlib.h>

void loadNumbersFromFile(int arr[], int n, char *filename);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);

int main()
{
    int n=10;  // Adjust for larger values of arrays
    int arr[n];

    loadNumbersFromFile(arr,n,"input.txt");

    printf("Before sorting:\n");
    for (int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    heapSort(arr,n);

    printf("Sorted:\n");
    for (int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;
}

void loadNumbersFromFile(int arr[], int n, char *filename)
{
    FILE *input = fopen(filename, "r");
    if (input == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    printf("Reading numbers from file...\n");  // A debug line

    for (int i = 0; i < n; i++) {
        if (fscanf(input, "%d", &arr[i]) != 1)
        {  //file reading errors
            printf("Error reading number at index %d\n", i);
            fclose(input);
            exit(1);
        }
    }

    fclose(input);
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Checking if the array is already sorted
    int isSorted = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            isSorted = 0;
            break;
        }
    }
    if (isSorted)
    {
        printf("Array is already sorted, skipping heap sort.\n");
        return;
    }

    // Build max heap
    for (int i=n/2-1;i>=0;i--)
        heapify(arr, n, i);

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void performOperations(int arr[], int n, const char *outputFile) 
{
    int sum = 0, product = 1, i;
    float division = (float)arr[0]; 
    FILE *file = fopen(outputFile, "w");
    if (file) 
    {
        fprintf(file, "Numbers: ");
        for (i = 0; i < n; i++) 
        {
            fprintf(file, "%d ", arr[i]);
            sum += arr[i];
            product *= arr[i];
        }
        fprintf(file, "\n\nAddition (Sum of all numbers): %d\n", sum);
        fprintf(file, "Multiplication (Product of all numbers): %d\n", product);
        fprintf(file, "\nSubtraction (Consecutive differences): ");
        for (i = 1; i < n; i++) 
            fprintf(file, "%d ", arr[i - 1] - arr[i]);
        fprintf(file, "\n\nDivision (Consecutive divisions): ");
        for (i = 1; i < n; i++) 
        {
            if (arr[i] != 0)
                division /= arr[i];
            else
            {
                fprintf(file, "\nError: Division by zero detected. Skipping.");
                break;
            }
        }
        fprintf(file, "\nFinal Division Result: %.2f\n", division);
        fclose(file);
        printf("Mathematical operations completed. Results saved in %s\n", outputFile);
    }
    else
        printf("Error opening file: %s\n", outputFile);   
}

int main() 
{
    int numbers[SIZE], i;
    FILE *file = fopen("Input.txt", "r");

    if (file) 
    {
        printf("Reading numbers from Input.txt...\n");
        for (i = 0; i < SIZE; i++) 
        {
            if (fscanf(file, "%d", &numbers[i]) != 1) 
            {
                printf("Error: Input.txt does not contain 10 valid numbers.\n");
                fclose(file);
                return 1;
            }
        }
        fclose(file);
        operations(numbers, SIZE, "Output.txt");
    }
    else
        printf("Error opening file: Input.txt\n");
    return 0;
}

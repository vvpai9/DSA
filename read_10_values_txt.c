#include <stdio.h>
int main() 
{
    FILE *inputFile,*outputFile;
    int values[10];
    int sum=0,diff=0,prod=1;
    float div=1.0;
    inputFile=fopen("input.txt", "r");
    outputFile=fopen("output.txt", "w");
    if(inputFile == NULL || outputFile == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    for(int i=0;i<10;i++)
    {
        fscanf(inputFile, "%d", &values[i]);
        sum += values[i];
        diff -= values[i];
        prod *= values[i];
        div /= values[i];
    }

    fprintf(outputFile, "Sum: %d\n", sum);
    fprintf(outputFile, "Difference: %d\n", diff);
    fprintf(outputFile, "Product: %d\n", prod);
    fprintf(outputFile, "Division: %f\n", div);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
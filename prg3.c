#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int search (int num[], int n, int key) 
{
    int i;
    for (i = 0; i < n; i++) 
    {
        if (num[i] == key)
            return 1;
    }
    return 0;
}

int main() 
{
    int num[MAX_SIZE], key, count = 0, found = 0, i;
    FILE *file = fopen("data.csv", "r");
    if (file) 
    {
        printf("Enter the number to search: ");
        scanf("%d", &key);
        for (; fscanf(file, "%d,", &num[count]) != EOF && count < MAX_SIZE; count++)
        fclose(file);
        found = search(num, count, key);
        if (found)
            printf("Number %d is present in the file.\n", key);
        else 
            printf("Number %d is absent in the file.\n", key); 
    }
    else
        printf("Error opening file: data.csv\n");
    return 0;
}

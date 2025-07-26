#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random(int N, int P, int Q)
{
    int num, i;
    FILE *file = fopen("random.txt", "w");
    if (file) 
    {
        
        srand(time(NULL));
        for (i = 0; i < N; i++) 
        {
            num = P + rand() % (Q - P + 1);
            fprintf(file, "%d\n", num);
        }
        fclose(file);
        printf("Successfully written %d random numbers to Input.txt\n", N);
    }
    else
        printf("Error opening file!\n");
}

int main() 
{
    int N, P, Q;
    printf("Enter the number of random numbers to generate (N): ");
    scanf("%d", &N);
    printf("Enter the lower bound (P): ");
    scanf("%d", &P);
    printf("Enter the upper bound (Q): ");
    scanf("%d", &Q);
    if (P > Q)
        printf("Invalid range! P should be less than or equal to Q.\n");
    else
        random(N, P, Q);
    return 0;
}

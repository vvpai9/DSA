//N random numbers between (P,Q)
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    FILE *inputFile;
    inputFile=fopen("input.txt", "w");
    if (inputFile == NULL) 
    {
        printf("File not found\n");
        return 1;
    }
    int r,p,q,n;
    printf("enter the value of P, Q and N\n");
    scanf("%d%d%d",&p,&q,&n);
    srand(time(0));
    printf("%d random numbers between %d and %d are:\n",n,p,q);
    for(int i=0;i<n;i++)
    {
        r= p+rand()%(q-p+1);
        printf("%d\n",r);
        fprintf(inputFile, "%d ", r);
    }
    fclose(inputFile);
    printf("Press any key to close\n");
    char a;
    scanf(" %c",&a);
    return 0;
}
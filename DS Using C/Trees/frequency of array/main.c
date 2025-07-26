#include <stdio.h>

void read (int a[], int n)
{
	int i;
	for  (i = 0; i < n; i++)
		scanf ("%d", &a[i]);
}

void display (int a[], int n)
{
	int i;
	for  (i = 0; i < n; i++)
		printf ("%d ", a[i]);
}

void frequency (int a[], int n)
{
    int i, j, fr[n], count;
    for (i = 0; i < n; fr[i] = 0, i++);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1, count = 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
                fr[j] = -1;
            }
        }
        if (fr[i] != -1)
            fr[i] = count;
    }
    for (i = 0; i < n; i++)
    {
        if (fr[i] != -1)
            printf ("\n%d\t%d", a[i], fr[i]);
    }

}

int main()
{
    int n;
    printf("Enter the number of array elements: ");
    scanf ("%d", &n);
    int a[n];
    read (a, n);
    display (a, n);
    frequency (a, n);
    return 0;
}

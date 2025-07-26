#include <stdio.h>

int fact (int n)
{
    int res;
    if (n >= 1)
        res =  n * fact (n - 1);
    else
        res = 1;
    return res;
}

int main()
{
    int n, res;
    printf("Enter an integer: ");
    scanf ("%d", &n);
    res = fact (n);
    printf ("\n%d! = %d\n", n, res);
    return 0;
}

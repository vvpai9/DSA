#include <stdio.h>

int reverse(int x)
{
    long int c;
    for (c = 0; x != 0; x = x / 10) {
        if (c > 2147483647 || c < -2147483648)
            return 0;
        c = (c * 10) + (x % 10);
    }
    return c;
}

int main()
{
    printf("Reverse: %d", reverse (1534236469));
    return 0;
}

#include <stdio.h>
#include <math.h>

double rad_to_deg (double rad)
{
    return rad * (180.0 / M_PI);
}

int main()
{
    printf("sin 90 = %lf", sine(rad_to_deg (M_PI / 2)));
    return 0;
}

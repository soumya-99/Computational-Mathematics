#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// #define f(x) (pow(x, 3) + (3 * x) - 5)
#define f(x) ((2 * x) - (3 * sin(x)) - 5)
// #define f(x) ((x*exp(x))-cos(x))
// #define f(x) ((4 * pow(x, 3)) - 2 *1 x - 6)

int main()
{
    float a = 0, b = 0, c, c_prev, error = 0;
    int i = 0;
    printf("Enter the Intervals (2 Numbers Required): ");
    scanf("%f %f", &a, &b);
    if ((f(a) * f(b)) > 0)
    {
        printf("Invalid Interval Input!!!\n");
        exit(1);
    }
    else if (f(a) == 0 || f(b) == 0)
    {
        printf("The root of the equation is one of the intervals.\nThe Root is: %4.3f\n", f(a) == 0 ? a : b);
        exit(0);
    }
    printf("Iter.\ta\tb\tc\tf(c)\tError\n");
    do
    {
        sleep(1);
        c_prev = c;
        c = (b - ((b - a) / (f(b) - f(a))) * f(b));
        printf("%2d\t%4.3f\t%4.3f\t%4.3f\t%4.3f\t", i++, a, b, c, f(c));
        if (f(c) == 0)
        {
            printf("The root of the equation is: %4.3f\n", c);
        }
        else if (f(c) < 0)
        {
            a = c;
        }
        else
        {
            b = c;
        }
        error = fabs(c - c_prev);
        if (i == 1)
        {
            printf("----\n");
        }
        else
        {
            printf("%4.3f\n", error);
        }
    } while (error > 0.0005);
    printf("The Approximate root is: %4.3f\n", c);
    return 0;
}
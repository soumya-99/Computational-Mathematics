#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// #define f(x) ((3 * x) - cos(x) - 1)
// #define fd(x) (3 - sin(x))

// #define f(x) (pow(x, 3) - (3 * x) + 1)
// #define fd(x) ((3 * pow(x, 2)) - 3)


#define f(x) (x * x * x - 3 * x + 1)
#define fd(x) (x * x - 3)

int main()
{
    float a = 0.0, b = 0.0, c_prev, c, error = 0.0;
    int i = 0;
    printf("-----------------\n");
    printf("Newton Raphson Method\n");
    printf("-----------------\n");
    printf("Enter two intervals: ");
    scanf("%f %f", &a, &b);

    if (f(a) == 0)
    {
        printf("The root is: %4.3f\n", a);
        exit(1);
    }
    else if ((f(a) * f(b)) > 0)
    {
        printf("Invalid Interval!!!\n");
        exit(0);
    }

    printf("Iter.\ta\tc\tError\n");

    do
    {
        c_prev = c;
        c = (a - (f(a) / fd(a)));

        printf("%2d\t%4.3f\t%4.3f\t", i++, a, c);
        a = c;

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

    printf("The approximate root is: %4.3f\n", c);
    return 0;
}
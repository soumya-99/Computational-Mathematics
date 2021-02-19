#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define f1(y, z) (3 + (5 * y) + (2 * z)) / 10
#define f2(x, z) (3 + (4 * x) + (3 * z)) / 10
#define f3(x, y) (-3 - x - (6 * y)) / 10

int main()
{
    float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, error1, error2, error3, errorPeak;
    int i = 0;
    printf("Enter peak limit of error: ");
    scanf("%f", &errorPeak);

    printf("Iter.\tx\ty\tz\terrorX\terrorY\terrorZ\n");
    do
    {
        x1 = f1(y0, z0);
        y1 = f2(x0, z0);
        z1 = f3(x0, y0);
        printf("%d\t%3.4f\t%3.4f\t%3.4f\t", i++, x1, y1, z1);

        /* Error */
        error1 = fabs(x0 - x1);
        error2 = fabs(y0 - y1);
        error3 = fabs(z0 - z1);

        if (i == 1){
            printf("----\t----\t----\n");
        } else {
            printf("%3.4f\t%3.4f\t%3.4f\n", error1, error2, error3);
        }

        /* Set value for next iteration */
        x0 = x1;
        y0 = y1;
        z0 = z1;

    } while (error1 > errorPeak && error2 > errorPeak && error3 > errorPeak);

    printf("Solution is: x=%3.4f, y=%3.4f and z=%3.4f\n", x1, y1, z1);
    return 0;
}
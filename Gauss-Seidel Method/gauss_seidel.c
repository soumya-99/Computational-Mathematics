#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main()
{
    int i = 0;
    float x = 0.0, y = 0.0, z = 0.0, x_prev, y_prev, z_prev, a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3, errorX = 0.0, errorY = 0.0, errorZ = 0.0, errorPeak;
    printf("Enter a1, b1, c1 and d1 respectively: ");
    scanf("%f %f %f %f", &a1, &b1, &c1, &d1);
    printf("Enter a2, b2, c2 and d2 respectively: ");
    scanf("%f %f %f %f", &a2, &b2, &c2, &d2);
    printf("Enter a3, b3, c3 and d3 respectively: ");
    scanf("%f %f %f %f", &a3, &b3, &c3, &d3);
    printf("Enter Peak Limit of Errors: ");
    scanf("%f", &errorPeak);

    if ((fabs(a1) > (fabs(b1) + fabs(c1))) && (fabs(b2) > (fabs(a2) + fabs(c2))) && (fabs(c3) > (fabs(a3) + fabs(b3))))
    {
        printf("Iter.\tx\ty\tz\t\tErrorX\tErrorY\tErrorZ\n");
        do
        {
            x_prev = x;
            y_prev = y;
            z_prev = z;
            x = ((d1 - (b1 * y) - (c1 * z))/a1);
            y = ((d2 - (a2 * x) - (c2 * z))/b2);
            z = ((d3 - (a3 * x) - (b3 * y))/c3);

            printf("%d\t%4.5f\t%4.5f\t%4.5f\t", i++, x, y, z);

            errorX = fabs(x - x_prev);
            errorY = fabs(y - y_prev);
            errorZ = fabs(z - z_prev);

            if (i == 1)
            {
                printf("----\t----\t----\n");
            }
            else
            {
                printf("%4.5f\t%4.5f\t%4.5f\n", errorX, errorY, errorZ);
            }

        } while (errorX > errorPeak && errorY > errorPeak && errorZ > errorPeak);
    }
    printf("The final values of x, y and z is: %4.5f, %4.5f, %4.5f", x, y, z);
    return 0;
}
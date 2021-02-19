#include "stdio.h"

#define dydx(x, y) (x * x + y * y)

int main()
{
    double toFindX, x0, h, k1 = 0, k2 = 0, y0, k = 0, nextY = 0, x, lastY;
    printf("-----------------\n");
    printf("Runge Kutta 2nd Order\n");
    printf("-----------------\n");

    printf("Enter the value for x0: ");
    scanf("%lf", &x0);
    printf("Enter the value for y0: ");
    scanf("%lf", &y0);
    printf("Enter the value for x to find: ");
    scanf("%lf", &toFindX);
    printf("Enter the value for h (height gap): ");
    scanf("%lf", &h);
    x = toFindX;

    lastY = y0;
    while (1)
    {
        k1 = h * dydx(x0, y0);
        k2 = h * dydx(x0 + h, y0 + k1);
        k = (k1 + k2) / 2;
        nextY = lastY + k;
        lastY = nextY;

        x0 = x0 + h;
        if (x0 >= toFindX)
            break;
    }

    printf("Hence, the value of y(%lf) = %4.6lf", x, nextY);

    return 0;
}

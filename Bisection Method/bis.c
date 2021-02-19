#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define f(x) (pow(x, 3) - (2 * x) - 3)
// #define f(x) ((2 * x) - (3 * sin(x)) - 5)

int main()
{
    float a = 0, b = 0, c, c_prev, error = 0;
    int i = 0;
    printf("-----------------\n");
    printf("Bisection Method\n");
    printf("-----------------\n");
    printf("Enter the Intervals (2 Numbers Required): ");
    scanf("%f %f", &a, &b);
    if ((f(a) * f(b)) > 0)
    {
        printf("Invalid Interval Input!!!\n");
        exit(1);
    }
    else if (f(a) == 0 || f(b) == 0)
    {
        printf("The root is one of the interval. Answer is: %4.6f", f(a) == 0 ? a : b);
        exit(0);
    }
    //For Table View
    printf("Iter.\ta\t\tb\t\tc\t\tf(c)\t\terror\n");
    do
    {
        sleep(1);
        c_prev = c;
        c = (a + b) / 2; //for bisection method
        printf("%2d\t%4.6f\t%4.6f\t%4.6f\t%4.6f\t", i++, a, b, c, f(c));
        if (f(c) == 0)
        {
            printf("Root is : %4.6f\n", c);
        }
        else if (f(c) < 0)
        {
            a = c;
        }
        else
        {
            b = c;
        }
        //Error Calculating
        error = fabs(c - c_prev);
        if (i == 1)
        {
            printf("----\n");
        }
        else
        {
            printf("%4.6f\n", error);
        }
    } while (error > 0.0005);
    printf("Now, The Approximate Root is: %4.6f\n", c);
    return 0;
}
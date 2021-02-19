#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define f(x) (1 / (1 + pow(x, 2)))

int main()
{
    float lowerLim, upperLim, h;
    float answerVal = 0.0, valY = 0.0, y0 = 0.0, yN = 0.0, sumEven = 0.0, sumOdd = 0.0, oddY = 0.0, evenY = 0.0;
    int i;
    printf("----------------\n");
    printf("Simpson's 1/3 Rule\n");
    printf("----------------\n");
    printf("Enter the lower limit & upper limit of the integral: ");
    scanf("%f %f", &lowerLim, &upperLim);
    printf("Enter the value of 'h': ");
    scanf("%f", &h);
    for (i = lowerLim; i <= upperLim; i++)
    {
        valY = f(i);
        if (i == lowerLim)
        {
            y0 = valY;
        }
        if (i == upperLim)
        {
            yN = valY;
        }
        if (i != lowerLim || upperLim)
        {
            if (i % 2 == 0)
            {
                evenY = valY;
                sumEven = sumEven + evenY;
            }
            else
            {
                oddY = valY;
                sumOdd = sumOdd + oddY;
            }
        }
    }
    answerVal = ((h / 3) * (4 * (sumOdd) + 2 * (sumEven)));
    printf("The value of the integral is : %f", answerVal);
    return 0;
}
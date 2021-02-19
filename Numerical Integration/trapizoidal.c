#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define f(x) (1 / (1 + pow(x, 2)))

int main()
{
    float lowerLim, upperLim, h;
    float answerVal = 0.0, valY = 0.0, y0 = 0.0, yN = 0.0, sum = 0.0;
    int i;
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
            sum = sum + valY;
        }
    }
    answerVal = ((h / 2) * ((y0 + yN) + (2 * (sum))));
    // answerVal = (h / 2) * ((y0 + yN) + 2 * (sum));
    printf("The value of the integral is : %f", answerVal);
    return 0;
}
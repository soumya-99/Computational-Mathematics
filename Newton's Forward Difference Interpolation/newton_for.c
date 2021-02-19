#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main()
{
    float x[20], y[20], x0, y0, x, dY;
    int interval, terms, i, j;
    printf("Enter how many duo terms you want to input: ");
    scanf("%d", &terms);
    //input of x & y

    printf("Enter the x, y terms: ");
    for (i = 0; i < terms; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }
    printf("Enter the value of x for which you want to find 'y = f(x)': ");
    scanf("%f", &x);
    interval = x[1] - x[0];
    //difference table

    for (i = 0; i < terms - 1; i++) {
        dY = y[i+1] - y[i];
    }

}
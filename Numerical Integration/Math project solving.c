#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, n, i, h;
	float x, y, sum = 0, area = 0;
	int j = 0;
	printf("\nEnter the upper limit and lower limit: ");
	scanf("%f%f", &b, &a);
	printf("\nEnter the width of each trapizium; ");
	scanf("%f", &h);
	x = a;
	n = ((b - a) / h);
	printf("\nThe total number of points will be n=%f", n);
	printf("\n=======================================");
	getch();
	printf("\nThe points are: ");
	for (x = a; x <= b; x += h)
	{
		y = (pow((9 - pow(x, 2)), 0.5)) * 0.66666666;
		printf("\n x%d = %f		 |		y%d = %f", j, x, j, y);
		sum = sum + y;
		j++;
	}
	printf("\n=======================================");
	printf("\nThe sum is: %f", sum);
	area = ((0.5 * h) * (2 * sum));
	printf("\n=======================================");
	printf("\ni.e area of the given curve is: %f", area);
	return 0;
}

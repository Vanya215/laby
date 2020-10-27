// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <cmath>

int main()
{
	int n = 1;
	long long x;
	while(1)
	{
		x = 7 * pow(n, 3) + 81 * pow(n, 2) - pow(10, 6);
		if (x >= 0)
			break;
		else
			n++;
	}
	printf("%d", --n);
	return 0;
}
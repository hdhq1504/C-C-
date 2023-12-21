#include <stdio.h>
#include <limits.h>

// Iterative Approach
void print3Largest(int a[], int n)
{
	int first, second, third;
	if(n < 3)
	{
		printf("Invalid input");
		return;
	}
	third = first = second = INT_MIN;
	for(int i = 0; i < n; i++)
	{
		if(a[i] > first)
		{
			third = second;
			second = first;
			first = a[i];
		}
		else if(a[i] > second)
		{
			third = second;
			second = a[i];
		}
		else if(a[i] > third)
			third = a[i];
	}
	printf("\nThree largest elements are %d %d %d\n\n", first, second, third);
}

int main()
{
	int a[] = {10, 4, 3, 50, 23, 90};
	int n = sizeof(a) / sizeof(a[0]);
	print3Largest(a, n);
	return 0;
}
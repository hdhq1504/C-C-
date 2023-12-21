#include <stdio.h>

void findMissing(int a[], int n)
{
	int temp[n+1];
	for(int i = 0; i <= n; i++)
	{
		temp[i] = 0;
	}
	
	for(int i = 0; i < n; i++)
	{
		temp[a[i] - 1] = 1;
	}
	
	int ans;
	for(int i = 0; i <= n; i++)
	{
		if(temp[i] == 0)
			ans = i+1;
	}
	printf("A missing element is %d\n", ans);
}

int main()
{
	int a[] = { 1, 3, 7, 5, 6, 2 };
	int n = sizeof(a) / sizeof(a[0]);
	findMissing(a, n);
	return 0;
}

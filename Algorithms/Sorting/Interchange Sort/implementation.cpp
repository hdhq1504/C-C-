#include <stdio.h>

void Nhap(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Nhap gia tri a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}

void Xuat(int a[], int n)
{
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void Swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void interchangeSort_Ascending(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				Swap(a[i], a[j]);
			}
		}
	}
}

void interchangeSort_Descending(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				Swap(a[i], a[j]);
			}
		}
	}
}

int main()
{
	int a[100];
	int n;
	
	printf("Nhap n: ");
	scanf("%d", &n);
	Nhap(a, n);
	
	interchangeSort_Ascending(a, n);
	Xuat(a, n);
	interchangeSort_Descending(a, n);
	Xuat(a, n);
	
	return 0;
}

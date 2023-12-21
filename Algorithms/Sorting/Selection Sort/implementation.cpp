#include <stdio.h>

void NhapMang(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap gia tri a[%d]: ", i);
		scanf("%d", &a[i]);
	}
}

void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void selection_Sort(int a[], int n)
{
	int min, i, j;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		Swap(a[min], a[i]);
	}
}

int main()
{
	int a[1000];
	int n;
	printf("Nhap n: ");
	scanf("%d", &n);
	NhapMang(a, n);
	selection_Sort(a, n);
	XuatMang(a, n);
	return 0;
}

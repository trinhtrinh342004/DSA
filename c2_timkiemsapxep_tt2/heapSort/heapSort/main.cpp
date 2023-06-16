#include <iostream>

using namespace std;

void heapify(int* a, int k, int n)
{
	int j = 2 * k + 1;
	while (j < n)
	{
		if (j + 1 < n && a[j] < a[j + 1])
			j = j + 1;
		if (a[k] <= a[j])
			return;
		swap(a[k], a[j]);
		k = j; j = 2 * k + 1;
	}
}

void buildHeap(int* a, int n)
{
	int i;
	i = n / 2 - 1;
	while (i >= 0)
	{
		heapify(a, i, n);
		i--;
	}
}

void heapSort(int* a, int n)
{
	buildHeap(a, n);
	while (n > 0)
	{
		n = n - 1;
		swap(a[0], a[n]);
		heapify(a, 0, n);
	}
}

int main()
{

	int a[] = { 8, 2, 1, 9, 4, 5, 7, 6, 3 };
	int n = sizeof(a) / sizeof(a[0]);

	heapSort(a, n);

	cout << "Mang sau khi sap xep la: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}
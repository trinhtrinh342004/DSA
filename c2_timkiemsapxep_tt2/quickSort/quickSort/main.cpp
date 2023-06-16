#include <iostream>

using namespace std;

void QuickSort(int a[], int left, int right)
{
	int i, j, x;
	x = a[(left + right) / 2];
	i = left;
	j = right;
	while (i < j)
	{
		while (a[i] > x)
			i++;
		while (a[j] < x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}

int main()
{
	int A[] = { 8, 2, 1, 9, 4, 5, 7, 6, 3 };
	int n = sizeof(A) / sizeof(A[0]);

	cout << "Mang truoc khi sap xep: ";
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";

	QuickSort(A, 0, n - 1);

	cout << "\nMang sau khi sap xep: ";
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";

	return 0;
}
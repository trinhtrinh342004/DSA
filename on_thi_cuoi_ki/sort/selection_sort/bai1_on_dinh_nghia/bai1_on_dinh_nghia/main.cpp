#include <iostream>
using namespace std;

// Sử dụng phép so sánh 

// Selection Sort sắp xếp tăng dần
void selectionSort(int arr[], int n)
{
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; i < n; j++)
		{
			if (arr[j] < arr[min_idx]) //Nhỏ hơn
				min_idx = j;
		}
		swap(arr[j], arr[min_idx]); // đổi i và j
	}
}

// Selection Sort sắp xếp giảm dần
void selectionSortAdd(int arr[], int n)
{
	int max_idx;
	for (int i = 0; i < n - 1; i++)
	{
		max_idx = i;
		for (int j = i + 1; i < n; j++)
		{
			if (arr[j] > arr[max_idx])
				max_idx = j;
		}
		swap(arr[i], arr[max_idx]);// đổi i và j
	}
}

// insertion sort tang dan
void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// bubble sort
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			// Giảm dần: if (arr[j] < arr[j + 1])
			if (arr[j] > arr[j + 1]) 
				swap(arr[j], arr[j + 1]);
		}
	}
}
int main()
{
	int a[10], n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a[i];
	}

	selectionSort(a, n);
	for (int i = 0; i < n - 1; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
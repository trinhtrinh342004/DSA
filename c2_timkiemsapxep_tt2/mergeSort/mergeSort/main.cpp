#include <iostream>

using namespace std;

void Merge(int A[], int left, int q, int right)
{
    int* temp = new int[right - left + 1];
    int i = left, j = q + 1, k = 0;

    while (i <= q && j <= right)
    {
        if (A[i] > A[j])
        {
            temp[k] = A[i];
            i++;
        }
        else
        {
            temp[k] = A[j];
            j++;
        }
        k++;
    }

    while (i <= q)
    {
        temp[k] = A[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        temp[k] = A[j];
        j++;
        k++;
    }

    for (int p = 0; p < k; p++)
        A[left + p] = temp[p];

    delete[] temp;
}

void MergeSort(int A[], int left, int right)
{
    if (left < right)
    {
        int q = (left + right) / 2;
        MergeSort(A, left, q);
        MergeSort(A, q + 1, right);
        Merge(A, left, q, right);
    }
}

int main()
{
    int A[] = {8, 2, 1, 9, 4, 5, 7, 6, 3};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    MergeSort(A, 0, n - 1);

    cout << "\nMang sau khi sap xep: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
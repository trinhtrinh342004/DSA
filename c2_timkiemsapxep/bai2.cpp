#include <iostream>
#include <algorithm>
using namespace std;

// Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

// Hàm tìm kiếm phần tử x trên mảng A sử dụng tìm kiếm nhị phân
int searchElement(int A[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == x) {
            return mid;
        }
        if (A[mid] < x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

// Hàm nhập mảng
void inputArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Hàm xuất mảng
void outputArray(int arr[], int n) {
    cout << "Cac phan tu trong mang la: ";
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void findElement(int arr[], int n) {
    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;
    int result = searchElement(arr, n, x);
    if (result == -1)
        cout << "Khong tim thay " << x << " trong mang" << endl;
    else
        cout << x << " xuat hien tai vi tri " << result + 1 << endl;
}

int main() {
    int n, x;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    int arr[n];
    inputArray(arr, n);
    outputArray(arr, n);
    findElement(arr, n);
}

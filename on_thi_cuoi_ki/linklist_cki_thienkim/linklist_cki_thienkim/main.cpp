#include <iostream>
#include <string>
using namespace std;


 struct MatHang
{
	int MaSP = 0;
	string TenSP;
	int SoLuong = 0;
	int NamSX = 0;
	int DonGia = 0;
};

struct Node
{
	MatHang data;
	Node* pNext = NULL;
};

struct List
{
	Node* pHead;
	Node* pTail;
};

Node* createNode(MatHang x)
{
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}

void emptyList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

void addTail(List& l, Node* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else 
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void inputList(List& l, int& n)
{
	MatHang x;
	emptyList(l);
	cout << "Nhap so luong mat hang: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin mat hang thu " << i + 1 << ":" << endl;
		cout << "Ma san pham: ";
		cin >> x.MaSP;
		cin.ignore();
		cout << "Ten san pham: ";
		getline(cin, x.TenSP);
		cout << "So luong: ";
		cin >> x.SoLuong;
		cout << "Nam san xuat: ";
		cin >> x.NamSX;
		cout << "Don gia: ";
		cin >> x.DonGia;

		Node* p = createNode(x);
		addTail(l, p);
	}
}

void ouputList(List l)
{
	Node* p = l.pHead;
	cout << "Danh sach san pham la: " << endl;
	while (p != NULL)
	{
		cout << p->data.MaSP << endl;
		cout << p->data.TenSP << endl;
		cout << p->data.SoLuong << endl;
		cout << p->data.NamSX << endl;
		cout << p->data.DonGia << endl;
		p = p->pNext;
	}
}

Node* findMax(List l)
{
	if (l.pHead == NULL)
		return NULL;
	Node* p = l.pHead;
	Node* max = p;
	while (p != NULL)
	{
		if (p->data.DonGia > max->data.DonGia)
			max = p;
		p = p->pNext;
	}
	return max;
}

void swap(MatHang& a, MatHang& b)
{
	MatHang temp = a;
	a = b;
	b = temp;
}

void sortList(List& l)
{
	if (l.pHead == NULL || l.pHead->pNext == NULL)
		return;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		for (Node* q = p->pNext; q != NULL; q = q->pNext)
		{
			if (p->data.MaSP > q->data.MaSP)
				swap(p->data, q->data);
		}
	}
}
int main()
{
	List ds;
	int select, n;
	Node* maxProduct;

	emptyList(ds);

	do
	{
		cout << "----- MENU -----" << endl;
		cout << "1. Nhap danh sach mat hang" << endl;
		cout << "2. Tim mat hang co gia cao nhat" << endl;
		cout << "3. Sap xep mat hang theo ma san pham" << endl;
		cout << "0. Thoat" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> select;

		switch (select)
		{
		case 1:
			inputList(ds, n);
			ouputList(ds);
			break;
		case 2:
			maxProduct = findMax(ds);
			if (maxProduct != NULL)
			{
				cout << "Mat hang cao nhat" << endl;
				cout << maxProduct->data.TenSP << endl;
			}
			else
				cout << "danh sach rong";
			break;
		case 3:
			sortList(ds);
			cout << "sap xep: ";
			ouputList(ds);
			break;
		case 0:
			cout << "Ket thuc chuong trinh." << endl;
			break;

		default:
			cout << "Lua chon khong hop le. Moi chon lai." << endl;
			break;
		}

		cout << endl;
	} while (select != 0);
	return 0;
}
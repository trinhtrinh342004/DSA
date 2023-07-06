#include <iostream>
#include <string>
using namespace std;

struct CHTienLoi
{
	string ten;
	int soMatHangBan;
	int tyLeDanhGiaMucDoTot;
	float kcDenCuaHang;
};

typedef struct node
{
	CHTienLoi data;
	node* pNext;
}Node;

typedef struct list
{
	Node* pHead= NULL;
	Node* pTail=NULL;
}List;

void addTail(List& l, const CHTienLoi& tl)
{
	Node* p = new Node();
	p->data = tl;
	p->pNext = NULL;
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void NhapDanhSach(List& l, int m)
{
	for (int i = 0; i < m; i++)
	{
		// Nhập thông tin cua hang
		CHTienLoi tl;
		cout << "Nhap cua hang thu " << i + 1 << endl;
		cout << "Nhap ten cua hang: ";
		cin.ignore();
		getline(cin, tl.ten);
		cout << "Nhap so mat hang: ";
		cin >> tl.soMatHangBan;
		cout << "Nhap ty le danh gia cua khach hang: ";
		cin >> tl.tyLeDanhGiaMucDoTot;
		cout << "Nhap khoang cach den cua hang: ";
		cin >> tl.kcDenCuaHang;
		addTail(l, tl);
	}
}

int main()
{
	CHTienLoi tl; List l;
	cout << "Nhap so luong cua hang: ";
	int m; cin >> m;
	NhapDanhSach(l, m);
	return 0;
}
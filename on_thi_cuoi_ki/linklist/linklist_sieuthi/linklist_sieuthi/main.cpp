#include <iostream>
#include <string>
using namespace std;

// Câu a) Khai báo cấu dslk đơn để quản lí SIÊU THỊ
struct SieuThi
{
	int maST;
	char tenST[50];
	int namThanhLap;
	int soThanhVien;
};

typedef struct node
{
	SieuThi data;
	node* pNext;
}Node;

typedef struct list
{
	Node* pHead= NULL;
	Node* pTail=NULL;
}List;
// Câu a) tới đây là đủ

void addHead(List& l, const SieuThi& st)
{
	Node* p = new Node();
	if (p == NULL)
		return;
	p->data = st;
	p->pNext = NULL;
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void addTail(List& l, const SieuThi& st)
{
	Node* p = new Node();
	if (p == NULL)
		return;
	p->data = st;
	p->pNext = NULL;
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void nhap(List& l, int& n)
{
	SieuThi st;
	cout << "Nhap so luong sieu thi: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap thong tin sieu thi thu " << i + 1 << endl;
		cout << "\nNhap ma sieu thi: ";
		cin >> st.maST;
		cout << "\nNhap ten sieu thi: ";
		cin >> st.tenST;
		cout << "\nNhap nam thanh lap: ";
		cin >> st.namThanhLap;
		cout << "\nNhap so luong nhan vien: ";
		cin >> st.soThanhVien;
		addHead(l, st);
	}
}

// Câu b) Viết hàm liệt kê các siêu thị có thời gian hoạt động >10 năm
void lietKeTren10Nam(List l)
{
	Node* p;
	cout << "Nhap so nam hien tai: ";
	int n; cin >> n;
	if (l.pHead == NULL)
		cout << "Danh sach rong!\n";
	else
	{
		p = l.pHead;
		while (n - p->data.namThanhLap > 10)
		{
			cout << p->data;
			p->pNext;
		}
	}
}



// Câu c) Viết hàm xóa các siêu thị có số lượng nhân viên <100 người
void removeSieuThi(List& l)
{
	Node* p = l.pHead;
	Node* prev = NULL;

	while (p != NULL)
	{
		if (p->data.soThanhVien < 100)
		{
			if (p == l.pHead)
			{
				l.pHead = p->pNext;
				delete p;
				p = l.pHead;
			}
			else
			{
				prev->pNext = p->pNext;
				if (p == l.pTail)
					l.pTail = prev;
				delete p;
				p = prev->pNext;
			}
		}
		else
		{
			prev = p;
			p = p->pNext;
		}
	}
}

int main()
{
	SieuThi st;
	List l;
	int n;
	nhap(l, n);
	lietKeTren10Nam(l);
	removeSieuThi(l) ;
	return 0;
}
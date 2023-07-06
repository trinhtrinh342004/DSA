#include <iostream>
#include <string>
using namespace std;

//Cấu a) Định nghĩa cấu trúc dữ liệu lưu thông tin
struct NhaHang
{
	string ten= "";
	int tyLeDG= 0;
	double khoangCach = 0;
};

typedef struct node
{
	NhaHang data;
	node* pNext = NULL;
}Node;

typedef struct list
{
	Node* pHead;
	Node* pTail;
}List;

// Câu b) Nhập vào 10 nhà hàng bằng cách thêm vào cuối danh sách
//Khởi tạo node
Node* createNode(NhaHang nh)
{
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->data = nh;
	p->pNext = NULL;
	return p;
}
//Khởi tạo list
void initList(List& l)
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

void Nhap(List& l, int &n)
{
	NhaHang nh;
	cout << "Nhap so nha hang!\n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin nha hang thu " << i + 1 << ": ";
		cout << "\nNhap ten: ";
		cin.ignore();
		getline(cin, nh.ten);
		cout << "\nNhap ty le danh gia muc do tot: ";
		cin >> nh.tyLeDG;
		cout << "\nNhap khoang cach tu trung tam den thanh pho: ";
		cin >> nh.khoangCach;

		Node* p = createNode(nh);
		addTail(l,p);
	}
}

// Câu c) Sắp xếp tỷ lệ đánh giá mức độ tốt giảm dần và tăng khoảng cách tới nhà hàng
void swap(NhaHang& a, NhaHang& b)
{
	NhaHang temp = a;
	a = b;
	b = temp;
}

void SapXep(List& l)
{
	if (l.pHead == NULL || l.pHead->pNext == NULL)
		return;
	for (Node* p = l.pHead; p != NULL; p = p->pNext)
	{
		for (Node* q = p->pNext; q != NULL; q = q->pNext)
		{
			if (p->data.tyLeDG < q->data.tyLeDG)
				if (p->data.khoangCach > q->data.khoangCach)
					swap(p->data, q->data);
		}
	}
}

// Làm thêm 
//1. Tìm tỷ lệ đánh giá thấp nhẩt
Node* findMin(List l)
{
	if (l.pHead == NULL)
		return NULL;
	Node* p = l.pHead;
	Node* min = p;
	while (p != NULL)
	{
		if (p->data.tyLeDG < min->data.tyLeDG)
		{
			min = p;
		}
		p = p->pNext;
	}
	return min;
}

//2. Hàm xóa cửa hàng có khoảng cách >10km

// Hàm xuất
void outputList(List l)
{
	Node* p = l.pHead;
	cout << "Danh sach cua hang " << endl;
	while (p != NULL)
	{
		cout << p->data.ten << endl;
		cout << p->data.tyLeDG << endl;
		cout << p->data.khoangCach << endl;
		p = p->pNext;
	}
}

int main()
{
	List ds = { NULL, NULL };
	int select, n;
	Node* minProduct;

	do
	{
		cout << "----- MENU -----" << endl;
		cout << "1. Nhap danh sach nha hang" << endl;
		cout << "2. Sap xep" << endl;
		cout << "3. Tìm ty le thanp nhat" << endl;
		cout << "0. Thoat" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> select;

		switch (select)
		{
		case 1:
			Nhap(ds, n);
			break;
		case 2:
			SapXep(ds);
			cout << "sap xep: ";
			outputList(ds);
			break;
		case 3:
			minProduct = findMin(ds);
			if (minProduct != NULL)
			{
				cout << "Ty le thap nhat " << endl;
				cout << minProduct->data.ten << endl;
			}
			else
				cout << " danh sach rong";
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

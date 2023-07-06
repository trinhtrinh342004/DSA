#include <iostream>
#include <string>
using namespace std;

// Câu a) Khai báo cấu trúc lưu thông tin sinh viên theo mô tả trên
struct SinhVien
{
	string MSSV = "";
	string hoTen = "";
	float dtb = 0;
	char loaiTN;
};

typedef struct node
{
	SinhVien data;
	node* pNext = NULL;
}Node;

typedef struct list
{
	Node* pHead = NULL;
	Node* pTail = NULL;
}List;

Node* create(SinhVien sv)
{
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->data = sv;
	p->pNext = NULL;
	return p;
}


// Câu b) Viết hàm nhập danh sách sinh viên vào đầu dah sách
void addHead(List& l, Node* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

// Câu c) Viết hàm xếp loại tốt nghiệp cho sinh viên 
string XepLoai(float DTB)
{
	if (DTB <= 3.6) return "Yeu";
	if (DTB >= 5 && DTB < 6.5) return "Trung binh";
	if (DTB >= 6.5 && DTB < 7) return "Trung binh kha";
	if (DTB >= 7 && DTB < 8) return "Kha";
	if (DTB >= 8 && DTB < 9) return "Gioi";
	return "Xuat sac";
}



void SapXepTheoDTBVaXepLoai(List& l)
{
	Node* p; 
	for (p = l.pHead; p != NULL; p = p->pNext)
		cout << p->data.MSSV << " " << p->data.hoTen << " " << p->data.dtb << XepLoai(p->data.loaiTN) << endl;
}

// câu d) Viết hàm xóa sv xếp loại Y ra khỏi danh sách
void remove(List& l)
{
	Node* prev = NULL;
	Node* c = l.pHead;
	while (c != NULL)
	{
		if (c->data.loaiTN == 'Y')
		{
			if (prev == NULL) // nếu sv là phần tử đầu ds
			{
				l.pHead = c->pNext;
				if (c == l.pTail)  // nếu sv là phần tử cuối
					l.pTail = NULL;
				delete c;
				c = l.pHead;
			}
			else // sv ko đầu ds
			{
				prev->pNext = c->pNext;
				if (c == l.pTail) // nếu sv là phần tử cuối ds
					l.pTail = prev;
				delete c;
				c = prev->pNext;
			}
		}
		else
		{
			prev = c;
			c = c->pNext;
		}
	}
}

int main()
{

	return 0;
}
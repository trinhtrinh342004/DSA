#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node
typedef struct node 
{
	int data; 
	struct node* pNext;
}Node;

// Định nghĩa cấu trúc list
typedef struct list
{
	Node* pHead; // Lưu địa chỉ node đầu tiên trong ds
	Node* pTail; // Lưu địa chỉ của node cuối cùng trong ds
}List;

// Tạo node
Node* createNode(int x)
{
	Node* p;
	p = new Node; // Cấp phát bộ nhớ cho phần tử
	if (p == NULL) return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}

// Khởi tạo list
void initList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

// Thêm node vào đầu danh sách
void addHead(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

// Thêm node vào cuối ds
void addTail(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

// Thêm node p vào sau node q cho trước
int addNodeAfterQ(List& l, Node* p, Node* q)
{
	if (q == NULL)
		return 0;
	p->pNext = q->pNext;
	q->pNext = p;
	if (l.pTail == q)
		l.pTail = p;
	return 1;
}

// Thêm node p vào sau node có giá trị x
Node* findNodeX(List l, int x)
{
	Node* p;
	p = l.pHead;
	while (p != NULL && p -> data != x)
	{
		p = p->pNext;
	}
	return p;
}

int addNodeAfterX(List& l, Node* p, int x)
{
	Node* q;
	q = findNodeX(l, x);
	if (q != NULL)
		addNodeAfterQ(l, p, q);
	else
		return 0;
	return 1;
}

// In ds
void printList(List l)
{
	Node* p;
	p = l.pHead;
	while (p != NULL)
	{
		cout << p-> data << " ";
		p = p->pNext;
	}
	/*
	for (Node* p = l.pHeap; p!=NULL; p = p -> pNext)
	  cout << p -> data << " ";
	  cout << "\n";
	*/
	cout << "\n";
}



int main()
{
	List l; initList(l);
	Node* p;
	int x, y;

	cout << "***********************************\n";
	cout << "1. Them node vao dau ds.\n";
	cout << "2. Them node vao cuoi ds.\n";
	cout << "3. In ds.\n";
	cout << "4. Tim node co gia tri x.\n";
	cout << "5. Them node p vao sau node q co gia tri x.\n";
	cout << "0. Thoat chuong trinh.\n";
	cout << "***********************************\n";

	int select;
	do
	{
		cout << "Chon chuc nang thuc hien: ";
		cin >> select;
		switch (select)
		{
		case 0:
			cout << "Tam biet";
			break;
		case 1:
			cout << "Nhap gia tri cua node can them vao dau: ";
			cin >> x;
			p = createNode(x);
			addHead(l, p);
			break;
		case 2:
			cout << "Nhap gia tri cua node can them vao cuoi: ";
			cin >> x;
			p = createNode(x);
			addTail(l, p);
			break;
		case 3:
			cout << "DS lien ket: ";
			printList(l);
			break;
		case 4:
			cout << "Nhap gia tri node can tim: ";
			cin >> x;
			p = findNodeX(l, x);
			if (p == NULL)
				cout << "Khong tim thay gia tri " << x << "\n";
			else
				cout << "Tim thay node gia tri " << x << "\n";
			break;
		case 5:
			cout << "Nhap gia tri node q can tim: ";
			cin >> x;
			cout << "Nhap gia tri cho node p can chen: ";
			cin >> y;
			p = createNode(y);
			if (addNodeAfterX(l, p, x) == 1)
				cout << "Them thanh cong!\n";
			else 
				cout << "Khong tim thay node q co gia tri " << x << "\n";
			break;
		default:
			break;
		}
	} while (select);
	return 0;
}
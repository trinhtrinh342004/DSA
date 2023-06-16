#include <iostream>
#include <list>
#define M 100 
using namespace std;

// Định nghĩa cấu trúc Node
typedef struct node
{
	int data;
	struct node* pNext;
}Node;

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


// Định nghĩa cấu trúc list
typedef struct list
{
	Node* pHead; // Lưu địa chỉ node đầu tiên trong ds
	Node* pTail; // Lưu địa chỉ của node cuối cùng trong ds
}List;

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
	while (p != NULL && p->data != x)
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
		cout << p->data << " ";
		p = p->pNext;
	}
	/*
	for (Node* p = l.pHeap; p!=NULL; p = p -> pNext)
	  cout << p -> data << " ";
	  cout << "\n";
	*/
	cout << "\n";
}

// Tạo HT
void initHash(List l[])
{
	for (int i = 0; i < M; i++)
		initList(l[i]);
}

// Tạo HF
int hashFunc(int key)
{
	return (key % M);
}

// thêm node vào bảng băm
void insertNode(List l[], int value)
{
	Node* p = createNode(value);

	int h = hashFunc(value);
	Node* current = l[h].pHead;
	Node* previous = NULL;

	while (current != NULL && current->data < value)
	{
		previous = current;
		current = current->pNext;
	}

	if (previous == NULL) // thêm vào đầu
		addHead(l[h], p);
	else if (current == NULL)
		addTail(l[h], p);
	else // thêm trước current
	{
		p->pNext = current;
		previous->pNext = p;
	}
}

void showHash(List l[])
{
	for (int i = 0; i < M; i++)
	{
		if (l[i].pHead != NULL)
		{
			cout << "BUCKET " << i << " : ";
			printList(l[i]);
		}
	}
}

//Tìm node vào bảng băm
Node* searchNode(List l[], int value)
{
	int h = hashFunc(value);
	Node* p = l[h].pHead;
	while (p != NULL && p->data != value)
		p = p->pNext;
	return p;
}

int main()
{
	List l[M];
	initHash(l);

	int select, value;
	cout << "...................................................\n";
	cout << "1. Them node vao bang bam.\n";
	cout << "2. Hien thi bang bam.\n";
	cout << "3. Tim gia tri cha cho truoc.\n";
	cout << "0. Tam biet!\n";
	cout << "...................................................\n";

	do
	{
		cout << "Chon chuc nang thuc hien: \n";
		cin >> select;
		switch (select)
		{
		case 0: 
			cout << "Tam biet!";
			break;
		case 1:
			cout << "Nhap gia tri them node vao bang bam: \n";
			cin >> value;
			insertNode(l, value);
			break;
		case 2:
			cout << "Bang bam: \n" << endl;
			showHash(l);
			break;
		case 3: 
			cout << "Tim node vao bang bam: \n";
			cin >> value;
			if (searchNode(l, value) == NULL)
				cout << "Khong tim thay node co gia tri " << value << endl;
			else
				cout << "Tim thay node co gia tri " << value << endl;
			break;
		default:
			break;
		}
	} while (select);

	return 0;
}

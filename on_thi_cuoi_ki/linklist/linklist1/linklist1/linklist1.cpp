#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
	string name;
	double gpa;
};

typedef struct node
{
	SinhVien data;
	struct node* pNext;
}Node;

typedef struct list
{
	Node* pHead;
	Node* pTail;
}List;

// Tao mot ds rong
void emptyList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

// Tao mot node
Node* createNode(SinhVien x)
{
	Node* p = new Node;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}

bool isEmpty(List& l)
{
	if (l.pHead = NULL)
		return true;
	return false;
}

// Them node vao dau danh sach
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

//Them node vao cuoi ds
void addTail(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		p->pNext = p;
		l.pTail = p;
	}
}

// Nhap ds sinh vien
void inputList(List& l, long& n)
{
	SinhVien x; Node* p;
	string t; n = 0;

	cout << "Nhap sinh vien! \n";
	do
	{
		cout << "Nhap sinh vien thu " << n + 1 << ": ";
		fflush(stdin);
		getline(cin, x.name);
		while (true)
		{
			cout << "Nhap gpa cua sv: ";
			cin >> x.gpa;
			if (x.gpa >= 0 && x.gpa <= 10)
				break;
			else
				cout << "Nhap lai! \n";
		}
		p = createNode(x);
		if (p != NULL)
			addTail(l, p);
		n++;
		cout << "Ban co muon tiep tuc khong {YES/NO): ";
		fflush(stdin);
		getline(cin, t);
		cout << "\n";
	} while (t != "NO");

	cout << "Nhap tu dong! \n";
	srand(time(0));
	n = 1 + rand() % 20;
	for (int i = 0; i < n; i++)
	{
		string s = to_string(1 + rand() % 30);
		x.name = "Sinh vien" + s;
		x.gpa = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 10));
		p = createNode(x);
		if (p != NULL)
			addHead(l, p);

	}
	cout << "Nhap tu dong hoan tat!\n";
}

bool removeHead(List& l, double& x)
{
	Node* p;
	if (l.pHead != NULL)
	{
		x = l.pHead->data.gpa;
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
		delete p;
		return true;
	}
	return false;
}
int main()
{

	return 0;
}
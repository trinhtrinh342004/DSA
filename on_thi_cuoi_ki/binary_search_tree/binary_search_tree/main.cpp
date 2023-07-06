#include <iostream>
using namespace std;
// cấu trúc dữ liệu
struct node
{
	int info;
	struct node* pLeft;
	struct node* pRight;
};
typedef node* Tree;

//Tạo node
node* GetNode(int x)
{
	node* p = new node;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

// Đếm số nút lá trên cây
int DemLa(Tree t)
{
	if (t == NULL)
		return 0;
	if (t->pLeft == NULL && t->pRight == NULL)
		return 1;
	else
		return DemLa(t->pLeft) + DemLa(t->pRight);
}

// Đếm số nút con trên cây chỉ có duy nhất 1 nút con phải
int DemNode1Phai(Tree t)
{
	if (t != NULL)
		return 0;
	if (t->pLeft == NULL && t->pRight != NULL)
		return 1 + DemNode1Phai(t->pLeft) + DemNode1Phai(t->pRight);
	else
		return DemNode1Phai(t->pLeft) + DemNode1Phai(t->pRight);
}

int main()
{

	return 0;
}
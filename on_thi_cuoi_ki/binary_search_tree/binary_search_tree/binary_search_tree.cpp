#include <iostream>
using namespace std;
// cấu trúc dữ liệu
struct node
{
	int info;
	struct node* pLeft;
	struct node* pRight;
};
typedef node* tree;

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
// Hàm tính chiều cao
int height(tree t)
{
	if (t == NULL)
		return 0;
	int a = height(t->pLeft);
	int b = height(t->pRight);
	return (a > b ? a + 1 : b + 1);
}


// Đếm số nút có đủ 2 con
int Dem2Con(tree t)
{
	if (!t)
		return 0;
	int a = Dem2Con(t->pLeft);
	int b = Dem2Con(t->pRight);
	if (t->pLeft && t->pRight)
		return a + b + 1;
	return a + b;
}

// Đếm số node có 1 con
int Dem1Con(tree t)
{
	if (!t)
		return 0;
	int a = Dem1Con(t->pLeft);
	int b = Dem1Con(t->pRight);
	if ((!t->pLeft && t->pRight) || (t->pLeft && !t->pRight))
		return a + b + 1;
	return a + b;
}

// Đếm số nút lá
int DemLa(tree t)
{
	if (!t)
		return 0;
	int a = DemLa(t->pLeft);
	int b = DemLa(t->pRight);
	if (!t->pLeft && !t->pRight)
		return 1;
	return a + b;
}

// Số node không là node lá trong cây
int DemNodeKhongLa(tree t)
{
	if (!t)
		return 0;
	int a = DemNodeKhongLa(t->pLeft);
	int b = DemNodeKhongLa(t->pRight);
	if (t->pLeft || t->pRight)
		return a + b + 1;
	return a + b;
}

// Đếm số node lẻ trong cây
int DemNodeLe(tree t)
{
	if (!t)
		return 0;
	int a = DemNodeLe(t->pLeft);
	int b = DemNodeLe(t->pRight);
	if (int(t->info) % 2 == 1) // Chẵn thì thay 0 = 1 
		return a + b + 1;
	return a + b;
}

// tìm node max
tree TimMax(tree t)
{
	if (!t)
		return NULL;
	if (!t->pRight)
		return t;
	return TimMax(t->pRight);
}


int main()
{
	return 0;
}



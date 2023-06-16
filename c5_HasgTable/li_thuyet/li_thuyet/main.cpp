#include <iostream>
using namespace std;

//Direct Chaining

//Khai báo cấu trúc bảng băm
#define M 100 // Giả sử bảng băm có 100 phần tử
typedef struct tagNODE
{
	int key;
	tagNODE* next;
}; NODE, *NODEPTR;

// Khai báo mảng bucket chứa M phần tử
NODEPTR bucket[M];

// Giả sử chọn hàm băm: f(key)=key%M
// Xây dựng hàm băm
int hashfunc(int key)
{
	return (key % M);
}

// Xây dựng các thao tác trên bảng băm
//Hàm tạo bảng băm
void initbuckets()
{
	int b;
	for (b = 0; b < M; b++)
		bucket[b] = NULL;
}

//Hàm kiểm tra bucket b có bị rỗng hay không
int emptybucket(int b)
{
	return (bucket[b] == NULL ? TRUE : FALSE);
}

//Hàm kiểm tra bảng băm có rỗng hay không 
int empty()
{
	int b;
	for (b = 0; b < M; b++)
		if (bucket[b] != NULL)
			return false;
	return true;
}

//Hàm thêm khóa k vào bảng băm
void insert(int k)
{
	int b;
	b = hashfunc(k);
	place(b, k);
}

//Hàm xóa khóa k trong bảng băm
void remove(int k)
{
	int b;
	NODEPTR q, p;
	b = hashfunc(k);
	p = hashbucket(k);
	q = p;
	while (p != NULL && p->key != k)
	{
		q = p;
		p = p->next;
	}
	if  ( p == NULL)
		cout 
}


int main()
{
	
	return 0;

}
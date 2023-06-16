#include <iostream>

using namespace std;

// Khai báo cấu trúc node
typedef struct node
{
    int data;
    node* pNext;
} Node;

// Khai báo cấu trúc list
typedef struct list
{
    Node* pHead;
    Node* pTail;
} List;

// Khởi tạo node
Node* createNode(int x)
{
    Node* p = new Node;
    if (p == NULL) return NULL;
    p->data = x;
    p->pNext = NULL;
    return p;
}

// Khởi tạo Stack
void initStack(List& s) 
{
    s.pHead = s.pTail = NULL;
}

bool isEmpty(List& s) 
{
    return s.pHead == NULL;
}

void push(List& s, Node* Tam)
{
    if (isEmpty(s))
    {
        s.pHead = Tam;
        s.pTail = Tam;
    }
    else
    {
        Tam->pNext = s.pHead;
        s.pHead = Tam;
    }
}

void pop(List& s)
{
    Node* p;
    if (!isEmpty(s))
    {
        p = s.pHead;
        s.pHead = s.pHead->pNext;
        delete p;
        if (s.pHead == NULL)
            s.pTail = NULL;
    }
    else
    {
        cout << "Stack rỗng!";
    }
}

int top(List& s)
{
    if (!isEmpty(s))
        return s.pHead->data;
    return -1;
}

// Viết hàm đổi một số thập phân sang cơ số nhị phân
void binaryConversion(List& s, int decimal)
{
    if (decimal == 0)
    {
        push(s, createNode(0));
        return;
    }
    while (decimal > 0)
    {
        int remainder = decimal % 2;
        decimal /= 2;
        push(s, createNode(remainder));
    }
}

int main()
{
    List s;
    initStack(s);
    Node* p;
    int value;

    cout << "Nhập số thập phân muốn chuyển đổi sang nhị phân: ";
    cin >> value;
    binaryConversion(s, value);
    cout << "Số nhị phân tương ứng: ";
    while (!isEmpty(s))
    {
        cout << top(s);
        pop(s);
    }
    cout << "\n";

    return 0;
}
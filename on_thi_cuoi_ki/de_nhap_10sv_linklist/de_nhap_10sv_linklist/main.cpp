#include <iostream>
#include <string>
using namespace std;

typedef struct tagSinhVien
{
    int MSSV = 0;
    string TenSV;
    float DTB =  0;
} SinhVien;

typedef struct tagNode
{
    SinhVien data;
    struct tagNode* pNext = NULL;
} Node;

typedef struct list
{
    Node* pHead;
    Node* pTail;
} List;

void createList(List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

Node* createNode()
{
    Node* p = new Node;
    if (p == NULL)
        return NULL;
    cout << "Nhap MSSV: ";
    cin >> p->data.MSSV;
    cin.ignore();
    cout << "Nhap ho va ten: ";
    getline(cin, p->data.TenSV);
    cout << "Nhap DTB: ";
    cin >> p->data.DTB;
    p->pNext = NULL;
    return p;
}

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

void cau1(List& l)
{
    for (int i = 0; i < 10; i++)
    {
        Node* p = createNode();
        addTail(l, p);
    }
}

void cau2(List l)
{
    cout << "Danh sach sinh vien co DTB < 5:\n";
    Node* p = l.pHead;
    while (p != NULL)
    {
        if (p->data.DTB < 5)
            cout << p->data.MSSV << " " << p->data.TenSV << " " << p->data.DTB << endl;
        p = p->pNext;
    }
}

void cau3(List& l)
{
    Node* p = l.pHead;
    while (p != NULL)
    {
        l.pHead = l.pHead->pNext;
        delete p;
        p = l.pHead;
    }
    l.pTail = NULL;
}

int main()
{
    List l;
    createList(l);
    cau1(l);
    cau2(l);
    cau3(l);
    return 0;
}
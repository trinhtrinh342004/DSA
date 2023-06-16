#include <iostream>

using namespace std;

#define MAX 8

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} Node;

typedef Node* TREE;

//khoi tao node co gia tri x
Node* CreateNode(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

//khoi tao cay
void Init(TREE& t)
{
    t = NULL;
}

//them node co gia tri x vao cay
void InsertNode(TREE& t, int nodeValue)
{
    if (t == NULL) //cay rong
        t = CreateNode(nodeValue);
    else
    {
        if (t->data > nodeValue)
            InsertNode(t->left, nodeValue);
        else if (t->data < nodeValue)
            InsertNode(t->right, nodeValue);
    }
}

void CreateTree(TREE& t, int arr[MAX])
{
    for (int i = 0; i < MAX; i++) {
        InsertNode(t, arr[i]);
    }
}

//duyet cay nhi phan
void NLR(TREE t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        NLR(t->left);
        NLR(t->right);
    }
}

void LNR(TREE t)
{
    if (t != NULL)
    {
        LNR(t->left);
        cout << t->data << " ";
        LNR(t->right);
    }
}

void LRN(TREE t)
{
    if (t != NULL)
    {
        LRN(t->left);
        LRN(t->right);
        cout << t->data << " ";
    }
}

int main()
{
    TREE t;
    Init(t);
    int arr[MAX] = { 6, 4, 8, 3, 9, 5, 2 };
    int select, nodeValue;
    cout << "*********************************" << endl;
    cout << "0. Them node vao trong cay!\n" << endl;
    cout << "1. Duyet cay theo NLR!\n" << endl;
    cout << "2. Duyet cay theo LNR!\n" << endl;
    cout << "3. Duyet cay theo LRN!\n" << endl;
    cout << "4. Exit!\n" << endl;

    do {
        cout << "Chon chuc nang can thuc hien: ";
        cin >> select;
        switch (select)
        {
        case 0:
            cout << "Nhap gia tri node: ";
            cin >> nodeValue;
            InsertNode(t, nodeValue);
            break;
        case 1:
            cout << "Duyet cay theo NLR: ";
            NLR(t);
            cout << endl;
            break;
        case 2:
            cout << "Duyet cay theo LNR: ";
            LNR(t);
            cout << endl;
            break;
        case 3:
            cout << "Duyet cay theo LRN: ";
            LRN(t);
            cout << endl;
            break;
        case 4:
            cout << "Tam biet!\n" << endl;
            break;
        default:
            cout << "Thu lai!\n" << endl;
            break;
        }
    } while (select != 4);

    return 0;
}
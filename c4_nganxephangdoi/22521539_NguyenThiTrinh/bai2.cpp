#include <iostream>
#include <string>
using namespace std;

// Khai báo kiểu dữ liệu Patient
typedef struct patient
{
    int number;
    string name;
    int age;
}Patient;

// Khai báo cấu trúc node
typedef struct node 
{
    Patient data;
    node* pNext;
}Node;

// Khai báo cấu trúc list
typedef struct list
{
    Node* pHead;
    Node* pTail;
}List;

// Khởi tạo node
Node* createNode(Patient x)
{
    Node* p = new Node;
    if (p == NULL) return NULL;
    p->data = x;
    p->pNext = NULL;
    return p;
}

// Khởi tạo Queue
void initQueue(List& q)
{
    q.pHead = q.pTail = NULL;
}

bool isEmpty(List& q) 
{
    return q.pHead == NULL;
}

void enQueue(List& q, Patient x)
{
    Node* p = createNode(x);
    if (isEmpty(q)) {
        q.pHead = q.pTail = p;
    }
    else {
        q.pTail->pNext = p;
        q.pTail = p;
    }
}

Patient deQueue(List& q)
{
    if (!isEmpty(q)) {
        Node* p = q.pHead;
        Patient x = p->data;
        q.pHead = q.pHead->pNext;
        delete p;
        if (q.pHead == NULL)
            q.pTail = NULL;
        return x;
    }
    else 
    {
        Patient x;
        x.number = -1; // số thứ tự -1 để đại diện cho trường hợp hàng đợi rỗng
        return x;
    }
}

int countPatients(List& q) 
{
    int count = 0;
    Node* p = q.pHead;
    while (p)
    {
        count++;
        p = p->pNext;
    }
    return count;
}

int main()
{
    List q;
    initQueue(q);
    int select;
    Patient p;
    int nextNumber = 1;

    cout << "************************************\n";
    cout << "1. Them benh nhan vao hang doi\n";
    cout << "2. Chuyen den benh nhan tiep theo\n";
    cout << "3. So benh nhan chua duoc kham\n";
    cout << "4. So benh nhan duoc kham\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "************************************\n";

    do {
        cout << "Chon chuc nang muon xu li: "; cin >> select;
        switch (select)
        {
        case 0:
            cout << "Tam biet!\n";
            break;
        case 1:
            p.number = nextNumber++;
            cout << "Nhap ho ten benh nhan: "; cin.ignore(); getline(cin, p.name);
            cout << "Nhap tuoi benh nhan: "; cin >> p.age;
            enQueue(q, p);
            cout << "Da them benh nhan co so thu tu " << p.number << " vao hang doi.\n";
            break;
        case 2:
            p = deQueue(q);
            if (p.number == -1) {
                cout << "Khong co benh nhan nao trong hang doi.\n";
            }
            else {
                cout << "Benh nhan tiep theo la: " << p.name << " (" << p.age << " tuổi)\n";
                cout << "Da xoa benh nhan co so thu tu " << p.number << " khỏi hàng đợi.\n";
            }
            break;
        case 3:
            cout << "Hien tai co " << countPatients(q) << " benh nhan chua duoc kham.\n";
            break;
        case 4:
            cout << "Hien tai da co " << nextNumber - countPatients(q) - 1 << " benh nhan da duoc kham.\n";
            break;
        default:
            break;
        }
    } while (select);

    return 0;
}
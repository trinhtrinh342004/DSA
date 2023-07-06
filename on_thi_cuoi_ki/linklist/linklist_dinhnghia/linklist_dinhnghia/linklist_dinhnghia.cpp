#include <iostream>
using namespace std;

// Khai báo cấu trúc node
typedef struct node {
    int data;
    node* pNext;
}Node;

// Khai báo cấu trúc list
typedef struct list {
    Node* pHead;
    Node* pTail;
}List;

// Khởi tạo node
Node* createNode(int x) {
    Node* p = new Node;
    if (p == NULL) return NULL;
    p->data = x;
    p->pNext = NULL;
    return p;
}

// Khởi tạo list
void initList(List& l) {
    l.pHead = l.pTail = NULL;
}

// Thêm một node vào đầu danh sách
void addHead(List& l, Node* p) {
    if (l.pHead == NULL) { // danh sách rỗng
        l.pHead = l.pTail = p;
    }
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

// Thêm một node vào cuối danh sách
void addTail(List& l, Node* p) {
    if (l.pHead == NULL) { // danh sách rỗng
        l.pHead = l.pTail = p;
    }
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

// In danh sách
void printList(List l) {
    // Node *p;
    // p = l.pHead;
    // while (p != NULL){
    //     cout << p -> data << "\t";
    //     p = p -> pNext;
    // }
    for (Node* p = l.pHead; p != NULL; p = p->pNext) {
        cout << p->data << " ";
    }
    cout << "\n";
}

// Tìm node có giá trị lớn nhất trong danh sách
Node* findMaxNode(List l) {
    Node* max = l.pHead;
    for (Node* p = l.pHead->pNext; p != NULL; p = p->pNext) {
        if (max->data < p->data) {
            max = p;
        }
    }
    return max;
}

// Tìm node có khóa là x trong danh sách
Node* findNodeX(List l, int x) {
    Node* p;
    p = l.pHead;
    while ((p != NULL) && (p->data != x)) {
        p = p->pNext;
    }
    return p;
}

// Chèn node p vào sau node q cho trước
void insertAfterNodeQ(List& l, Node* p, Node* q) {
    if (q != NULL) {
        p->pNext = q->pNext;
        q->pNext = p;
        if (l.pTail == q)
            l.pTail = p;
    }
    else {
        addHead(l, p);
    }

}

// Chèn node p vào sau node q có giá trị x
void insertAfterX(List& l, Node* p, int x) {
    Node* q;
    q = findNodeX(l, x);
    if (q != NULL) {
        insertAfterNodeQ(l, p, q);
    }
    else {
        cout << "Không tìm thấy node có giá trị " << x << "!\n";
    }
}

// Chèn node p vào trước node q có giá trị 2 cho trước
// ---------------(sv thực hiện chức năng này)---------------


// Xóa node đầu danh sách
bool removeHead(List& l, int& x) {
    Node* p;
    if (l.pHead != NULL) {
        p = l.pHead;
        x = p->data;
        l.pHead = l.pHead->pNext;
        delete p;
        if (l.pHead == NULL)
            l.pTail = NULL;
        return true;
    }
    return false;
}

// Xóa node nằm sau node q trong danh sách
int removeAfterQ(List& l, Node* q, int& x) {
    Node* p;
    if (q != NULL) {
        p = q->pNext; //p là node cần hủy
        if (p != NULL) { // q không phải là node cuối 
            if (p == l.pTail) //node cần hủy là node cuối cùng 
                l.pTail = q; // cập nhật lại pTail
            else {
                q->pNext = p->pNext; // tách p ra khỏi xâu
                x = p->data;         // lưu dữ liệu node hủy
                delete p;            // hủy node p
            }
        }
        return 1;
    }
    else
        return 0;
}


// Xóa node có khóa x trong danh sách
int removeX(List& l, int x) {
    Node* p, * q = NULL;
    p = l.pHead;
    while ((p != NULL) && (p->data != x)) { // tìm x
        q = p;
        p = p->pNext;
    }
    if (p == NULL) // không tìm thấy phần tử có khoá bằng x
        return 0;
    if (q != NULL) // tìm thấy phần tử có khoá bằng x
        removeAfterQ(l, q, x);
    else
        removeHead(l, x); // phần tử cần hủy nằm đầu DS
    return 1;
}

// Xóa tất cả các node trong danh sách
void removeList(List& l) {
    Node* p;
    while (l.pHead != NULL) { // còn phần tử trong List
        p = l.pHead;
        l.pHead = p->pNext;
        delete p;
    }
}

// Sắp xếp danh sách
void selectionSort(List& l) {
    Node* p, * q, * min;
    p = l.pHead;
    while (p != l.pTail) {
        min = p;
        q = p->pNext;
        while (q != NULL) {
            if (q->data < min->data)
                min = q;
            q = q->pNext;
        }
        swap(min->data, p->data);
        p = p->pNext;
    }
}

// Chèn node vào danh sách, sao cho sau khi chèn vẫn đảm bảo thứ tự giá trị các node trong danh sách
// ---------------(sv thực hiện chức năng này)---------------

int main() {
    List l; initList(l);
    Node* p;
    int x;
    int select;
    cout << "*****************************\n";
    cout << "1. Thêm node vào đầu danh sách.\n";
    cout << "2. Thêm node vào cuối danh sách.\n";
    cout << "3. In danh sách.\n";
    cout << "4. Tìm node có giá trị lớn nhất trong danh sách.\n";
    cout << "5. Tìm node có giá trị x trong danh sách.\n";
    cout << "6. Chèn node p vào sau node q có giá trị x trong danh sách.\n";
    cout << "7. Xóa node có giá trị x trong danh sách.\n";
    cout << "8. Sắp xếp danh sách.\n";
    cout << "0. Thoát chương trình.\n";
    cout << "*****************************\n";
    do {
        cout << "Chọn chức năng thực hiện: "; cin >> select;
        switch (select) {
        case 0:
            cout << "Tạm biệt!\n";
            break;
        case 1:
            cout << "Nhập giá trị node muốn thêm vào đầu ds: ";
            cin >> x;
            p = createNode(x);
            addHead(l, p);
            break;
        case 2:
            cout << "Nhập giá trị node muốn thêm vào cuối ds: ";
            cin >> x;
            p = createNode(x);
            addTail(l, p);
            break;
        case 3:
            cout << "Danh sách các phần tử: ";
            printList(l);
            break;
        case 4:
            cout << "Giá trị lớn nhất trong danh sách: ";
            p = findMaxNode(l);
            cout << p->data << "\n";
            break;
        case 5:
            cout << "Nhập giá trị cần tìm: "; cin >> x;
            p = findNodeX(l, x);
            if (p != NULL)
                cout << "Tìm thấy!\n";
            else
                cout << "Không tìm thấy!\n";
            break;
        case 6:
            cout << "Nhập giá trị của node p cần chèn: "; cin >> x;
            p = createNode(x);
            cout << "Nhập giá trị x của node q cần tìm: "; cin >> x;
            insertAfterX(l, p, x);
            break;
        case 7:
            cout << "Nhập giá trị của node cần xóa: "; cin >> x;
            if (removeX(l, x) == 0)
                cout << "Không tìm thấy node có giá trị " << x << " trong ds!\n";
            else
                cout << "Đã xóa node có giá trị " << x << "!\n";
            break;
        case 8:
            selectionSort(l);
            cout << "Danh sách sau sắp xếp: ";
            printList(l);
            break;
        default:
            break;
        }
    } while (select);

    return 0;
}
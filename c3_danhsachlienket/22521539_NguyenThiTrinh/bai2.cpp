#include <iostream>
using namespace std;

// Định nghĩa cấu trúc cho danh sách liên kết đơn
struct Node 
{
    int coeff;
    int exp;
    Node* next;
};

// Hàm khởi tạo một Node mới
Node* createNode(int coeff, int exp) 
{
    Node* newNode = new Node;
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = nullptr;
    return newNode;
}

// Hàm thêm một phần tử vào danh sách liên kết
void append(Node** head, int coeff, int exp) 
{
    if (*head == nullptr)
    {
        *head = createNode(coeff, exp);
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = createNode(coeff, exp);
}

// Hàm nhập đa thức
Node* inputPolynomial()
{
    Node* poly = nullptr;
    int n;
    cout << "Nhap so luong hang tu cua da thuc: ";
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        int coeff, exp;
        cout << "Nhap he so va so mu cua hang tu " << i + 1 << ": ";
        cin >> coeff >> exp;
        append(&poly, coeff, exp);
    }
    return poly;
}

// Hàm cộng hai đa thức
Node* addPolynomials(Node* poly1, Node* poly2)
{
    Node* result = nullptr;

    while (poly1 != nullptr && poly2 != nullptr) 
    {
        if (poly1->exp > poly2->exp) 
        {
            append(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp) 
        {
            append(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        else {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0) 
            {
                append(&result, sum, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != nullptr) 
    {
        append(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != nullptr) 
    {
        append(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Hàm in đa thức
void printPolynomial(Node* poly) 
{
    if (poly == nullptr) 
    {
        cout << "0";
        return;
    }

    while (poly != nullptr)
    {
        if (poly->coeff > 0 && poly != poly->next)
        {
            cout << "+";
        }
        if (poly->exp == 0)
        {
            cout << poly->coeff;
        }
        else if (poly->exp == 1)
        {
            cout << poly->coeff << "x";
        }
        else
        {
            cout << poly->coeff << "x^" << poly->exp;
        }
        poly = poly->next;
    }
}

int main()
{
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;
    Node* sum = nullptr;

    cout << "Nhap da thuc thu nhat:\n";
    poly1 = inputPolynomial();
    cout << "Da thuc thu nhat la: ";
    printPolynomial(poly1);
    cout << endl;

    cout << "Nhap da thuc thu hai:\n";
    poly2 = inputPolynomial();
    cout << "Đa thuc thu hai la: ";
    printPolynomial(poly2);
    cout << endl;

    sum = addPolynomials(poly1, poly2);
    cout << "Tong hai da thuc la: ";
    printPolynomial(sum);
    cout << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <list>
using namespace std;

struct SinhVien 
{
    string MSSV;
    string Ten;
    float DTB;
    SinhVien* next;
};

SinhVien* first = NULL;

// Nhập danh sách sinh viên
void NhapDS() 
{
    string MSSV, Ten;
    float DTB;
    cout << "Nhap thong tin sinh vien (MSSV Ten DTB), ket thuc bang khoang trang: " << endl;
    cin >> MSSV >> Ten >> DTB;
    while (Ten != " ")
    {
        SinhVien* sv = new SinhVien;
        sv->MSSV = MSSV;
        sv->Ten = Ten;
        sv->DTB = DTB;
        sv->next = first;
        first = sv;
        cin >> MSSV >> Ten >> DTB;
    }
}

// Tim kiem sinh vien 
bool TimKiem(string MSSV)
{
    SinhVien* p = first;
    while (p != NULL && p->MSSV != MSSV)
        p = p->next;
    return p != NULL;
}


// Xoa sinh vien
void Xoa(string MSSV) 
{
    SinhVien* p = first, * q;
    if (first->MSSV == MSSV) 
    {
        first = first->next;
        delete p;
        return;
    }
    while (p->next != NULL && p->next->MSSV != MSSV)
        p = p->next;
    if (p->next != NULL)
    {
        q = p->next;
        p->next = p->next->next;
        delete q;
    }
}

// In danh sach sinh vien co DTB >= 5
void InDSDTB() 
{
    SinhVien* p = first;
    while (p != NULL)
    {
        if (p->DTB >= 5)
            cout << p->MSSV << " " << p->Ten << " " << p->DTB << endl;
        p = p->next;
    }
}

// Sap xep theo DTB va In danh sach 
void SapXepTheoDTB()
{
    SinhVien* p, * q;
    for (p = first; p != NULL; p = p->next)
        for (q = p->next; q != NULL; q = q->next)
            if (p->DTB > q->DTB)
                swap(p, q);
    p = first;
    while (p != NULL)
    {
        cout << p->MSSV << " " << p->Ten << " " << p->DTB << endl;
        p = p->next;
    }
}

// Xep loai sinh vien
string XepLoai(float DTB) 
{
    if (DTB <= 3.6) return "Yeu";
    if (DTB >= 5 && DTB < 6.5) return "Trung binh";
    if (DTB >= 6.5 && DTB < 7) return "Trung binh kha";
    if (DTB >= 7 && DTB < 8) return "Kha";
    if (DTB >= 8 && DTB < 9) return "Gioi";
    return "Xuat sac";
}

// Sap xep theo DTB va in ra danh sach sinh vien voi xep loai
void SapXepTheoDTBVaXepLoai() 
{
    SinhVien* p;
    for (p = first; p != NULL; p = p->next) 
    {
        cout << p->MSSV << " " << p->Ten << " " << p->DTB << " " << XepLoai(p->DTB) << endl;
    }
}

// Chen sinh vien vao DSLK tang DTB 
void Chen(SinhVien sv) 
{
    if (first == NULL || first->DTB >= sv.DTB)
    {
        sv.next = first;
        first = &sv;
        return;
    }
    SinhVien* p = first;
    while (p->next != NULL && p->next->DTB < sv.DTB)
        p = p->next;
    sv.next = p->next;
    p->next = &sv;
}

int main() 
{
    int choice;
    string MSSV;
    SinhVien sv;
    do 
    {
        cout << "1. Nhap danh sach sinh vien." << endl;
        cout << "2. Tim kiem sinh vien." << endl;
        cout << "3. Xoa sinh vien." << endl;
        cout << "4. In danh sach sinh vien co DTB >= 5." << endl;
        cout << "5. Sap xep theo DTB va in danh sach sinh vien." << endl;
        cout << "6. Sap xep theo DTB va in danh sach sinh vien voi xep loai." << endl;
        cout << "7. Chen sinh vien vao DSLK tang DTB." << endl;
        cout << "8. Thoat." << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        switch (choice) 
        {
        case 1:
            NhapDS();
            break;
        case 2:
            cout << "Nhap MSSV can tim: ";
            cin >> MSSV;
            if (TimKiem(MSSV))
                cout << "Sinh vien co MSSV " << MSSV << " co trong danh sach." << endl;
            else
                cout << "Sinh vien co MSSV " << MSSV << " khong co trong danh sach." << endl;
            break;
        case 3:
            cout << "Nhap MSSV can xoa: ";
            cin >> MSSV;
            Xoa(MSSV);
            break;
        case 4:
            InDSDTB();
            break;
        case 5:
            SapXepTheoDTB();
            break;
        case 6:
            SapXepTheoDTBVaXepLoai();
            break;
        case 7:
            cout << "Nhap thong tin sinh vien can chen (MSSV Ten DTB): ";
            cin >> sv.MSSV >> sv.Ten >> sv.DTB;
            Chen(sv);
            break;
        case 8:
            cout << "Tam biet!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
            break;
        }
    } while (choice != 8);
    return 0;
}
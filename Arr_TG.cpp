#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace std;

class Diem
{
private:
    int x;
    int y;
public:
    Diem();
    Diem(int h, int t);
    void inPut();
    void outPut();
    int getX();
    int getY();
    float KhoangCach(Diem);
};

class TamGiac 
{
protected:
    Diem A, B, C;
    float dt;
    float cv;
public:
    TamGiac();
    void inPut();
    void outPut();
    float getDT();
    float getCV();
    int is_TamGiac();
    void Tinh_CV();
    void Tinh_DT();
    Diem TrongTam();
};

class MangTamGiac
{
private:
    TamGiac* arr;  // Mảng các tam giác
    int n;         // Số lượng tam giác
public:
    MangTamGiac(int size);
    ~MangTamGiac();
    void inPut();
    void outPut();
    void TongCV();
    void TongDT();
};

int main()
{
    int n;
    cout << "Nhap so luong tam giac: ";
    cin >> n;

    MangTamGiac mang(n);
    mang.inPut();
    cout << "\nDanh sach tam giac:\n";
    mang.outPut();
    
    cout << "Tong chu vi cac tam giac: ";
    mang.TongCV();
    
    cout << "Tong dien tich cac tam giac: ";
    mang.TongDT();

    getch(); // Dừng xem kết quả
    return 1; // Hoặc return 0;
}

// Định nghĩa các phương thức lớp Diem
Diem::Diem()
{
    x = y = 0;
}
Diem::Diem(int h, int t)
{
    x = h; y = t;
}

void Diem::inPut()
{
    cout << "\nNhap hoanh do x: "; cin >> x;
    cout << "Nhap tung do y: "; cin >> y;
}

void Diem::outPut()
{
    cout << "(" << x << "," << y << ")"; //(3,5)
}

float Diem::KhoangCach(Diem P)
{
    return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
}

int Diem::getX()
{
    return x;
}

int Diem::getY()
{
    return y;
}

// Định nghĩa các phương thức lớp TamGiac
TamGiac::TamGiac()
{
    A = Diem(0, 0);
    B = Diem(0, 0);
    C = Diem(0, 0);
    dt = cv = 0;
}

void TamGiac::inPut()
{
    cout << "Nhap dinh thu nhat : "; A.inPut();
    cout << "Nhap dinh thu hai : "; B.inPut();
    cout << "Nhap dinh thu ba : "; C.inPut();
    
    while (!is_TamGiac())
    {
        cout << "3 Dinh tao nam tren duong thang, vui long nhap lai 3 dinh moi:\n";
        cout << "Nhap dinh thu nhat : "; A.inPut();
        cout << "Nhap dinh thu hai : "; B.inPut();
        cout << "Nhap dinh thu ba : "; C.inPut();		
    }
}

void TamGiac::outPut()
{
    cout << "\nDinh thu nhat: "; A.outPut();
    cout << "\nDinh thu hai: "; B.outPut();
    cout << "\nDinh thu ba: "; C.outPut();
    cout << endl << "Chu vi: " << cv << "  va dien tich= " << dt << endl;
}

float TamGiac::getDT()
{
    return dt;
}

float TamGiac::getCV()
{
    return cv;
}

int TamGiac::is_TamGiac()
{
    if ((B.getX() - A.getX()) * (C.getY() - A.getY()) == (C.getX() - A.getX()) * (B.getY() - A.getY()))
        return 0;
        
    return 1; 
}

Diem TamGiac::TrongTam()
{
    int x = (A.getX() + B.getX() + C.getX()) / 3;
    int y = (A.getY() + B.getY() + C.getY()) / 3;
    return Diem(x, y);
}

void TamGiac::Tinh_CV() 
{
    float c1 = A.KhoangCach(B);
    float c2 = B.KhoangCach(C);
    float c3 = C.KhoangCach(A);
    cv = (c1 + c2 + c3);
}

void TamGiac::Tinh_DT()
{
    float c1 = A.KhoangCach(B);
    float c2 = B.KhoangCach(C);
    float c3 = C.KhoangCach(A);
    
    float p = (c1 + c2 + c3) / 2;
        
    dt = sqrt(p * (p - c1) * (p - c2) * (p - c3));
}

// Định nghĩa các phương thức lớp MangTamGiac
MangTamGiac::MangTamGiac(int size)
{
    n = size;
    arr = new TamGiac[n]; // Cấp phát bộ nhớ cho mảng tam giác
}

MangTamGiac::~MangTamGiac()
{
    delete[] arr; // Giải phóng bộ nhớ
}

void MangTamGiac::inPut()
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nTam giac thu " << (i + 1) << ": ";
        arr[i].inPut();
        arr[i].Tinh_CV();
        arr[i].Tinh_DT();
    }
}

void MangTamGiac::outPut()
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nTam giac thu " << (i + 1) << ": ";
        arr[i].outPut();
    }
}

void MangTamGiac::TongCV()
{
    float tongCV = 0;
    for (int i = 0; i < n; i++)
    {
        tongCV += arr[i].getCV();
    }
    cout << tongCV << endl;
}

void MangTamGiac::TongDT()
{
    float tongDT = 0;
    for (int i = 0; i < n; i++)
    {
        tongDT += arr[i].getDT();
    }
    cout << tongDT << endl;
}

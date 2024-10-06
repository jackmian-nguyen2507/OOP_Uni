#include <iostream>
#include <cmath>
using namespace std;

class Diem
{
    private:
        int x;
        int y;
    public:
        Diem();                     // Constructor mặc định
        Diem(int h, int t);          // Constructor tham số
        void inPut();                // Nhập tọa độ
        void outPut();               // Xuất tọa độ
        int getX();                  // Lấy giá trị hoành độ
        int getY();                  // Lấy giá trị tung độ
};

class HinhTron
{
    private:
        Diem tam;                    // Tọa độ tâm
        float r;                     // Bán kính
        float cv;                    // Chu vi
        float dt;                    // Diện tích
    public:
        HinhTron();                  // Constructor mặc định
        void inPut();                // Nhập tâm và bán kính
        void outPut();               // Xuất chu vi và diện tích
        void Tinh_CV();              // Tính chu vi
        void Tinh_DT();              // Tính diện tích
};

// Triển khai lớp Diem
Diem::Diem() 
{
    x = y = 0;
}

Diem::Diem(int h, int t) 
{
    x = h; 
    y = t;
}

void Diem::inPut() 
{
    cout << "Nhap hoanh do x: "; cin >> x;
    cout << "Nhap tung do y: "; cin >> y;
}

void Diem::outPut() 
{
    cout << "(" << x << ", " << y << ")";
}

int Diem::getX() 
{
    return x;
}

int Diem::getY() 
{
    return y;
}

// Triển khai lớp HinhTron
HinhTron::HinhTron()
{
    r = cv = dt = 0;
}

void HinhTron::inPut()
{
    cout << "Nhap toa do tam cua hinh tron: " << endl;
    tam.inPut();
    cout << "Nhap ban kinh r: "; 
    cin >> r;
}

void HinhTron::outPut()
{
    cout << "Tam hinh tron: "; 
    tam.outPut();
    cout << "\nBan kinh: " << r;
    cout << "\nChu vi: " << cv;
    cout << "\nDien tich: " << dt << endl;
}

void HinhTron::Tinh_CV()
{
    cv = 2 * M_PI * r;  // Chu vi = 2 * pi * r
}

void HinhTron::Tinh_DT()
{
    dt = M_PI * r * r;  // Diện tích = pi * r^2
}

int main()
{
    int n;
    cout << "Nhap so luong hinh tron: ";
    cin >> n;

    // Khai báo mảng các đối tượng HinhTron
    HinhTron *List_Tron = new HinhTron[n];

    // Nhập thông tin cho từng hình tròn
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap thong tin cho hinh tron thu " << i+1 << ":" << endl;
        List_Tron[i].inPut();
        List_Tron[i].Tinh_CV();   // Tính chu vi
        List_Tron[i].Tinh_DT();   // Tính diện tích
    }

    // Xuất thông tin của từng hình tròn
    for (int i = 0; i < n; i++)
    {
        cout << "\nThong tin hinh tron thu " << i+1 << ":" << endl;
        List_Tron[i].outPut();
    }

    // Giải phóng bộ nhớ
    delete[] List_Tron;

    return 0;
}

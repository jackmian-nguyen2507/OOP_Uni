#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class PhanSo {
public:
    int tuSo;
    int mauSo;

public:
    PhanSo();
    PhanSo(int, int);
    PhanSo(const PhanSo&);
    void inPut();
    void outPut();

    int Uscln(int a, int b);
    void RutGon();
    float GiatriPS();
    void CHPS();

    // Phương thức tính toán
    PhanSo Cong(PhanSo ps);
    PhanSo Tru(PhanSo ps);
    PhanSo Nhan(PhanSo ps);
    PhanSo Chia(PhanSo ps);

    // Nhập - Xuất bằng lệnh
    friend istream& operator>>(istream& is, PhanSo& p);
    friend ostream& operator<<(ostream& os, PhanSo& p);

    // Các phép toán dùng toán tử
    PhanSo operator+(PhanSo);
    PhanSo operator-(PhanSo);
    PhanSo operator*(PhanSo);
    PhanSo operator/(PhanSo);

    // Toán tử So sánh
    int operator>(PhanSo);
    int operator<(PhanSo);
    int operator>=(PhanSo);
    int operator<=(PhanSo);
    int operator==(PhanSo);
    int operator!=(PhanSo);
};

class Stack {
private:
    PhanSo* arr; // Mảng để lưu trữ các phần tử
    int top;     // Chỉ số phần tử trên cùng
    int capacity; // Sức chứa của stack

public:
    Stack(int size); // Constructor
    ~Stack();        // Destructor
    void push(PhanSo p);
    PhanSo pop();
    PhanSo peek();
    bool isEmpty();
    bool isFull();
    int size();
};

class MangPhanSo {
private:
    Stack ds; // Sử dụng stack tự định nghĩa để lưu trữ phân số

public:
    MangPhanSo(int capacity); // Constructor để chỉ định dung lượng của stack
    void inPut(int n);
    void outPut();
    PhanSo TongMang();
    PhanSo TichMang();
};

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    MangPhanSo mang(n);
    mang.inPut(n);

    cout << "\nDanh sach phan so: \n";
    mang.outPut();

    cout << "\nTong cac phan so trong mang: ";
    mang.TongMang().outPut();

    cout << "\nTich cac phan so trong mang: ";
    mang.TichMang().outPut();

    return 0;
}

// Định nghĩa các phương thức của lớp PhanSo
PhanSo::PhanSo() {
    tuSo = 0;
    mauSo = 1;
}

PhanSo::PhanSo(int t, int m) {
    tuSo = t;
    mauSo = m;
}

PhanSo::PhanSo(const PhanSo& p) {
    tuSo = p.tuSo;
    mauSo = p.mauSo;
}

void PhanSo::inPut() {
    cout << "\nNhap Tu so: "; cin >> tuSo;
    cout << "Nhap Mau so: "; cin >> mauSo;
    while (mauSo == 0) {
        cout << "Mau so phai khac 0 - Nhap lai Mau so: "; cin >> mauSo;
    }
}

void PhanSo::outPut() {
    cout << tuSo << "/" << mauSo << " ";
}

float PhanSo::GiatriPS() {
    return (float)(tuSo) / (float)(mauSo);
}

istream& operator>>(istream& is, PhanSo& p) {
    cout << "\nNhap tu so: "; is >> p.tuSo;
    cout << "Nhap mau so: "; is >> p.mauSo;
    return is;
}

ostream& operator<<(ostream& os, PhanSo& p) {
    os << p.tuSo << "/" << p.mauSo;
    return os;
}

int PhanSo::Uscln(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == b) return a;
    else {
        while (a != 0 && b != 0) {
            if (a > b)
                a -= b;
            else b -= a;
        }
        return (a == 0) ? b : a;
    }
}

void PhanSo::RutGon() {
    int k = Uscln(tuSo, mauSo);
    tuSo = tuSo / k;
    mauSo = mauSo / k;
}

void PhanSo::CHPS() {
    if (mauSo < 0) {
        mauSo = -mauSo;
        tuSo = -tuSo;
    }
}

PhanSo PhanSo::Cong(PhanSo p) {
    PhanSo tam;
    tam.tuSo = tuSo * p.mauSo + mauSo * p.tuSo;
    tam.mauSo = mauSo * p.mauSo;
    tam.RutGon();
    tam.CHPS();
    return tam;
}

PhanSo PhanSo::Tru(PhanSo p) {
    PhanSo tam;
    tam.tuSo = tuSo * p.mauSo - mauSo * p.tuSo;
    tam.mauSo = mauSo * p.mauSo;
    tam.RutGon();
    tam.CHPS();
    return tam;
}

PhanSo PhanSo::Nhan(PhanSo p) {
    PhanSo tam;
    tam.tuSo = tuSo * p.tuSo;
    tam.mauSo = mauSo * p.mauSo;
    tam.RutGon();
    tam.CHPS();
    return tam;
}

PhanSo PhanSo::Chia(PhanSo p) {
    PhanSo tam;
    tam.tuSo = tuSo * p.mauSo;
    tam.mauSo = mauSo * p.tuSo;
    tam.RutGon();
    tam.CHPS();
    return tam;
}

PhanSo PhanSo::operator+(PhanSo p) {
    return Cong(p);
}

PhanSo PhanSo::operator-(PhanSo p) {
    return Tru(p);
}

PhanSo PhanSo::operator*(PhanSo p) {
    return Nhan(p);
}

PhanSo PhanSo::operator/(PhanSo p) {
    return Chia(p);
}

int PhanSo::operator>(PhanSo p) {
    return GiatriPS() > p.GiatriPS();
}

int PhanSo::operator<(PhanSo p) {
    return GiatriPS() < p.GiatriPS();
}

int PhanSo::operator>=(PhanSo p) {
    return GiatriPS() >= p.GiatriPS();
}

int PhanSo::operator<=(PhanSo p) {
    return GiatriPS() <= p.GiatriPS();
}

int PhanSo::operator==(PhanSo p) {
    return GiatriPS() == p.GiatriPS();
}

int PhanSo::operator!=(PhanSo p) {
    return GiatriPS() != p.GiatriPS();
}

// Định nghĩa các phương thức của lớp Stack
Stack::Stack(int size) {
    arr = new PhanSo[size];
    capacity = size;
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(PhanSo p) {
    if (isFull()) {
        cout << "Stack da day, khong the them phan so!" << endl;
        return;
    }
    arr[++top] = p;
}

PhanSo Stack::pop() {
    if (isEmpty()) {
        cout << "Stack rong, khong the pop!" << endl;
        return PhanSo(); // Trả về phân số mặc định
    }
    return arr[top--];
}

PhanSo Stack::peek() {
    if (isEmpty()) {
        cout << "Stack rong!" << endl;
        return PhanSo(); // Trả về phân số mặc định
    }
    return arr[top];
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == capacity - 1;
}

int Stack::size() {
    return top + 1;
}

// Định nghĩa các phương thức của lớp MangPhanSo
MangPhanSo::MangPhanSo(int capacity) : ds(capacity) {}

void MangPhanSo::inPut(int n) {
    for (int i = 0; i < n; i++) {
        PhanSo ps;
        cout << "\nNhap phan so thu " << i + 1 << ": ";
        cin >> ps;
        ds.push(ps);
    }
}

void MangPhanSo::outPut() {
    for (int i = 0; i < ds.size(); i++) {
        PhanSo ps = ds.pop();
        ps.outPut();
        ds.push(ps); // Push lại để giữ nguyên stack
    }
}

PhanSo MangPhanSo::TongMang() {
    PhanSo tong;
    while (!ds.isEmpty()) {
        tong = tong + ds.pop();
    }
    return tong;
}

PhanSo MangPhanSo::TichMang() {
    if (ds.isEmpty()) return PhanSo(0, 1); // Trả về phân số 0 nếu stack rỗng
    PhanSo tich = ds.pop(); // Lấy phần tử đầu tiên

    while (!ds.isEmpty()) {
        tich = tich * ds.pop(); // Sử dụng toán tử *
    }
    return tich;
}

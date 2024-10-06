#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Diem {
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

class TamGiac {
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

class StackTamGiac {
private:
    TamGiac* stack;  // Mảng chứa các tam giác
    int top;         // Chỉ số phần tử trên cùng
    int capacity;    // Dung lượng tối đa của stack
public:
    StackTamGiac(int size);
    ~StackTamGiac();
    void push(const TamGiac& tg);
    TamGiac pop();
    bool isEmpty();
    void display();
    void TongCV();
    void TongDT();
};

int main() {
    int n;
    cout << "Nhap so luong tam giac: ";
    cin >> n;

    StackTamGiac stack(n);
    for (int i = 0; i < n; i++) {
        TamGiac tg;
        cout << "\nTam giac thu " << (i + 1) << ": ";
        tg.inPut();
        tg.Tinh_CV();
        tg.Tinh_DT();
        stack.push(tg);  // Đưa tam giác vào stack
    }

    cout << "\nDanh sach tam giac:\n";
    stack.display();

    cout << "Tong chu vi cac tam giac: ";
    stack.TongCV();

    cout << "Tong dien tich cac tam giac: ";
    stack.TongDT();

    return 0; // Hoặc return 0;
}

// Định nghĩa các phương thức lớp Diem
Diem::Diem() {
    x = y = 0;
}

Diem::Diem(int h, int t) {
    x = h; y = t;
}

void Diem::inPut() {
    cout << "\nNhap hoanh do x: "; cin >> x;
    cout << "Nhap tung do y: "; cin >> y;
}

void Diem::outPut() {
    cout << "(" << x << "," << y << ")"; //(3,5)
}

float Diem::KhoangCach(Diem P) {
    return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
}

int Diem::getX() {
    return x;
}

int Diem::getY() {
    return y;
}

// Định nghĩa các phương thức lớp TamGiac
TamGiac::TamGiac() {
    A = Diem(0, 0);
    B = Diem(0, 0);
    C = Diem(0, 0);
    dt = cv = 0;
}

void TamGiac::inPut() {
    cout << "Nhap dinh thu nhat : "; A.inPut();
    cout << "Nhap dinh thu hai : "; B.inPut();
    cout << "Nhap dinh thu ba : "; C.inPut();
    
    while (!is_TamGiac()) {
        cout << "3 Dinh tao nam tren duong thang, vui long nhap lai 3 dinh moi:\n";
        cout << "Nhap dinh thu nhat : "; A.inPut();
        cout << "Nhap dinh thu hai : "; B.inPut();
        cout << "Nhap dinh thu ba : "; C.inPut();		
    }
}

void TamGiac::outPut() {
    cout << "\nDinh thu nhat: "; A.outPut();
    cout << "\nDinh thu hai: "; B.outPut();
    cout << "\nDinh thu ba: "; C.outPut();
    cout << endl << "Chu vi: " << cv << "  va dien tich= " << dt << endl;
}

float TamGiac::getDT() {
    return dt;
}

float TamGiac::getCV() {
    return cv;
}

int TamGiac::is_TamGiac() {
    if ((B.getX() - A.getX()) * (C.getY() - A.getY()) == (C.getX() - A.getX()) * (B.getY() - A.getY()))
        return 0;
        
    return 1; 
}

Diem TamGiac::TrongTam() {
    int x = (A.getX() + B.getX() + C.getX()) / 3;
    int y = (A.getY() + B.getY() + C.getY()) / 3;
    return Diem(x, y);
}

void TamGiac::Tinh_CV() {
    float c1 = A.KhoangCach(B);
    float c2 = B.KhoangCach(C);
    float c3 = C.KhoangCach(A);
    cv = (c1 + c2 + c3);
}

void TamGiac::Tinh_DT() {
    float c1 = A.KhoangCach(B);
    float c2 = B.KhoangCach(C);
    float c3 = C.KhoangCach(A);
    
    float p = (c1 + c2 + c3) / 2;
        
    dt = sqrt(p * (p - c1) * (p - c2) * (p - c3));
}

// Định nghĩa các phương thức lớp StackTamGiac
StackTamGiac::StackTamGiac(int size) {
    capacity = size;
    stack = new TamGiac[capacity];
    top = -1; // Chỉ số của phần tử trên cùng là -1 khi stack rỗng
}

StackTamGiac::~StackTamGiac() {
    delete[] stack; // Giải phóng bộ nhớ
}

void StackTamGiac::push(const TamGiac& tg) {
    if (top < capacity - 1) { // Kiểm tra nếu stack chưa đầy
        stack[++top] = tg; // Tăng chỉ số top và thêm tam giác
    } else {
        cout << "Stack day! Khong the them tam giac.\n";
    }
}

TamGiac StackTamGiac::pop() {
    if (top >= 0) { // Kiểm tra nếu stack không rỗng
        return stack[top--]; // Trả về tam giác trên cùng và giảm chỉ số top
    } else {
        cout << "Stack rong! Khong the lay tam giac.\n";
        return TamGiac(); // Trả về một tam giác rỗng
    }
}

bool StackTamGiac::isEmpty() {
    return top == -1; // Kiểm tra xem stack có rỗng không
}

void StackTamGiac::display() {
    for (int i = top; i >= 0; i--) { // Hiển thị các tam giác từ trên xuống
        cout << "\nTam giac thu " << (i + 1) << ": ";
        stack[i].outPut();
    }
}

void StackTamGiac::TongCV() {
    float tongCV = 0;
    for (int i = 0; i <= top; i++) {
        tongCV += stack[i].getCV();
    }
    cout << tongCV << endl;
}

void StackTamGiac::TongDT() {
    float tongDT = 0;
    for (int i = 0; i <= top; i++) {
        tongDT += stack[i].getDT();
    }
    cout << tongDT << endl;
}

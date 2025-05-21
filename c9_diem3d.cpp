#include <iostream>
using namespace std;

class Diem3D {
private:
    int x, y, z;

public:
    Diem3D();                         // Hàm khởi tạo mặc định
    Diem3D(int x, int y, int z);      // Hàm khởi tạo có đối số
    ~Diem3D();                        // Hàm hủy

    // Khai báo các toán tử friend
    friend istream& operator>>(istream& in, Diem3D& d);
    friend ostream& operator<<(ostream& out, const Diem3D& d);
    friend Diem3D operator+(const Diem3D& a, const Diem3D& b);
    friend Diem3D operator-(const Diem3D& a, const Diem3D& b);
};
// Hàm khởi tạo mặc định
Diem3D::Diem3D() {
    x = y = z = 0;
}

// Hàm khởi tạo có tham số
Diem3D::Diem3D(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Hàm hủy
Diem3D::~Diem3D() {
    // Không cần giải phóng gì vì không dùng con trỏ
}
istream& operator>>(istream& in, Diem3D& d) {
    cout << "Nhap x: "; in >> d.x;
    cout << "Nhap y: "; in >> d.y;
    cout << "Nhap z: "; in >> d.z;
    return in;
}

ostream& operator<<(ostream& out, const Diem3D& d) {
    out << "(" << d.x << ", " << d.y << ", " << d.z << ")";
    return out;
}

Diem3D operator+(const Diem3D& a, const Diem3D& b) {
    return Diem3D(a.x + b.x, a.y + b.y, a.z + b.z);
}

Diem3D operator-(const Diem3D& a, const Diem3D& b) {
    return Diem3D(a.x - b.x, a.y - b.y, a.z - b.z);
}
int main() {
    Diem3D M1, M2;

    cout << "Nhap diem M1:\n";
    cin >> M1;

    cout << "Nhap diem M2:\n";
    cin >> M2;

    Diem3D tong = M1 + M2;
    Diem3D hieu = M1 - M2;

    cout << "\nM1 = " << M1 << endl;
    cout << "M2 = " << M2 << endl;
    cout << "M1 + M2 = " << tong << endl;
    cout << "M1 - M2 = " << hieu << endl;

    return 0;
}

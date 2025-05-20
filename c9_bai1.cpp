#include <iostream>
using namespace std;

class number {
    private:
        float x;
    public:
        friend istream& operator >> (istream& is, number& u);
        friend ostream& operator << (ostream& os, number u);

        number operator+ (const number& b);
        number operator- (const number& b);
        number operator* (const number& b);
        number operator/ (const number& b);
};

istream& operator >> (istream& is, number& u) { //nhap
    cout<<"Nhap gia tri x: ";
    is >> u.x;
    return is;
}

ostream& operator << (ostream& os, number u) {
    os << "x = " <<u.x<<endl;
    return os;
}

number number::operator+(const number& b) {
    number kq;
    kq.x = this->x + b.x;
    return kq;
}

number number::operator-(const number& b) {
    number kq;
    kq.x = this->x - b.x;
    return kq;
}

number number::operator*(const number& b) {
    number kq;
    kq.x = this->x * b.x;
    return kq;
}

number number::operator/(const number& b) {
    number kq;
    if(b.x == 0) {
        cout<<"LOI";
        kq.x = 0;
    } else {
        kq.x = this->x / b.x;
    }
    return kq;
}

int main() {
    number n, m, cong, tru, nhan, chia;

    cin >> n >> m;
    cout << n << m;

    cong = n + m;
    cout<<"Cong: \t"<<cong<<endl;

    tru = n - m;
    cout<<"tru: \t"<<tru<<endl;

    nhan = n * m;
    cout<<"nhan: \t"<<nhan<<endl;

    chia = n / m;
    cout<<"chia: \t"<<chia<<endl;

    return 0;
}
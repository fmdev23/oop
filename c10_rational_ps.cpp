#include <iostream>
#include <cmath>
using namespace std;

class rational {
    private:
        int tuso, mauso;
        int ucln(int a, int b);
        void rutgon();
    public:
        rational(int tu = 0, int mau = 1);
        ~rational();

        rational operator+(rational& b);
        rational operator-(rational& b);
        rational operator*(rational& b);
        rational operator/(rational& b);

        bool operator==(rational& b);
        bool operator!=(rational& b);
        bool operator<(rational& b);
        bool operator<=(rational& b);
        bool operator>(rational& b);
        bool operator>=(rational& b);

        friend istream& operator>>(istream& in, rational& ps);
        friend ostream& operator<<(ostream& out, rational ps);
};

rational::rational(int tu, int mau) {
    tuso = tu;
    if(mau == 0) mau = 1;
        mauso = mau;
    rutgon();
}

rational::~rational() {

}

int rational::ucln(int a, int b) {
    if(b == 0) return a;
    return ucln(b, a%b);
}

void rational::rutgon() {
    int u = ucln(abs(tuso), abs(mauso));
    tuso /= u;
    mauso /= u;

    if(mauso < 0) {
        tuso = -tuso;
        mauso = -mauso;
    }
}

rational rational::operator+(rational& b) {
    rational kq;
    kq.tuso = tuso * b.mauso + b.tuso * mauso;
    kq.mauso = mauso * b.mauso;
    kq.rutgon();
    return kq;
}

rational rational::operator-(rational& b) {
    rational kq;
    kq.tuso = tuso * b.mauso - b.tuso * mauso;
    kq.mauso = mauso * b.mauso;
    kq.rutgon();
    return kq;
}

rational rational::operator*(rational& b) {
    rational kq;
    kq.tuso = tuso * b.tuso;
    kq.mauso = mauso * b.mauso;
    kq.rutgon();
    return kq;
}

rational rational::operator/(rational& b) {
    rational kq;
    kq.tuso = tuso * b.mauso;
    kq.mauso = mauso * b.tuso;
    if(kq.mauso == 0) {
        cout<<"LOI";
        kq.mauso = 1;
    }
    kq.rutgon();
    return kq;
}

bool rational::operator==(rational& b) {
    return tuso == b.tuso && mauso == b.mauso;
}

bool rational::operator!=(rational& b) {
    return !(*this == b);
}

bool rational::operator<(rational& b) {
    return tuso * b.mauso < b.tuso * mauso;
}

bool rational::operator<=(rational& b) {
    return tuso * b.mauso <= b.tuso * mauso;
}

bool rational::operator>(rational& b) {
    return tuso * b.mauso > b.tuso * mauso;
}

bool rational::operator>=(rational& b) {
    return tuso * b.mauso >= b.tuso * mauso;
}

istream& operator>>(istream& in, rational& ps) {
    cout<<"\nNhap tu so: "; in >> ps.tuso;
    cout<<"\nNhap mau so: "; in >> ps.mauso;

    if(ps.mauso == 0) {
        cout<<"LOI";
        ps.mauso = 1;
    }
    ps.rutgon();
    return in;
}

ostream& operator<<(ostream& out, rational ps) {
    out << ps.tuso << " / " << ps.mauso << endl;
    return out;
}

int main() {
    rational a, b, c;

    cout<<"\nNhap phan so a: "; cin >> a;
    cout<<"\nNhap phan so b: "; cin >> b;

    cout<<"\na = " << a << endl;
    cout<<"\nb = " << b << endl;

    cout<<"\na + b = "<<a+b;
    cout<<"\na - b = "<<a-b;
    cout<<"\na * b = "<<a*b;
    cout<<"\na / b = "<<a/b;

    cout<< "\na == b " << (a==b) <<endl;
    cout<< "\na != b " << (a!=b) <<endl;
    cout<< "\na > b " << (a>b) <<endl;
    cout<< "\na >= b " << (a>=b) <<endl;
    cout<< "\na < b " << (a<b) <<endl;
    cout<< "\na <= b " << (a<=b) <<endl;

    return 0;
}
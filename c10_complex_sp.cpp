#include <iostream>
#include <cmath>
using namespace std;

class complex {
    private:
        float thuc, ao;
    public:
        complex();
        ~complex();

        complex operator+(complex& b);
        complex operator-(complex& b);
        complex operator*(complex& b);
        complex operator/(complex& b);

        friend istream& operator>>(istream& in, complex& c);
        friend ostream& operator<<(ostream& out, complex c);
};

complex::complex() {
    thuc = 0;
    ao = 0;
}

complex::~complex() {

}

complex complex::operator+(complex& b) {
    complex kq;
    kq.thuc = thuc + b.thuc;
    kq.ao = ao + b.ao;
    return kq;
}

complex complex::operator-(complex& b) {
    complex kq;
    kq.thuc = thuc - b.thuc;
    kq.ao = ao - b.ao;
    return kq;
}

complex complex::operator*(complex& b) {
    complex kq;
    kq.thuc = thuc * b.thuc - ao * b.ao;
    kq.ao = thuc * b.ao + ao * b.thuc;
    return kq;
}

complex complex::operator/(complex& b) {
    complex kq;
    float mau = pow(b.thuc, 2) + pow(b.ao, 2);
    if(mau == 0) {
        cout<<"LOI";
        kq.thuc = kq.ao = 0;
        return kq;
    }

    kq.thuc = ( thuc * b.thuc + ao * b.ao ) / mau;
    kq.ao = ( ao * b.thuc - thuc * b.ao ) / mau;
    return kq;
}

istream& operator>>(istream& in, complex& c) {
    cout<<"\nNhap phan thuc: "; in >> c.thuc;
    cout<<"\nNhap phan ao: "; in >> c.ao;
    return in;
}

ostream& operator<<(ostream& out, complex c) {
    if(c.ao >= 0) 
        out << c.thuc << " +" << c.ao << "i";
    else 
        out << c.thuc << " " << c.ao << "i";
    return out;
}

int main() {
    complex a, b;

    cout<<"\nNhap so phuc 1: "; cin>>a;
    cout<<"\nNhap so phuc 2: "; cin>>b;

    cout<<"\nSo phuc 1 la: " << a << endl;
    cout<<"\nSo phuc 2 la: " << b << endl;

    cout<<"\nTong hai so phuc: " << a+b << endl;
    cout<<"\nHieu hai so phuc: " << a-b << endl;
    cout<<"\nTich hai so phuc: " << a*b << endl;
    cout<<"\nThuong hai so phuc: " << a/b << endl;

    return 0;
}
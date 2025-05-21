#include <iostream>
#include <cmath>

using namespace std;

class phanso {
    private:
        int tuso, mauso;
    public:
        phanso(int tu, int mau);
        ~phanso();
        void nhap();
        void xuat();
        void rutgon();
        int ucln(int, int);
        phanso cong(phanso);
        phanso tru(phanso);
        phanso nhan(phanso);
        phanso chia(phanso);
};

phanso::phanso(int tu = 0, int mau = 1) {
    tuso = tu;
    mauso = mau;
}

phanso::~phanso() {

}

void phanso::nhap() {
    cout<<"\nNhap tu so: "; cin>>tuso;
    cout<<"\nNhap mau so: "; cin>>mauso;
}

void phanso::xuat() {
    cout<<tuso<< " / " <<mauso<<endl;
}

int phanso::ucln(int a, int b) {
    while(b!=0) {
        int t = b;
        b = a%b;
        a = t;
    }
    return a;
}

void phanso::rutgon() {
    int u = ucln(tuso, mauso);
    tuso /= u;
    mauso /= u;
}

phanso phanso::cong(phanso p) {
    phanso kq;
    kq.tuso = tuso * p.mauso + p.tuso * mauso;
    kq.mauso = mauso * p.mauso;
    kq.rutgon();
    return kq;
}

phanso phanso::tru(phanso p) {
    phanso kq;
    kq.tuso = tuso * p.mauso - p.tuso * mauso;
    kq.mauso = mauso * p.mauso;
    kq.rutgon();
    return kq;
}

phanso phanso::nhan(phanso p) {
    phanso kq;
    kq.tuso = tuso * p.tuso;
    kq.mauso = mauso * p.mauso;
    kq.rutgon();
    return kq;
}

phanso phanso::chia(phanso p) {
    phanso kq;
    kq.tuso = tuso * p.mauso;
    kq.mauso = mauso * p.tuso;
    kq.rutgon();
    return kq;
}


int main() {

    return 0;
}
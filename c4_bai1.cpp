#include <iostream>
using namespace std;

class diem2d {
    private:
        int x, y;
    public:
        diem2d();
        diem2d(int x1, int y1);
        ~diem2d();
        void setx(int x1);
        void sety(int y1);
        int getx();
        int gety();
        void tinhtien(int dx, int dy, int x1, int y1);
        void nhap();
        void xuat();
};

diem2d::diem2d() {
    x = 0;
    y = 0;
}

diem2d::diem2d(int x1, int y1) {
    x = x1;
    y = y1;
}

diem2d::~diem2d() {

}

void diem2d::setx(int x1) {
    x = x1;
}

void diem2d::sety(int y1) {
    y = y1;
}

int diem2d::getx() {
    return x;
}

int diem2d::gety() {
    return y;
}

void diem2d::tinhtien(int dx, int dy, int x, int y) {
    x += dx;
    y += dy;
}

void diem2d::nhap() {
    cout<<"Nhap vao x: "; cin>>x;
    cout<<"Nhap vao y: "; cin>>y;
}

void diem2d::xuat() {
    cout<<"Toa do vua nhap la: ";
    cout<<"( "<<x<< " , " <<y<< " )";
}


int main() {
    diem2d a;

    a.nhap();
    a.xuat();

    a.setx(2);
    a.sety(5);
    a.getx();
    a.gety();
    a.xuat();

    a.tinhtien(0,9,8,7);
    a.xuat();

    return 0;
}
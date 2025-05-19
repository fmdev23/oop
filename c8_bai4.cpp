#include <iostream>
#include <cmath>
using namespace std;

class cylinder {
    private: 
        int bankinh, chieucao;
    public:
        void nhap();
        void xuat();
        
        cylinder();
        cylinder(int r, int h);
        ~cylinder();

        float dientichtoanphan();
        float thetich();
};

cylinder::cylinder() {
    bankinh = 0;
    chieucao = 0;
}

cylinder::cylinder(int r, int h) {
    bankinh = r;
    chieucao = h;
}

cylinder::~cylinder() {

}

void cylinder::nhap() {
    cout<<"\nNhap ban kinh: "; cin>>bankinh;
    cout<<"\nNhap chieu cao: "; cin>>chieucao;
}

void cylinder::xuat() {
    cout<<"Ban kinh = "<<bankinh<<endl;
    cout<<"Chieu cao = "<<chieucao<<endl;
}

float cylinder::dientichtoanphan() {
    return 2*M_PI*bankinh*(bankinh+chieucao);
}

float cylinder::thetich() {
    return M_PI*pow(bankinh, 2)*chieucao;
}

int main() {
    cylinder a;

    a.nhap();
    cout<<"\nThong so hinh tru la: \n";
    a.xuat();

    cout<<"\nDien tich toan phan la: "<<a.dientichtoanphan()<<endl;
    cout<<"\nThe tich la: "<<a.thetich()<<endl;

    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

class tamgiac {
    private:
        int canha, canhb, canhc;
    public:
        tamgiac(double a = 0, double b = 0, double c = 0);
        ~tamgiac();
        void nhap();
        void xuat();
        int hople();
        void phanloai();
        double tinhchuvi();
        double tinhdientich();
};  

tamgiac::tamgiac(double a, double b, double c) {
    canha = a;
    canhb = b;
    canhc = c;
}

tamgiac::~tamgiac() {

}

void tamgiac::nhap() {
    cout<<"\nNhap a: "; cin>>canha;
    cout<<"\nNhap b: "; cin>>canhb;
    cout<<"\nNhap c: "; cin>>canhc;
}

void tamgiac::xuat() {
    cout<<"A = "<<canha<<",\t";
    cout<<"B = "<<canhb<<",\t";
    cout<<"C = "<<canhc<<"\t";
}

int tamgiac::hople() {
    return (canha > 0 && canhb > 0 && canhc > 0 && canha+canhb>canhc && canha+canhc>canhb && canhb+canhc>canha);
}

void tamgiac::phanloai() {
    if(!hople()) {
        cout<<"Tam giac khong hop le";
        return;
    } else {
        
        if(canha == canhb && canhb == canhc) {
            cout<<"Tam giac deu";
        } else if(canha == canhb || canha == canhc || canhb == canhc) {
            cout<<"Tam giac can";
        } else if(pow(canha, 2) + pow(canhb, 2) == pow(canhc, 2) || pow(canha, 2) + pow(canhc, 2) == pow(canhb, 2) || pow(canhb, 2) + pow(canhc, 2) == pow(canha, 2) ) {
            cout<<"Tam giac vuong";
        } else {
            cout<<"Tam giac thuong";
        }
    }

}

double tamgiac::tinhchuvi() {
    if(!hople()) {
        return 0;
    } else {
        return canha+canhb+canhc;
    }
}

double tamgiac::tinhdientich() {
    if(!hople()) {
        return 0;
    } else {
        double p = tinhchuvi() / 2;
        return sqrt( p*(p-canha) * (p-canhb) * (p-canhc) );
    }
}

int main() {
    tamgiac a;

    a.nhap();
    a.xuat();

    cout<<"Chu vi: "<<a.tinhchuvi()<<endl;
    cout<<"Dien tich: "<<a.tinhdientich()<<endl;

    return 0;
}
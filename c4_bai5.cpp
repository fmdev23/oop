#include <iostream>
using namespace std;

class tongdayso {
    private:
        int i, n;
        double tong;
    public:
        void nhap();
        void xuat();
        double tinhtong();
};

void tongdayso::nhap() {
    cout<<"Nhap n: "; cin>>n;
}

double tongdayso::tinhtong() {
    tong = 0;
    for(int i = 0; i<=n; i++) {
        tong += i;
    }
    return tong;
}

void tongdayso::xuat() {
    cout<<"Tong day so tu 1 den "<<n<<" la: "<<tinhtong()<<endl;
}

int main() {
    tongdayso a;

    a.nhap();
    a.xuat();

    return 0;
}
#include <iostream>
using namespace std;

class vecto {
    private:
        int n;
        int a[100];
    public:
        void nhap();
        void xuat();
        bool cungcap(vecto b);
        vecto tong(vecto b);
        vecto hieu(vecto b);
        vecto tichvh(vecto b);
};

void vecto::nhap() {
    cout<<"Nhap cap vecto: "; cin>>n;
    for(int i = 0; i<n; i++) {
        cout<<"\nNhap phan tu thu: "<<i+1<<": ";
        cin>>a[i];
    }
}

void vecto::xuat() {
    for(int i = 0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

bool vecto::cungcap(vecto b) {
    return n == b.n;
}

vecto vecto::tong(vecto b) {
    vecto kq;
    kq.n = n;
    for(int i = 0; i<n; i++) {
        kq.a[i] = a[i] + b.a[i];
    }
    return kq;
} 

vecto vecto::hieu(vecto b) {
    vecto kq;
    kq.n = n;
    for(int i = 0; i<n; i++) {
        kq.a[i] = a[i] - b.a[i];
    }
    return kq;
}

vecto vecto::tichvh(vecto b) {
    vecto kq;
    kq.n = n;
    for(int i = 0; i<n; i++) {
        kq.a[i] = a[i] * b.a[i];
    }
    return kq;
} 

int main() {
    vecto v1, v2;

    cout<<"Nhap vecto 1: "; v1.nhap();
    cout<<"Nhap vecto 2: "; v2.nhap();

    cout<<"vecto 1 = "; v1.xuat();
    cout<<"vecto 2 = "; v2.xuat();

    if(v1.cungcap(v2)) {
        vecto tong = v1.tong(v2);
        vecto hieu = v1.hieu(v2);
        vecto tichvh = v1.tichvh(v2);

        cout<<"Tong: "; tong.xuat();
        cout<<"Hieu: "; hieu.xuat();
        cout<<"Tich vh: "; tichvh.xuat();
    } else {
        cout<<"Khong cung cap";
    }

    return 0;
}
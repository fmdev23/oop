#include <iostream>
#include <cmath>

using namespace std;

class mang1chieu {
    private:
        int a[100], n;
    public:
        void taomang();
        void inmang();
        void minmax();
        void saptang();
        void sapgiam();
        int tongmang();
};

void mang1chieu::taomang() {
    cout<<"Nhap so luong phan tu: "; cin>>n;
    for(int i = 0; i<n; i++) {
        cout<<"a [ "<<i<<" ] = "; cin>>a[i];
    }
    cout<<endl;
}

void mang1chieu::inmang() {
    for(int i = 0; i<n; i++) {
        cout<<a[i]<<"\t";
    }
}

void mang1chieu::minmax() {
    int max = a[0], min = a[0];
    for(int i = 0; i<n; i++) {
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }
    cout<<"Phan tu lon nhat: "<<max<<endl;
    cout<<"Phan tu nho nhat: "<<min<<endl;
}

void mang1chieu::saptang() {
    for(int i = 0; i<n-1; i++) {
        for(int j = i+1; j<n; j++) {
            if(a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    cout<<"Mang sau khi sx tang: ";
    inmang();
}

void mang1chieu::sapgiam() {
    for(int i = 0; i<n-1; i++) {
        for(int j = i+1; j<n; j++) {
            if(a[i] < a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    cout<<"Mang sau khi sx giam: ";
    inmang();
}

int mang1chieu::tongmang() {
    int tong = 0;
    for(int i = 0; i<n; i++) {
        tong += a[i];
    }
    return tong;
}

int main() {
    mang1chieu a;

    a.taomang();
    a.inmang();
    a.saptang();
    a.sapgiam();
    a.minmax();
    cout<<"Tong mang: "<<a.tongmang()<<endl;
    
    return 0;
}
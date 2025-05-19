#include <iostream>
using namespace std;

class hocsinh {
    private:
        string hoten, lop;
        float toan, ly, hoa;
    public:
        void nhap();
        void xuat();
        int trungbinh();
};

void hocsinh::nhap() {
    cin.ignore();
    cout<<"Nhap ho ten: "; getline(cin, hoten);
    cout<<"Nhap lop: "; getline(cin, lop);
    cout<<"Nhap diem toan: "; cin>>toan;
    cout<<"Nhap diem ly: "; cin>>ly;
    cout<<"Nhap diem hoa: "; cin>>hoa;
}

void hocsinh::xuat() {
    cout<<"Ho ten: "<<hoten<<",\t";
    cout<<"Lop: "<<lop<<",\t";
    cout<<"Diem toan: "<<toan<<",\t";
    cout<<"Diem ly: "<<ly<<",\t";
    cout<<"Diem hoa: "<<hoa<<",\t";
    cout<<"DTB = "<<trungbinh()<<"\t";
}

int hocsinh::trungbinh() {
    return ((toan+ly+hoa)/3);
}

int main() {
    int n;

    do {
        cout<<"Nhap so luong hoc sinh: "; cin>>n;
    } while(n<=0);

    hocsinh *hs = new hocsinh[n];

    for(int i = 0; i<n; i++) {
        cout<<"\nNhap thong tin hoc sinh thu "<<i+1<<": \n";
        hs[i].nhap();
    }

    cout<<"\nDANH SACH HS VUA NHAP LA\n";
    for(int i = 0; i<n; i++) {
        cout<<endl;
        hs[i].xuat();
    }

    delete [] hs;

    return 0;
}
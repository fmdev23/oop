#include <iostream>
using namespace std;

class cdcanhac {
    private:
        string tuade;
        int soluong, giatien;
    public:
        void nhap();
        void xuat();
        int slbai();
};

void cdcanhac::nhap() {
    cin.ignore();
    cout<<"Nhap tua de: "; getline(cin, tuade);
    cout<<"Nhap so luong: "; cin>>soluong;
    cout<<"Nhap gia tien: "; cin>>giatien;
}

void cdcanhac::xuat() {
    cout<<"Tua de: "<<tuade<<",\t";
    cout<<"So luong: "<<soluong<<",\t";
    cout<<"Gia tien: "<<giatien<<"\t";
}

int cdcanhac::slbai() {
    return soluong;
}

int main() {
    int n;
    cdcanhac cd[100];

    do {
        cout<<"Nhap so luong CD: "; cin>>n;
    } while(n<=0);

    for(int i = 0; i<n; i++) {
        cout<<"\nNhap thong tin CD "<<i+1<<":\n";
        cd[i].nhap();
    }

    cdcanhac max = cd[0];

    for(int i = 0; i<n; i++) {
        if(max.slbai() < cd[i].slbai()) {
            max = cd[i];
        }
    }

    cout<<"\nCD co so luong bai hat lon nhat la: \n";
    max.xuat();

    return 0;
}
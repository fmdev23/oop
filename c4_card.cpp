#include <iostream>
using namespace std;

class card {
    private:
        string tuade;
        string tacgia;
        int soluong;
    public:
        void nhap();
        void xuat();
        int getsoluong();
};

void card::nhap() {
    cin.ignore();
    cout<<"Nhap tua de: "; getline(cin, tuade);
    cout<<"Nhap tac gia: "; getline(cin, tacgia);
    cout<<"Nhap so luong: "; cin>>soluong;
}

void card::xuat() {
    cout<<"Tua de: "<<tuade<<",\t";
    cout<<"Tac gia: "<<tacgia<<",\t";
    cout<<"So luong: "<<getsoluong()<<"\t";
}

int card::getsoluong() {
    return soluong;
}

int main() {
    int n;
    card ds[100];

    do {
        cout<<"Nhap so luong sach: "; 
        cin>>n;
    } while (n<=0);

    for(int i = 0; i<n; i++) {
        cout<<"\nNhap thong tin sach "<<i+1<<": \n";
        ds[i].nhap();
    }

    card max = ds[0];

    for(int i = 0; i<n; i++) {
        if(max.getsoluong() < ds[i].getsoluong()) {
            max = ds[i];
        }
    }

    cout<<"Sach co so luong nhieu nhat la: "<<endl;
    max.xuat();

    return 0;
}
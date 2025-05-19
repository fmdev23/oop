#include <iostream>
using namespace std;

class sophuc {
    private:
        float thuc, ao;
    public:
        sophuc();
        void nhap();
        void xuat();
        sophuc cong(sophuc b);
        sophuc tru(sophuc b);
        sophuc nhan(sophuc b);
        sophuc chia(sophuc b);
};

sophuc::sophuc() {
    thuc = 0;
    ao = 0;
}

void sophuc::nhap() {
    cout<<"\nNhap phan thuc: "; cin>>thuc;
    cout<<"\nNhap phan ao: "; cin>>ao;
}

void sophuc::xuat() {
    cout << "(" << thuc << " + " << ao << "i)";
}

sophuc sophuc::cong(sophuc b) {
    sophuc kq;
    kq.thuc = thuc + b.thuc;
    kq.ao = ao + b.ao;
    return kq;
}

sophuc sophuc::tru(sophuc b) {
    sophuc kq;
    kq.thuc = thuc - b.thuc;
    kq.ao = ao - b.ao;
    return kq;
}

sophuc sophuc::nhan(sophuc b) {
    sophuc kq;
    kq.thuc = thuc * b.thuc - ao * b.ao;
    kq.ao = thuc * b.ao + ao * b.thuc;
    return kq;
}

sophuc sophuc::chia(sophuc b) {
    sophuc kq;
    float mau = b.thuc * b.thuc + b.ao * b.ao;
    kq.thuc = (thuc * b.thuc + ao * b.ao) / mau;
    kq.ao = (ao * b.thuc - thuc * b.ao) / mau;
    return kq;
}

int main() {
    sophuc a, b;
    a.nhap(); 
	cout<<"So phuc 1: "<<endl;
	a.xuat();
	
    b.nhap(); 
	cout<<"So phuc 1: "<<endl;
	b.xuat();

    sophuc tong = a.cong(b); 
    cout<<"tong: "<<endl;
    tong.xuat();
    
	sophuc hieu = a.tru(b); 
    cout<<"hieu: "<<endl;
    hieu.xuat();
    
	sophuc tich = a.nhan(b); 
    cout<<"nhan: "<<endl;
    tich.xuat();
    
	sophuc thuong = a.chia(b); 
    cout<<"chia: "<<endl;
    thuong.xuat();

    return 0;
}

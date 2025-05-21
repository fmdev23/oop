#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 101;

class dathuc {
    private:
        int bac;
        int doiso[MAX];
    public:
        dathuc();
        ~dathuc();

        friend istream& operator >> (istream& in, dathuc& dt);
        friend ostream& operator << (ostream& out, dathuc dt);

        dathuc operator+(dathuc& b);
        dathuc operator-(dathuc& b);
        dathuc operator!();
};

dathuc::dathuc() {
    bac = 0;
    for(int i = 0; i<MAX; i++) {
        doiso[i] = 0;
    }
}

dathuc::~dathuc() {

}

istream& operator >> (istream& in, dathuc& dt) {
    cout<<"\nNhap bac: "; in >> dt.bac;
    for(int i = dt.bac; i>=0; i--) {
        cout<<"\nHe so bac "<<i<<": ";
        in >> dt.doiso[i];
    }
    return in;
}

ostream& operator << (ostream& out, dathuc dt) {
    bool first = true;
    
    for(int i = dt.bac; i>=0; i--) {
        int hs = dt.doiso[i];
        if(hs == 0) continue;

        if(!first) {
            if(hs > 0) out << " + ";
            else out << " - ";
        } else {
            if(hs < 0) out << " - ";
        }

        int abs_hs = abs(hs);

        if(abs_hs != 1 || i == 0) out << abs_hs;

        if(i > 0) out << "x";
        if(i > 1) out << "^" << i;

        first = false;
    }

    if(first) out << "0";
    return out;
}

dathuc dathuc::operator+(dathuc& b) {
    dathuc kq;
    kq.bac = max(bac, b.bac);
    for(int i = 0; i<=kq.bac; i++) {
        kq.doiso[i] = doiso[i] + b.doiso[i];
    }

    while (kq.bac > 0 && kq.doiso[kq.bac] == 0) {
        kq.bac--;
    }

    return kq;
}

dathuc dathuc::operator-(dathuc& b) {
    dathuc kq;
    kq.bac = max(bac, b.bac);
    for(int i = 0; i<=kq.bac; i++) {
        kq.doiso[i] = doiso[i] - b.doiso[i];
    }

    while (kq.bac > 0 && kq.doiso[kq.bac] == 0) {
        kq.bac--;
    }

    return kq;
}

dathuc dathuc::operator!() {
    dathuc kq;
    if(bac == 0) {
        kq.bac = 0;
        kq.doiso[0] = 0;
        return kq;
    }

    kq.bac = bac - 1;
    for(int i = 1; i<=bac; i++) {
        kq.doiso[i-1] = doiso[i] * i;
    }

    return kq;
}

int main() {
    dathuc a, b;

    cout<<"Nhap da thuc a:\n"; cin>>a;
    cout<<"Nhap da thuc b:\n"; cin>>b;

    cout<<"\na(x) = " << a << endl;
    cout<<"b(x) = " << b << endl;

    cout<<"\na + b = "<<a+b<<endl;
    cout<<"\na - b = "<<a-b<<endl;
    cout<<"\nDao ham cua a = " << !a << endl;

    return 0;
}
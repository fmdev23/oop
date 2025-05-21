#include <iostream>
using namespace std;

class dathuc {
    private:
        int bac;
        int* heso;
    public:
        dathuc();
        dathuc(const dathuc& dt);
        dathuc& operator=(const dathuc& dt);
        ~dathuc();

        friend istream& operator>>(istream& in, dathuc& dt);
        friend ostream& operator<<(ostream& out, dathuc dt);
        friend dathuc operator+(const dathuc& dt1, const dathuc& dt2);
        friend dathuc operator-(const dathuc& dt1, const dathuc& dt2);

        dathuc daoham();
};

dathuc::dathuc() {
    bac = 0;
    heso = 0;
}

dathuc::dathuc(const dathuc& dt) {
    bac = dt.bac;
    heso = new int[bac + 1];
    for(int i = 0; i<=bac; i++) {
        heso[i] = dt.heso[i];
    }
}

dathuc& dathuc::operator=(const dathuc& dt) {
    if(this != &dt) {
        delete[] heso;
        bac = dt.bac;
        heso = new int[bac + 1];
        for(int i = 0; i<=bac; i++) {
            heso[i] = dt.heso[i];
        }
    }
    return *this;
}

dathuc::~dathuc() {
    delete[] heso;
}

istream& operator>>(istream& in, dathuc& dt) {
    cout<<"\nNhap bac: "; in >> dt.bac;

    delete[] dt.heso;

    dt.heso = new int[dt.bac + 1];

    for(int i = dt.bac; i>=0; i--) {
        cout<<"\nHe so bac "<<i<<"= ";
        in >> dt.heso[i];
    }
    return in;
}

ostream& operator<<(ostream& out, dathuc dt) {
    int dem = 0;
    for(int i = dt.bac; i>=0; i--) {
        if(dt.heso[i] != 0) {
            if(dem == 1 && dt.heso[i] > 0)
                out << " + ";
            out << dt.heso[i];
            if(i > 0)
                out << "x^" <<i<< " ";
            dem = 1;
        }
    }
    if(dem == 0) {
        out << "0";
    }
    return out;
}

dathuc operator+(const dathuc& a, const dathuc& b) {
    dathuc kq;
    if(a.bac > b.bac) {
        kq.bac = a.bac;
    } else {
        kq.bac = b.bac;
    }

    kq.heso = new int[kq.bac + 1];
    for(int i = 0; i<kq.bac; i++) {
        kq.heso[i] = 0;
        if(i <= a.bac)
            kq.heso[i] += a.heso[i];
        if(i <= b.bac)
            kq.heso[i] += b.heso[i];
    }

    for(int i = kq.bac; i>=0; i--) {
        if(kq.heso[i] != 0) {
            kq.bac = i;
            break;
        }
        if(i == 0)
            kq.bac = 0;
    }
    return kq;
}

dathuc operator-(const dathuc& a, const dathuc& b) {
    dathuc kq;
    if(a.bac > b.bac) {
        kq.bac = a.bac;
    } else {
        kq.bac = b.bac;
    }

    kq.heso = new int[kq.bac + 1];
    for(int i = 0; i<kq.bac; i++) {
        kq.heso[i] = 0;
        if(i <= a.bac)
            kq.heso[i] += a.heso[i];
        if(i <= b.bac)
            kq.heso[i] -= b.heso[i];
    }

    for(int i = kq.bac; i>=0; i--) {
        if(kq.heso[i] != 0) {
            kq.bac = i;
            break;
        }
        if(i == 0)
            kq.bac = 0;
    }

    return kq;
}

dathuc dathuc::daoham() {
    dathuc kq;
    if(bac == 0) {
        kq.bac = 0;
        kq.heso = new int[1];
        kq.heso[0] = 0;
        return kq;
    }

    kq.bac = bac - 1;
    kq.heso = new int[kq.bac + 1];
    for(int i = 1; i<=bac; i++) 
        kq.heso[i - 1] = heso[i] * i;
    return kq;
}

int main() {
    dathuc a, b;

    cout<<"\nNhap da thuc a: \n"; cin >> a;
    cout<<"\nNhap da thuc b: \n"; cin >> b;

    cout<<"\n A = " << a << endl;
    cout<<"\n B = " << b << endl;

    cout<<"\nA + B = "<<a+b<<endl;
    cout<<"\nA - B = "<<a-b<<endl;

    cout<<"\nDao ham cua A = "<<a.daoham()<<endl;

    return 0;
}
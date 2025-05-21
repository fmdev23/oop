#include <iostream>
using namespace std;

class matrix{
    private:
        int hang, cot;
        int **val;
    public:
        matrix();
        matrix(const matrix& m);
        matrix& operator=(const matrix& m);
        ~matrix();

        friend istream& operator>>(istream& in, matrix& m);
        friend ostream& operator<<(ostream& out, matrix m);

        friend matrix operator+(const matrix& a, const matrix& m);
        friend matrix operator-(const matrix& a, const matrix& m);
        friend matrix operator*(const matrix& a, const matrix& m);
};

matrix::matrix() {
    hang = 0;
    cot = 0;
}

matrix::matrix(const matrix& m) {
    hang = m.hang;
    cot = m.cot;
    val = new int*[hang];
    for(int i = 0; i<hang; i++) {
        val[i] = new int[cot];
        for(int j = 0; j<cot; j++) {
            val[i][j] = m.val[i][j];
        }
    }
}

matrix& matrix::operator=(const matrix& m) {
    if(this != &m) {
        for(int i = 0; i<hang; i++) delete[] val[i];
        delete[] val;
    }

    hang = m.hang;
    cot = m.cot;
    val = new int*[hang];
    for(int i = 0; i<hang; i++) {
        val[i] = new int[cot];
        for(int j = 0; j<cot; j++) {
            val[i][j] = m.val[i][j];
        }
    }
    return *this;
}

matrix::~matrix() {
    for(int i = 0; i<hang; i++) delete[] val[i];
    delete[] val;
    val = nullptr;
}

istream& operator>>(istream& in, matrix& m) {
    cout<<"\nNhap so hang: "; in >> m.hang;
    cout<<"\nNhap so cot: "; in >> m.cot;

    m.val = new int*[m.hang];
    for(int i = 0; i<m.hang; i++) {
        m.val[i] = new int[m.cot];
        for(int j = 0; j<m.cot; j++) {
            cout<<"\nNhap [" << i << "][" << j << "] = ";
            in >> m.val[i][j];
        }
    }

    return in;
}

ostream& operator<<(ostream& out, matrix m) {
    for(int i = 0; i<m.hang; i++) {
        for(int j = 0; j<m.cot; j++) {
            out << m.val[i][j] << "\t";
        }
        out << endl;
    }
    return out;
}

matrix operator+(const matrix& a, const matrix& m) {
    matrix c;
    if(a.hang != m.hang || a.cot != m.cot) {
        cout<<"LOI";
        return c;
    }

    c.hang = a.hang;
    c.cot = a.cot;
    c.val = new int*[c.hang];
    for(int i = 0; i < c.hang; i++) {
        c.val[i] = new int[c.cot];
        for(int j = 0; j<c.cot; j++) {
            c.val[i][j] = a.val[i][j] + m.val[i][j];
        }
    }

    return c;
}

matrix operator-(const matrix& a, const matrix& m) {
    matrix c;
    if(a.hang != m.hang || a.cot != m.cot) {
        cout<<"LOI";
        return c;
    }

    c.hang = a.hang;
    c.cot = a.cot;
    c.val = new int*[c.hang];
    for(int i = 0; i<c.hang; i++) {
        c.val[i] = new int[c.cot];
        for(int j = 0; j<c.cot; j++) {
            c.val[i][j] = a.val[i][j] - m.val[i][j];
        }
    }
    return c;
}

matrix operator*(const matrix& a, const matrix& m) {
    matrix c;
    if(a.cot != m.hang) {
        cout<<"LOI";
        return c;
    }

    c.hang = a.hang;
    c.cot = m.cot;
    c.val = new int*[c.hang];
    for(int i = 0; i<c.hang; i++) {
        c.val[i] = new int[c.cot];
        for(int j = 0; j<c.cot; j++) {
            c.val[i][j] = 0;
            for(int k = 0; k<a.cot; k++) {
                c.val[i][j] += a.val[i][k] * m.val[k][j];
            }
        }
    }
    return c;
}

int main() {
    matrix a, b, c;

    cout<<"\nNhap ma tran a: "; cin >> a;
    cout<<"\nNhap ma tran b: "; cin >> b;

    cout<<"\nMa tran A = \n" << a;
    cout<<"\nMa tran B = \n" << b;

    cout<<"\nTong 2 ma tran: \n" << a+b << endl;
    cout<<"\nHieu 2 ma tran: \n" << a-b << endl;

    cout<<"\nNhap ma tran c: "; cin >> c;
    cout<<"\nTich ma tran A va C la: \n" << a*c << endl;

    return 0;
}
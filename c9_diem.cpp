#include <iostream>
#include <cmath>
using namespace std;

class diem {
    private:
        float x, y;
    public:
        diem(float x = 0, float y = 0);
        ~diem();

        friend istream& operator >> (istream& in, diem& u);
        friend ostream& operator << (ostream& out, diem u);

        friend float chuvi(diem& a, diem& b, diem& c);
        friend float dientich(diem& a, diem& b, diem& c);
};

diem::diem(float x, float y) {
    this->x = x;
    this->y = y;
}

diem::~diem() {

}

istream& operator >> (istream& in, diem& u) {
    cout<<"Nhap hoanh do: "; in >> u.x;
    cout<<"Nhap tung do: "; in >> u.y;
    return in;
}

ostream& operator << (ostream& out, diem u) {
    out << "( " << u.x << " , " << u.y << " )";
    return out;
}

float chuvi(diem& a, diem& b, diem& c) {
    float ab = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    float bc = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));
    float ca = sqrt(pow(c.x - a.x, 2) + pow(c.y - a.y, 2));
    return ab+bc+ca;
}

float dientich(diem& a, diem& b, diem& c) {
    float ab = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    float bc = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));
    float ca = sqrt(pow(c.x - a.x, 2) + pow(c.y - a.y, 2));
    float p = (ab+bc+ca) / 2;
    return sqrt((p * (p-ab) * (p-bc) * (p-ca)));
}

int main() {
    diem a, b, c;

    cout<<"\nNhap a: "; cin>>a;
    cout<<"\nNhap b: "; cin>>b;
    cout<<"\nNhap c: "; cin>>c;

    cout<<"\n3 diem vua nhap";
    cout<<"\ta = "<<a;
    cout<<"\tb = "<<b;
    cout<<"\tc = "<<c;

    cout<<"\nChu vi = "<<chuvi(a,b,c)<<endl;
    cout<<"\nDien tich = "<<dientich(a,b,c)<<endl;

    return 0;
}
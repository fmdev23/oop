#include <iostream>
using namespace std;

class gio {
	private:
		int h, m, s;
	public:
		gio(int hh = 0, int mm = 0, int ss = 0);
		void nhap();
		int hople(); //kiem tra gio hop le
		void xuat24(); // xuat gio theo 24 tieng
		void xuat12(); // xuat gio theo 12 tieng
		void tanggiay(int n); //tang gio len n giay
		gio cong(const gio &u); //cong hai gio
		gio tru(const gio &u); //tru hai gio
};

gio::gio(int hh, int mm, int ss) {
	h = hh;
	m = mm;
	s = ss;
}

void gio::nhap() {
    cout << "Nhap gio, phut, giay: ";
    cin >> h >> m >> s;
}

int gio::hople() {
	return h>=0 && h<24 && m>=0 && m<60 && s>=0 && s<60;
}

void gio::xuat24() {
	cout<<h<< ":" <<m<< ":" <<s<< endl;
}

void gio::xuat12() {
	int hh = h % 12;
	if(hh == 0) hh = 12;
	cout<<hh<<":"<<m<<":"<<s<<(h<12 ? " AM" : " PM") << endl;
}

void gio::tanggiay(int n) {
    s += n;
    m += s / 60;
    s %= 60;
    h += m / 60;
    m %= 60;
    h %= 24;
}

gio gio::cong(const gio &u) {
    gio kq;
    kq.s = s + u.s;
    kq.m = m + u.m + kq.s / 60;
    kq.s %= 60;
    kq.h = h + u.h + kq.m / 60;
    kq.m %= 60;
    kq.h %= 24;
    return kq;
}

gio gio::tru(const gio &u) {
    gio kq;
    int t1 = h * 3600 + m * 60 + s;
    int t2 = u.h * 3600 + u.m * 60 + u.s;
    int kc = t1 - t2;
    if (kc < 0) kc += 24 * 3600;
    kq.h = kc / 3600;
    kq.m = (kc % 3600) / 60;
    kq.s = kc % 60;
    return kq;
}

int main() {
	gio g1, g2;
    
    cout << "Nhap gio thu nhat:\n";
    g1.nhap();
    
    cout << "Nhap gio thu hai:\n";
    g2.nhap();
    
    cout << "Gio thu nhat: ";
    g1.xuat24();
    
    cout << "Gio thu hai: ";
    g2.xuat24();

    int n;
    cout << "Nhap so giay muon tang: ";
    cin >> n;
    g1.tanggiay(n);
    cout << "Gio sau khi tang " << n << " giay: ";
    g1.xuat24();

    gio g3 = g1.cong(g2);
    cout << "Tong hai gio: ";
    g3.xuat24();

    gio g4 = g1.tru(g2);
    cout << "Hieu hai gio: ";
    g4.xuat24();
	
	return 0;
}

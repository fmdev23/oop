#include <iostream>
using namespace std;

class ngay {
	private:
		int d, m, y;
	public:
		ngay(int dd = 1, int mm = 1, int yy = 1);
		void nhap(); void xuat(); int nhuan();	//kiem tra nam nhuan
		int sntrongthang();
		int hople();
		void tangngay();
		void giamngay();
		void tangtuan();
		void giamtuan();
};

ngay::ngay(int dd, int mm, int yy) {
    d = dd;
    m = mm;
    y = yy;
}

void ngay::nhap() {
    cout << "Nhap ngay, thang, nam: ";
    cin >> d >> m >> y;
}

void ngay::xuat() {
    cout << d << "/" << m << "/" << y << endl;
}

int ngay::nhuan() {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int ngay::sntrongthang() {
    int days[] = {31, 28 + nhuan(), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[m - 1];
}

int ngay::hople() {
    return (m >= 1 && m <= 12 && d >= 1 && d <= sntrongthang());
}

void ngay::tangngay() {
    d++;
    if (d > sntrongthang()) {
        d = 1;
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }
}

void ngay::giamngay() {
    d--;
    if (d < 1) {
        m--;
        if (m < 1) {
            m = 12;
            y--;
        }
        d = sntrongthang();
    }
}

void ngay::tangtuan() {
    for (int i = 0; i < 7; i++) tangngay();
}

void ngay::giamtuan() {
    for (int i = 0; i < 7; i++) giamngay();
}


int main() {
	ngay a;
    a.nhap();
    a.xuat();
    
    if(a.nhuan() == 1) {
    	cout<<"La nam nhuan\n";
	} else {
		cout<<"Khong la nam nhuan\n";
	}

    cout << "So ngay trong thang: " << a.sntrongthang() << endl;

    if(a.hople() == 1) {
    	cout<<"Ngay hop le\n";
	} else {
		cout<<"Ngay khong hop le\n";
	}
	
	return 0;
}

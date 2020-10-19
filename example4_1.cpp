#include<iostream>
#include<math.h>
/*
ʵ��Բ׶����taper��
���й��캯��������뾶���ߣ������������������������ȹ���
*/
using namespace std;
const double pi = 3.14159;
class Taper {
public:
	Taper(double r = 0, double h = 0) { R = r; H = h; }
	double sideArea() { return pi*R*sqrt(H*H + R*R); }
	double surface() { return sideArea() + pi*R*R; }
	double volume() { return pi*R*R*H / 3; }
	double getR() { return R; }
	double getH() { return H; }
private:
	double R, H;
};
void main() {
	Taper a(1,3), b(2,2);
	cout << "Բ׶a��R=" << a.getR() << " H=" << a.getH() << endl;
	cout << "�����=" << a.sideArea() << " �����=" << a.surface() << " ���" << a.volume() << endl;
	cout << "Բ׶b��R=" << b.getR() << " H=" << b.getH() << endl;
	cout << "�����=" << b.sideArea() << " �����=" << b.surface() << " ���" << b.volume() << endl;
}
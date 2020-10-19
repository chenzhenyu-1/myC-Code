#include<iostream>
#include<math.h>
/*
实现圆锥体类taper。
具有构造函数（底面半径、高）、计算侧面积、表面积和体积等功能
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
	cout << "圆锥a：R=" << a.getR() << " H=" << a.getH() << endl;
	cout << "侧面积=" << a.sideArea() << " 表面积=" << a.surface() << " 体积" << a.volume() << endl;
	cout << "圆锥b：R=" << b.getR() << " H=" << b.getH() << endl;
	cout << "侧面积=" << b.sideArea() << " 表面积=" << b.surface() << " 体积" << b.volume() << endl;
}
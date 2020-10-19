#include <iostream>
using namespace std;

template<typename T> T mymax(T a, T b) {    //函数模板定义（两个参数）
	return a>b ? a : b;
}

template<class T> T mymax(T a, T b, T c) {   //重载函数模板（三个参数）
	if (a>b) return mymax(a, c);
	else return mymax(b, c);
}

class complex {      //自定义复数类
	float r, i;     //实部和虚部数据成员
public:
	complex(float rr = 0, float ii = 0) { r = rr; i = ii; }    //构造函数
	bool operator >(complex &c) {          //自定义复数类型的“>”运算符重载
		if (r*r + i*i>c.r*c.r + c.i*c.i) return true; else return false;
	}
	float getr() { return r; }    //返回复数的实部
	float geti() { return i; }    //返回复数的虚部
};

void main()
{
	complex c1(2, 4), c2(1, 3), c3(2, 5), c;
	cout << mymax<int>(10, 20.5) << endl;   //强制实例化，可解决参数不匹配的问题。去掉<int>后会出现什么情况？
	cout << mymax(50.5, 28.5) << endl;      //通过实参,系统可确定T为double型
	cout << mymax('d', 't') << endl;        //通过实参,系统可确定T为char型
	cout << mymax(30, 40, 50) << endl;
	cout << mymax(101.3, 200.4, 156.9) << endl;
	c = mymax(c1, c2, c3);                 //通过实参,系统可确定T为complex型
	cout << "(" << c.getr() << "," << c.geti() << ")" << endl;
}

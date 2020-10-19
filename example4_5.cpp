#include<iostream>
/*
构造一个复数类complex，所有的数据成员为私有属性，
为复数类complex定义友元函数，重载运算符+,实现复数的加法运算；
定义一个成员函数，重载运算符-,实现复数的减法运算。并调用验证。
*/
using namespace std;
class Complex
{
public:
	Complex() { real = 0; img = 0; }
	Complex(float a, float b) { real = a; img = b; }
	friend Complex operator +(Complex a,Complex b);
	Complex operator -(Complex a) { return Complex(real - a.real, img - a.img); }
	void show() { cout << "(" << real << "," << img << ")"; }
private:
	float real, img;
};

Complex operator +(Complex a, Complex b)
{
	Complex s(a.real + b.real, a.img + b.img);
	return s;
}

void main() {
	Complex c1(2, 4), c2(3, 5);
	c1.show(); cout << "+"; c2.show(); cout << "="; (c1 + c2).show(); cout << endl;
	c2.show(); cout << "-"; c1.show(); cout << "="; (c2 - c1).show(); cout << endl;
}
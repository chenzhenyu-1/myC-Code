#include<iostream>
/*
定义一个复数类，并重载运算符：+、*、<<、>>，使它们能运用于该复数类
*/
using namespace std;

class complex//定义复数类
{
public:
	complex() { rel = 0; img = 0; }
	complex(double a, double b) { rel = a; img = b; }
	complex operator +(complex);//重载运算符+
	complex operator *(complex);//重载运算符*
	friend ostream & operator << (ostream &, complex &);//声明<<为友元函数，以便访问复数类的私有成员
	friend istream & operator >> (istream &, complex &);//声明>>为友元函数，以便访问复数类的私有成员

private:
	int rel, img;//rel代表实部，img代表虚部

};

complex complex::operator+(complex x){
	x.rel = rel + x.rel;
	x.img = img + x.img;
	return x;
}

complex complex::operator*(complex x) {
	x.rel = rel*x.rel;
	x.img = img*x.img;
	return x;
}

ostream & operator << (ostream & out, complex & x) {//重载<<运算符以适用于复数类
	if(x.img>=0)//判断虚部正负，实现输出形式为：a+bi或a-bi
		out << x.rel << "+" << x.img << "i";
	else
		out << x.rel << x.img << "i";
	return out;
}

istream & operator >> (istream & in, complex & x) {//重载>>运算符以适用于复数类
	char a[20];
	in >> a;//输入复数的形式为a+bi或a-bi，先保存为字符数组
	int i = 0;
	while (a[i]!='i') {//把+号（或-号）前的字符转为实部的值，把后面的字符转为虚部的值
		if (a[i] == '+') {
			i++;
			x.img = x.img*10*i+a[i] - 48;
		}
		else if (a[i] == '-') {
			i++;
			x.img = x.img * 10 * i + a[i] - 48;
			x.img = -x.img;
		}
		else
		{
			x.rel =x.rel*10*i+a[i] - 48;
		}
		i++;
	}
	return in;
}

int main() {
	complex a(2, -4), b(0, 3),c,d,e;
	c = a + b;
	d = c*a;
	cout << c << endl;
	cout << d << endl;
	cin >> e;
	cout << e << endl;
}
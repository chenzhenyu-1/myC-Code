#include<iostream>
/*
��дһ����ʵ�ֶ����������������������ǰ�úͺ�������++�����أ�
ʹ֮�ܶԸ������������ýṹ���ͽ��б�ʾ�ʹ洢���������㡣
������ǰ�úͺ������������++���������������Ϊ������ʵ�����鲿������1��
ע��ǰ�úͺ�������������������𡣣�
*/
using namespace std;
struct Complex {
	double re, im;
};
Complex operator+(Complex a, Complex b)
{
	Complex s;
	s.re = a.re + b.re;
	s.im = a.im + b.im;
	return s;
}
Complex operator-(Complex a, Complex b)
{
	Complex s;
	s.re = a.re - b.re;
	s.im = a.im - b.im;
	return s;
}
Complex operator++(Complex &a)
{
	a.re++; a.im++;
	return a;
}
Complex operator++(Complex &a,int)
{
	Complex temp;
	temp = a;
	a.re++; a.im++;
	return temp;
}
Complex operator--(Complex &a)
{
	a.re--; a.im--;
	return a;
}
Complex operator--(Complex &a, int)
{
	Complex temp;
	temp = a;
	a.re--; a.im--;
	return temp;
}
ostream & operator<<(ostream & os, const Complex & c)
{
	if (c.im < 0)
		if (c.im == -1)
			os << c.re << "-" << "i";
		else
			os << c.re << c.im << "i";
	else
		if (c.im == 1)
			os << c.re << "+" << "i";
		else
			os << c.re << "+" << c.im << "i"; 
	return os;
}
void main() {
	Complex n, m, a, b;
	n = { 2,3 };
	m = { 0,4 };
	cout << "n=" << n << ";   m=" << m << endl
		<< "n+m=" << n + m << ";  n-m=" << n - m << endl;
	a = n++;
	b = ++n;
	cout << "a=" << a << ";   a=" << b << endl;
	a = --m;
	b = m--;
	cout << "a=" << a << ";   a=" << b << endl;
}
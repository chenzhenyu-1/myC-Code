#include<iostream>
#include<string.h>
using namespace std;
void f1(int* p, int* q) {
	p = new int;
	*p = 66;	*q = 66;
	cout << "*p,*q=>" << *p << "," << *q << endl;
}
void f2(char* s) {
	cout << "s+2=>" << s + 2 << endl;
	char a[20] = "C++ Programming!";
	s = a;
	cout << "s=>" << s << endl;
}
void main() {
	int a = 2, b = 5;
	f1(&a, &b);
	cout << "a,b=>" << a << "," << b << endl;
	char e[10] = "123abc#";
	cout << "e=>" << e << endl;
	f2(e);
	cout << "e=>" << e << endl;
}

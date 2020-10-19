#include<iostream>
using namespace std;

int main() {
	int i = 77; double d = 8765.56789;
	cout << i << "(10)=";
	cout.setf(ios::showbase);
	cout.setf(ios::oct,ios::basefield);
	cout << i << "(8)=";
	cout.setf(ios::hex,ios::basefield);
	cout << i << "(16)" << endl;
	cout.setf(ios::fixed); cout.fill('#'); cout.precision(1);
	cout.width(10);
	cout << d << endl;
	cout.setf(ios::left);
	cout.width(10);
	cout << d << endl;
	cout.precision(5);
	cout << d << endl;
	cout.flags(ios::scientific);
	cout.precision(9); cout.setf(ios::uppercase);
	cout << d << endl;
	return 0;
}
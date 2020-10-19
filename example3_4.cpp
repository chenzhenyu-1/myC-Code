#include<iostream>
using namespace std;
int k = 56;
void f1(int a, int& b) {
	cout << "In f1:a,b=>" << a << "," << b << endl;
	a += 10; b += 10;
}
int& f2(int& a, int& b) {
	cout << "In f2:a+b=>" << a + b << endl;
	if ((a + b) % 2 == 0)return a;
	else return b;
}
void main() {
	int x = 1, y = 2, z = 3, w = 0;
	f1(x, y);
	cout << "main1:x,y=>" << x << "," << y << endl;
	cout << "main1:z,k,w=>" << z << "," << k << "," << w << endl;
	w = f2(z, k)++;
	cout << "main2:z,k,w=>" << z << "," << k << "," << w << endl;
	w = f2(z, k)++;
	cout << "main3:z,k,w=>" << z << "," << k << "," << w << endl;
}
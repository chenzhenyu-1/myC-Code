// program8_1.cpp 
# include<iostream>
using namespace std;
class CA {
	int a;
public:
	CA(int n) { a = n; cout << "CA::a=" << a << endl; };
	~CA() { cout << "CAobj is destructing." << endl; };
};
class CB {
	int b;
public:
	CB(int n) { b = n; cout << "CB::b=" << b << endl; };
	~CB() { cout << "CBobj is destructing." << endl; };
};
class CC :public CA {
	int c;
public:
	CC(int n1, int n2) :CA(n2) { c = n1; cout << "CC::c=" << c << endl; };
	~CC() { cout << "CCobj is destructing" << endl; };
};
class CD :public CB, public CC {
	int d;
public:
	CD(int n1, int n2, int n3, int n4) :CC(n3, n4), CB(n2) {
		d = n1; cout << "CD::d=" << d << endl;
	};
	~CD() { cout << "CDobj is destructing" << endl; };
};

void main(void) {
	CD CDobj(2, 4, 6, 8);
}
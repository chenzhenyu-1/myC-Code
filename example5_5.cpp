# include<iostream>
using namespace std;

class baseCla {
public:
	virtual double fib(int n) = 0;
};

class fib1Cla :public baseCla {
public:
	virtual double fib(int n);
};

double fib1Cla::fib(int n){//数据平移法
	double a, b, temp;
	a = 1; b = 1;
	for (int i = 0; i < n-2; i++) {
		temp = a + b;
		a = b;
		b = temp;
	}
	return b;
}

class fib2Cla :public baseCla {
public:
	virtual double fib(int n);
};

double fib2Cla::fib(int n) {//数组求解
	double *s,r;
	s = new double[n];
	*s = 1; *(s + 1) = 1;
	int i;
	for (i = 0; i < n - 2; i++) {
		*(s + i + 2) = *(s + i) + *(s + i + 1);
	}
	r = *(s + n - 1);
	delete[] s;
	return r;
}

class fib3Cla :public baseCla {
public:
	virtual double fib(int n);
};

double fib3Cla::fib(int n) {//递归求解
	if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

void fun(baseCla *p, int n) {
	double d = p->fib(n);
	cout.flags(ios::scientific);
	cout.precision(15);
	cout << "fib(" << n << ")=" << d << endl;
}

int main() {
	fib1Cla obj1;
	fib2Cla obj2;
	fib3Cla obj3;
	cout << "-----------fib1Cla------------" << endl;
	fun(&obj1, 1476);
	cout << "-----------fib2Cla------------" << endl;
	fun(&obj2, 888);
	cout << "-----------fib3Cla------------" << endl;
	fun(&obj3, 35);
}
#include <iostream>
using namespace std;
void swap(const int& a, int& b, int *c, int *d, int e, int f);
void main() {
	int i = 10, j = 20, k = 30, m = 40, n = 50, p = 60;
	swap(i, j, &k, &m, n, p);
	cout << "i,j,k,m,n,p=" << i << " " << j << " " << k << " " << m << " " << n << " " << p << endl;
}
void swap(int& a, int& b, int *c, int *d, int e, int f)
{
	int tmp;
	tmp = a;  a = b;  b = tmp;
	tmp = *c; *c = *d; *d = tmp;
	tmp = e;  e = f;  f = tmp;
	cout << "a,b,c,d,e,f=" << a << " " << b << " " << *c << " " << *d << " " << e << " " << f << endl;
}

#include<iostream>
using namespace std;
void split(double x, int *iPart, double *fPart) {
	*iPart = int(x);
	*fPart = x - *iPart;
}
double f(double *a, int n) {
	int i, intPt;
	double fracPt, maxfracPt = 0;
	for (i = 0; i < n; i++) {
		split(*(a + i), &intPt, &fracPt);
		if (fracPt > maxfracPt)
			maxfracPt = fracPt;
		*(a + i) = intPt;
	}
	return maxfracPt;
}
void main() {
	int i;
	double maxfr, a[6] = { 1.1,2.2,3.3,9.9,6.6,5.0 };
	maxfr = f(a, 6);
	cout << "After call f,a[0..5]=";
	for (i = 0; i < 6; i++) cout << a[i] << " ";
	cout << "\nmaxfr=" << maxfr << endl;
}
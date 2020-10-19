#include<iostream>
using namespace std;
void main(void) {
	int a[10] = { 10,11,12 };
	int *p = a, *q = &a[9];
	*(p + 3) = 13; *(q - 5) = *(p + 3) + 1;
	for (int i = 5; i < 10; i++)
		*(p + i) = 80 + i;
	cout << "*(p+2)=" << *(p + 2) << endl;
	cout << "*(&a[8])=" << *(&a[8]) << endl;
	for (int i = 3; i < 8; i++)
		cout << *(a + i) << " ";
	cout << "\nq-a=" << q - a << endl;
	cout << "q-p=" << q - p << endl;
	while (q > &a[4])
		cout << *q-- << " ";
	cout << "\nq-a=" << q - a << endl;
}
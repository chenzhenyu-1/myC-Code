#include<iostream>
using namespace std;

template<class Type>void sort(Type *A, int n) {
	for (int j = n; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			Type temp;
			if (*(A + i) < *(A + i + 1)) {
				temp = *(A + i + 1);
				*(A + i + 1) = *(A + i);
				*(A + i) = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << A[i] << ",";
	}
	cout << endl;
}

int main() {
	int a[5] = { 0,3,1,2,6 };
	sort(a, 5);
	float b[7] = { 1.2,5.3,2.0,1.1,9.2,10.0,7.2 };
	sort(b, 7);
	char c[10] = "sVfhFwTum";
	sort(c, 10);
}
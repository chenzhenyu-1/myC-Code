#include<iostream>
using namespace std;
#define N 4
#define M 4
void main() {
	int a[N][M] = {0}, (*p)[M], *pa;
	pa = a[0];
	p = a;
	for (int i = 0; i < N*M; i++) {
		*pa = 2*i+1;
		pa++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << *(*p+j) << " ";
		p++; cout << endl;
	}
}
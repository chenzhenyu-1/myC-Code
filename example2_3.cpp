#include <iostream>
using namespace std;
void conv(int n) {
	if (n<10) { cout << n << endl; return; }
	cout << n % 10;
	conv(n / 10); //�ݹ����
}

void main() {
	int t;
	cin >> t;
	conv(t);
}

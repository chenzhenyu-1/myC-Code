#include <iostream>
#include <math.h>
#include <bitset>
using namespace std;
void main() {
	unsigned int num;
	int k;
	cout << "������һ���޷���������" << endl;
	cin >> num;
	cout << "��Ӧ���������ǣ�" << (bitset<16>)num << endl;
	cout << "������kֵ��" << endl;
	cin >> k;
	cout << "�����" << k << "λ����������ǣ�" << endl;
	k = pow(2, k - 1);
	k = ~k;
	num = num & k;
	cout << (bitset<16>)num << endl;
}
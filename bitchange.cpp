#include <iostream>
#include <math.h>
#include <bitset>
using namespace std;
void main() {
	unsigned int num;
	int k;
	cout << "请输入一个无符号整数：" << endl;
	cin >> num;
	cout << "对应二进制数是：" << (bitset<16>)num << endl;
	cout << "请输入k值：" << endl;
	cin >> k;
	cout << "清零第" << k << "位数后二进制是：" << endl;
	k = pow(2, k - 1);
	k = ~k;
	num = num & k;
	cout << (bitset<16>)num << endl;
}
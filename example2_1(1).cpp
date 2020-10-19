#include<iostream>
/*
编写一个函数实现将一个十进制正整数n化为x进制数（x为2~16的整数），
函数原型可设计为：void Chg10Tox(unsigned long n,int x)，
并编写主函数验证其正确性。
提示：采用逐次除x取余数，余数倒序输出法。
*/
using namespace std;
void Chg10Tox(unsigned long n, int x) {
	int a[64] = { 0 }, i = 0, flag;
	if (x > 16 | x < 2) {
		cout << "error！x为2-16的数." << endl;
		return;
	}
		cout << "10进制数:" << n << endl
			<< "转换为" << x << "进制数的结果是：" << endl;
		for (; n > 0;) {
			flag = n % x;
			if (flag >= 10) {
				flag = flag % 10;
				switch (flag)
				{
				case 0: a[i] = 'A'; break;
				case 1: a[i] = 'B'; break;
				case 2: a[i] = 'C'; break;
				case 3: a[i] = 'D'; break;
				case 4: a[i] = 'E'; break;
				case 5: a[i] = 'F'; break;
				}
			}
			else
				a[i] = flag;
			i++;
			n = n / x;
		}
		for (; i > 0; i--)
			if (a[i - 1] <= 70 & a[i - 1] >= 65)
				cout << (char)a[i - 1];
			else
				cout << a[i - 1];
		cout << endl;
}
void main() {
	unsigned long n;
	int x;
	cout << "Input n:" << endl; cin >> n;
	cout << "Input x:" << endl; cin >> x;
	Chg10Tox(n, x);
}
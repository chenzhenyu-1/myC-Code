#include<iostream>
/*
��дһ������ʵ�ֽ�һ��ʮ����������n��Ϊx��������xΪ2~16����������
����ԭ�Ϳ����Ϊ��void Chg10Tox(unsigned long n,int x)��
����д��������֤����ȷ�ԡ�
��ʾ��������γ�xȡ���������������������
*/
using namespace std;
void Chg10Tox(unsigned long n, int x) {
	int a[64] = { 0 }, i = 0, flag;
	if (x > 16 | x < 2) {
		cout << "error��xΪ2-16����." << endl;
		return;
	}
		cout << "10������:" << n << endl
			<< "ת��Ϊ" << x << "�������Ľ���ǣ�" << endl;
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
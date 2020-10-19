#include<iostream>
/*
编写一个函数实现将一个x进制正整数化为十进制数（x为2~16的整数），函数原型可设计为：long ChgxTo10(char a[],int x)，
其中参数a数组用于保存x进制数的各数码，并编写主函数验证其正确性。
提示：采用按权展开求和法（各数码乘以它的权重，并求和）。
注意要检查x进制数各数码的合法性。
*/
using namespace std;
int ChgxTo10(char a[], int x) {
	int i = 0, j = 0, sum = 0, count;
	while (a[i]) {
		if (x >= 2 && x <= 16) //限制x在2-16的范围
			if ((int)a[i]>=48&&(int)a[i]<=57||(int)a[i]>=65&&(int)a[i]<=70) //限制输入的n在48-57和65-70的范围
				if ((int)a[i] < x + 48) {
					i++; continue;
				} 
				//当a[i]是数字时，判断是否超出进制所要求的数
				else if ((int)a[i] < x + 55 && (int)a[i] > 64 ) {
					i++; continue;
				} 
				//当a[i]是字符是，判断是否超出进制所要求的数
		cout << "Error input!" << endl;
		return 1;
	}
	cout << x << "进制数：" << a << endl;
	count = i;
	i--;
	while (j<count) {
		if (a[i] < 58)
			sum = sum + ((int)a[i] - 48) * pow(x, j);
		else
			sum = sum + ((int)a[i] - 55)*pow(x, j);
		i--;
		j++;
	}
	cout << "转换为10进制数为：" << sum << endl;
	return 0;
}
void main() {
	int x, i = 0;
	char a[64];
	cout << "Input x:" << endl; cin >> x;
	cout << "Input n:" << endl; cin >> a;
	ChgxTo10(a, x);
}
#include<iostream>
/*
��дһ������ʵ�ֽ�һ��x������������Ϊʮ��������xΪ2~16��������������ԭ�Ϳ����Ϊ��long ChgxTo10(char a[],int x)��
���в���a�������ڱ���x�������ĸ����룬����д��������֤����ȷ�ԡ�
��ʾ�����ð�Ȩչ����ͷ����������������Ȩ�أ�����ͣ���
ע��Ҫ���x������������ĺϷ��ԡ�
*/
using namespace std;
int ChgxTo10(char a[], int x) {
	int i = 0, j = 0, sum = 0, count;
	while (a[i]) {
		if (x >= 2 && x <= 16) //����x��2-16�ķ�Χ
			if ((int)a[i]>=48&&(int)a[i]<=57||(int)a[i]>=65&&(int)a[i]<=70) //���������n��48-57��65-70�ķ�Χ
				if ((int)a[i] < x + 48) {
					i++; continue;
				} 
				//��a[i]������ʱ���ж��Ƿ񳬳�������Ҫ�����
				else if ((int)a[i] < x + 55 && (int)a[i] > 64 ) {
					i++; continue;
				} 
				//��a[i]���ַ��ǣ��ж��Ƿ񳬳�������Ҫ�����
		cout << "Error input!" << endl;
		return 1;
	}
	cout << x << "��������" << a << endl;
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
	cout << "ת��Ϊ10������Ϊ��" << sum << endl;
	return 0;
}
void main() {
	int x, i = 0;
	char a[64];
	cout << "Input x:" << endl; cin >> x;
	cout << "Input n:" << endl; cin >> a;
	ChgxTo10(a, x);
}
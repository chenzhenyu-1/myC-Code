#include<iostream>
/*
��дһ������ʵ�����þ��ι�ʽ������һ��һԪ�����ڱ�����[a,b]�ϵĶ����֣�
����д���������е�����֤��
*/
using namespace std;
float f(float x) {
	return 3*x*x + 1;
}
double definite_integral(float (*p)(float), float a, float b) {
	float n = 1000, sum = 0;
	float eps = (b - a) / n;
	for (int i = 0; i < n; i++) {
		sum += p(a + eps*i)*eps;
	}
	return sum;
}
void main() {
	float a=2.3, b=3.03;
	cout << "f(x)=3*x^2+1�Ķ����֣�����������" << b << "��" << a << "����" << endl;
	cout << "��ȷֵ��" <<b*b*b+b-a*a*a-a<< endl;
	cout << "����ֵ:" << definite_integral(&f, a, b) << endl;
}
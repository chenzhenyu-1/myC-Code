#include <iostream>
#include <math.h>
using namespace std;
unsigned long num, res,front,after;
int k;
void main() {
	cout << "������һ���޷���������";cin >> num;
	cout << "������Kֵ��"; cin >> k;
	front = pow(10, k - 1);
	after = pow(10, k);
	res = num % front + (num / after) * front;
	cout <<"�����"<<k<<"λ����Ϊ��"<< res << endl;
}
#include <iostream>
using namespace std;
int g = 100;//ȫ�ֱ���
void f(int g, int x) {
	static int y = 150;//��̬�ֲ��������ص㣺���ͷţ�ֻ��ʼ��һ�Σ�ǰ�ε�ֵӰ����������
	::g += 10;//������ֲ�����ͬ����ȫ�ֱ���g
	y += 10;
	cout << "g=" << g << ",x=" << x << ",y=" << y << ",::g=" << ::g << endl;
}
void main() {
	int a = 200;
	cout << "First:"; f(g, a);
	a += 10; g += 10;
	cout << "Second:"; f(g, a);
}

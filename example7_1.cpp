#include<iostream>
/*
����һ�������࣬�������������+��*��<<��>>��ʹ�����������ڸø�����
*/
using namespace std;

class complex//���帴����
{
public:
	complex() { rel = 0; img = 0; }
	complex(double a, double b) { rel = a; img = b; }
	complex operator +(complex);//���������+
	complex operator *(complex);//���������*
	friend ostream & operator << (ostream &, complex &);//����<<Ϊ��Ԫ�������Ա���ʸ������˽�г�Ա
	friend istream & operator >> (istream &, complex &);//����>>Ϊ��Ԫ�������Ա���ʸ������˽�г�Ա

private:
	int rel, img;//rel����ʵ����img�����鲿

};

complex complex::operator+(complex x){
	x.rel = rel + x.rel;
	x.img = img + x.img;
	return x;
}

complex complex::operator*(complex x) {
	x.rel = rel*x.rel;
	x.img = img*x.img;
	return x;
}

ostream & operator << (ostream & out, complex & x) {//����<<������������ڸ�����
	if(x.img>=0)//�ж��鲿������ʵ�������ʽΪ��a+bi��a-bi
		out << x.rel << "+" << x.img << "i";
	else
		out << x.rel << x.img << "i";
	return out;
}

istream & operator >> (istream & in, complex & x) {//����>>������������ڸ�����
	char a[20];
	in >> a;//���븴������ʽΪa+bi��a-bi���ȱ���Ϊ�ַ�����
	int i = 0;
	while (a[i]!='i') {//��+�ţ���-�ţ�ǰ���ַ�תΪʵ����ֵ���Ѻ�����ַ�תΪ�鲿��ֵ
		if (a[i] == '+') {
			i++;
			x.img = x.img*10*i+a[i] - 48;
		}
		else if (a[i] == '-') {
			i++;
			x.img = x.img * 10 * i + a[i] - 48;
			x.img = -x.img;
		}
		else
		{
			x.rel =x.rel*10*i+a[i] - 48;
		}
		i++;
	}
	return in;
}

int main() {
	complex a(2, -4), b(0, 3),c,d,e;
	c = a + b;
	d = c*a;
	cout << c << endl;
	cout << d << endl;
	cin >> e;
	cout << e << endl;
}
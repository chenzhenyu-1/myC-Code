#include <iostream>
using namespace std;

template<typename T> T mymax(T a, T b) {    //����ģ�嶨�壨����������
	return a>b ? a : b;
}

template<class T> T mymax(T a, T b, T c) {   //���غ���ģ�壨����������
	if (a>b) return mymax(a, c);
	else return mymax(b, c);
}

class complex {      //�Զ��帴����
	float r, i;     //ʵ�����鲿���ݳ�Ա
public:
	complex(float rr = 0, float ii = 0) { r = rr; i = ii; }    //���캯��
	bool operator >(complex &c) {          //�Զ��帴�����͵ġ�>�����������
		if (r*r + i*i>c.r*c.r + c.i*c.i) return true; else return false;
	}
	float getr() { return r; }    //���ظ�����ʵ��
	float geti() { return i; }    //���ظ������鲿
};

void main()
{
	complex c1(2, 4), c2(1, 3), c3(2, 5), c;
	cout << mymax<int>(10, 20.5) << endl;   //ǿ��ʵ�������ɽ��������ƥ������⡣ȥ��<int>������ʲô�����
	cout << mymax(50.5, 28.5) << endl;      //ͨ��ʵ��,ϵͳ��ȷ��TΪdouble��
	cout << mymax('d', 't') << endl;        //ͨ��ʵ��,ϵͳ��ȷ��TΪchar��
	cout << mymax(30, 40, 50) << endl;
	cout << mymax(101.3, 200.4, 156.9) << endl;
	c = mymax(c1, c2, c3);                 //ͨ��ʵ��,ϵͳ��ȷ��TΪcomplex��
	cout << "(" << c.getr() << "," << c.geti() << ")" << endl;
}

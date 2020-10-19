// program8_4.cpp
# include<iostream>
using namespace std;
class CB {
public:
	int a;
	CB(int x) { a = x; }
	void showa() { cout << "Class CB -- a=" << a << endl; }
};
class CD :public CB {
public:
	int a; //������Աaͬ��
	CD(int x, int y) :CB(x) { a = y; }
	void showa() { cout << "Class CD -- a=" << a << endl; } //������Աshowa ͬ��
	void print2a() {
		cout << "a=" << a << endl; //���������ݳ�Աa
		cout << "CB::a=" << CB::a << endl; //���ʻ���ͬ����Աa
	}
};
void main() {
	CB CBobj(12);
	CBobj.showa(); //���û����showa()
	CD CDobj(48, 999);
	CDobj.showa(); //������CD ��showa
	CDobj.CB::showa(); //���ʻ���showa
	cout << "CDobj.a=" << CDobj.a << endl; //������CD ��a
	cout << "CDobj.CB::a=" << CDobj.CB::a << endl; //���ʻ���a
	CDobj.print2a();
}

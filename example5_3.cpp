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
	int a; //与基类成员a同名
	CD(int x, int y) :CB(x) { a = y; }
	void showa() { cout << "Class CD -- a=" << a << endl; } //与基类成员showa 同名
	void print2a() {
		cout << "a=" << a << endl; //派生类数据成员a
		cout << "CB::a=" << CB::a << endl; //访问基类同名成员a
	}
};
void main() {
	CB CBobj(12);
	CBobj.showa(); //调用基类的showa()
	CD CDobj(48, 999);
	CDobj.showa(); //派生类CD 的showa
	CDobj.CB::showa(); //访问基类showa
	cout << "CDobj.a=" << CDobj.a << endl; //派生类CD 的a
	cout << "CDobj.CB::a=" << CDobj.CB::a << endl; //访问基类a
	CDobj.print2a();
}

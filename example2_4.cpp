#include <iostream>
using namespace std;
int g = 100;//全局变量
void f(int g, int x) {
	static int y = 150;//静态局部变量，特点：不释放，只初始化一次，前次的值影响后面的运算
	::g += 10;//访问与局部变量同名的全局变量g
	y += 10;
	cout << "g=" << g << ",x=" << x << ",y=" << y << ",::g=" << ::g << endl;
}
void main() {
	int a = 200;
	cout << "First:"; f(g, a);
	a += 10; g += 10;
	cout << "Second:"; f(g, a);
}

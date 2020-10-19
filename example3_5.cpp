#include<iostream>
/*
编写一个函数实现利用矩形公式计算任一个一元函数在闭区间[a,b]上的定积分，
并编写主函数进行调用验证。
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
	cout << "f(x)=3*x^2+1的定积分（积分上下限" << b << "、" << a << "）：" << endl;
	cout << "精确值：" <<b*b*b+b-a*a*a-a<< endl;
	cout << "计算值:" << definite_integral(&f, a, b) << endl;
}
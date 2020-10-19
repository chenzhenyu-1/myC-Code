#include <iostream>
#include <math.h>
using namespace std;
unsigned long num, res,front,after;
int k;
void main() {
	cout << "请输入一个无符号整数：";cin >> num;
	cout << "请输入K值："; cin >> k;
	front = pow(10, k - 1);
	after = pow(10, k);
	res = num % front + (num / after) * front;
	cout <<"清除第"<<k<<"位后结果为："<< res << endl;
}
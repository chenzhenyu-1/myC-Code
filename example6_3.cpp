#include <iostream>
#include "string.h"
using namespace std;
template <typename T, int i> class TestClass {
public:
	T buffer[i];
	//T类型的buffer，其大小随普通形参i的值变化(灵活性大!)
	T getData(int j);
};

template <class T, int i>
T TestClass<T, i>::getData(int j) {
	return *(buffer + j);
};
void main() {
	TestClass<char, 6> ClassInstA;
	char cArr[6] = "abcde";
	strcpy_s(ClassInstA.buffer, 6, cArr);
	for (int i = 0; i<5; i++) {
		char res = ClassInstA.getData(i);
		cout << res << "  ";
	}
	cout << endl;
	TestClass<double, 6> ClassInstF;
	double fArr[6] = { 12.1, 23.2, 34.3, 45.4, 56.5, 67.6 };
	for (int i = 0; i<6; i++)
		ClassInstF.buffer[i] = fArr[i] - 10;
	for (int i = 0; i<6; i++) {
		double res = ClassInstF.getData(i);
		cout << res << "  ";
	}
	cout << endl;
}

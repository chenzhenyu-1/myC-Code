#include<iostream>
/*
编写一个对具有n个元素的一维数组进行由大到小排序的函数模板，编制主函数，
通过使用不同类型的实参数组对它进行调用以验证其正确性。
函数模板的原型为：template <class Type> void sort(Type *A,int n)
*/
using namespace std;

template<class Type>void sort(Type *A, int n) {
	for (int j = n; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			Type temp;
			if (*(A + i) < *(A + i + 1)) {
				temp = *(A + i + 1);
				*(A + i + 1) = *(A + i);
				*(A + i) = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << A[i] << ",";
	}
	cout << endl;
}

int main() {
	int a[5] = { 0,3,1,2,6 };
	sort(a, 5);
	float b[7] = { 1.2,5.3,2.0,1.1,9.2,10.0,7.2 };
	sort(b, 7);
	char c[10] = "sVfhFwTum";
	sort(c, 10);
}
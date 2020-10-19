#include<iostream>
#include<fstream>
/*
编程实现将一个文本文件的每一行添加行号后写入另一个文本文件
*/
using namespace std;

void main() {
	ifstream If("file1.txt");
	ofstream Of("file2.txt");
	int i = 1;
	char c;
	cout << "file1.txt---(添加行号)--->file2.txt" << endl;
	Of << i << "  ";
	i++; If.get(c);
	while (1){
		If.get(c);
		if (If.eof())
			break;
		if (c == '\n') {
			Of << c << i << "  ";
			i++;
		}
		else
			Of << c;
	} 
	If.close(); Of.close();
	cout << "done" << endl;
}
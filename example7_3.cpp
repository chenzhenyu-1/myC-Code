#include<iostream>
#include<fstream>
/*
���ʵ�ֽ�һ���ı��ļ���ÿһ������кź�д����һ���ı��ļ�
*/
using namespace std;

void main() {
	ifstream If("file1.txt");
	ofstream Of("file2.txt");
	int i = 1;
	char c;
	cout << "file1.txt---(����к�)--->file2.txt" << endl;
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
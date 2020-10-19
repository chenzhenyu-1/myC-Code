#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void main() {
	ofstream fout("f.txt");
	int i = 77; double d = 8765.56789;
	fout << i << "(10)=";
	fout << showbase << oct << i << "(8)=";
	fout << hex << i << "(16)" << endl;
	fout << setw(10) << fixed << setprecision(1) << right << setfill('#') << d << endl;
	fout << setw(10) << left << setfill('#') << d << endl;
	fout << setw(10) << setprecision(5) << d << endl;
	fout << scientific << setprecision(9) << uppercase << d << endl;
	cout << "\"f.txt\"------------done." << endl;
}
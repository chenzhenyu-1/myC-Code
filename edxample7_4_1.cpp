#include<iostream>
#include<fstream>
using namespace std;
void main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "����Ĳ�������" << endl;
		exit(1);
	}
	ifstream fi;
	fi.open(argv[1]);
	char c;
	fi.get(c);
	while (!fi.eof()) {
		cout << c;
		fi.get(c);
	}
	fi.close();
}
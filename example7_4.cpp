#include<iostream>
#include<fstream>
/*
编写一个程序实现类似DOS命令copy的文件拷贝功能。
要求用两种方法实现：
（1）拷贝的源文件和目标文件由命令行输入；
（2）拷贝的源文件和目标文件按对话方式输入
*/
using namespace std;

void main(int argc, char* argv[]) {
	if (argc != 1 && argc != 3) {	//判断输入参数是否正确
		cout << "输入的参数错误！" << endl;
		exit(1);
	}
	if (argc == 3) {	//参数个数为3时，以命令行方式输入
		cout << argv[1] << "------(复制到)------>" << argv[2] << endl;
		ifstream fi; ofstream fo;
		fi.open(argv[1], ios::binary, ios::_Nocreate);
		if (fi.fail()) {	//判断要复制的源文件是否存在
			cout << "读取文件出错！" << endl;
			fi.close();
			exit(1);
		}
		fo.open(argv[2], ios::binary);
		char c;
		fi.get(c);
		while (!fi.eof()) {
			fo.put(c);
			fi.get(c);
		}
		fo.close(); fi.close();
		cout << "done" << endl;
	}
	else if (argc == 1) {	//默认按对话方式输入；
		ifstream fi; ofstream fo;
		cout << "请输入要复制的源文件名：";
		char source[20], target[20];
		cin >> source;
		fi.open(source, ios::binary, ios::_Nocreate);
		if (fi.fail()) {	//判断要复制的源文件是否存在
			cout << "读取文件出错！" << endl;
			fi.close();
			exit(1);
		}
		cout << "请输入要复制的目标文件名：";
		cin >> target;
		fo.open(target, ios::binary);
		char c;
		fi.get(c);
		while (!fi.eof()) {
			fo.put(c);
			fi.get(c);
		}
		fo.close(); fi.close();
		cout << "done" << endl;
	}
	else
		cout << "输入的参数错误！" << endl;
}

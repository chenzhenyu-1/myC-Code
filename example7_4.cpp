#include<iostream>
#include<fstream>
/*
��дһ������ʵ������DOS����copy���ļ��������ܡ�
Ҫ�������ַ���ʵ�֣�
��1��������Դ�ļ���Ŀ���ļ������������룻
��2��������Դ�ļ���Ŀ���ļ����Ի���ʽ����
*/
using namespace std;

void main(int argc, char* argv[]) {
	if (argc != 1 && argc != 3) {	//�ж���������Ƿ���ȷ
		cout << "����Ĳ�������" << endl;
		exit(1);
	}
	if (argc == 3) {	//��������Ϊ3ʱ���������з�ʽ����
		cout << argv[1] << "------(���Ƶ�)------>" << argv[2] << endl;
		ifstream fi; ofstream fo;
		fi.open(argv[1], ios::binary, ios::_Nocreate);
		if (fi.fail()) {	//�ж�Ҫ���Ƶ�Դ�ļ��Ƿ����
			cout << "��ȡ�ļ�����" << endl;
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
	else if (argc == 1) {	//Ĭ�ϰ��Ի���ʽ���룻
		ifstream fi; ofstream fo;
		cout << "������Ҫ���Ƶ�Դ�ļ�����";
		char source[20], target[20];
		cin >> source;
		fi.open(source, ios::binary, ios::_Nocreate);
		if (fi.fail()) {	//�ж�Ҫ���Ƶ�Դ�ļ��Ƿ����
			cout << "��ȡ�ļ�����" << endl;
			fi.close();
			exit(1);
		}
		cout << "������Ҫ���Ƶ�Ŀ���ļ�����";
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
		cout << "����Ĳ�������" << endl;
}

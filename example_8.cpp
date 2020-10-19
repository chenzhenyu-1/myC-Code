#include<iostream>
#include<string>
#include<fstream>
#include"Person.h"
#include<math.h>
/*
�����¸�������ܽ��з�������ƣ���д�������е���ȷ��C++���Գ��򣬻���ʵ��ϵͳ�ĸ�������ܡ�
Ա��������Ϣ�����ܣ�
Ա��������Ϣ��¼�룬����Ա����š��������Ա𡢳������ڡ�ְ�����ڲ��ŵ���Ϣ��
Ա��������Ϣ���޸ģ�
Ա��������Ϣ��ɾ����
Ա��������Ϣ�Ĳ�ѯ��
Ա��������Ϣ�Ĵ��̣�
Ա��������Ϣ�Ķ��̣�
*/

using namespace std;

void List::add() {
	node *temp;
	temp = new node;
	long long num;
	string name, sex, post, department, birth;
	cout << "����Ա����ţ�";
	cin >> num;
	if (cin.fail()) {
		cout << "�������" << endl;
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		return;
	}
	temp->data.setNum(num);
	cout << "����������";
	cin >> name;
	temp->data.setName(name);
	cout << "�����Ա�";
	cin >> sex;
	temp->data.setSex(sex);
	cout << "����������ڣ�";
	cin >> birth;
	temp->data.setBirth(birth);
	cout << "����ְ��";
	cin >> post;
	temp->data.setPost(post);
	cout << "�������ڲ��ţ�";
	cin >> department;
	temp->data.setDepartment(department);
	temp->next = NULL;
	if (tail != NULL) {
		temp->previous = tail;
		tail->next = temp;
	}
	else
		temp->previous = NULL;
	tail = temp;
	if (head == NULL)
		head = tail;
}

void List::add(long long num, string name, string sex, string birth, string post, string department)
{
	node *temp;
	temp = new node;
	temp->data.setNum(num);
	temp->data.setName(name);
	temp->data.setSex(sex);
	temp->data.setBirth(birth);
	temp->data.setPost(post);
	temp->data.setDepartment(department);
	temp->next = NULL;
	if (tail != NULL) {
		temp->previous = tail;
		tail->next = temp;
	}
	else
		temp->previous = NULL;
	tail = temp;
	if (head == NULL)
		head = tail;
}

void List::revise() {
	cout << "������Ҫ�޸ĵ�Ա����ţ�";
	long long num;
	node *p;
	cin >> num;
	if (cin.fail()) {
		cout << "�������" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		return;
	}
	p = check(num);
	if (p == NULL)
		return;
	else {
		bool flag = true;
		output(p);
		while (flag) {
			cout << "������Ҫ�޸ĵ����ݣ�" << endl;
			cout << "[1] ����\t[2] �Ա�\t[3] ��������" << endl;
			cout << "[4] ְ��\t[5] ���ڲ���\t[6] �˳�" << endl;
			int i;
			cin >> i;
			if (cin.fail()) {
				cout << "�������" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				return;
			}
			if (i < 1 || i>6) {
				cout << "�������������1-6��Χ�����֡�" << endl;
				system("pause");
				system("cls");
			}
			else {
				switch (i)
				{
				case 1: {
					cout << "�����޸ĺ��������";
					string name;
					cin >> name;
					p->data.setName(name);
					break;
				}
				case 2: {
					cout << "�����޸ĺ���Ա�";
					string sex;
					cin >> sex;
					p->data.setSex(sex);
					break;
				}
				case 3: {
					cout << "�����޸ĺ�ĳ������ڣ�";
					string birth;
					cin >> birth;
					p->data.setBirth(birth);
					break;
				}
				case 4: {
					cout << "�����޸ĺ��ְ��";
					string post;
					cin >> post;
					p->data.setPost(post);
					break;
				}
				case 5: {
					cout << "�����޸ĺ�Ĳ��ţ�";
					string department;
					cin >> department;
					p->data.setDepartment(department);
					break;
				}
				default:
					return;
				}
				system("cls");
			}
			output(p); isExit(flag);
		}
	}
}

void List::remove() {
	cout << "������Ҫɾ����Ա����ţ�";
	long long num;
	cin >> num;
	if (cin.fail()) {
		cout << "�������" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		return;
	}
	node *p = check(num);
	if (p == NULL)  return;
	output(p);
	cout << "�Ƿ�ȷ��Ҫɾ����Ա����Ϣ��" << endl;
	cout << "[0] ��\t[����]��" << endl;
	int n;
	cin >> n;
	if (n == 0) {
		if (p->previous != NULL)
			p->previous->next = p->next;
		if (p == tail)
			tail = p->previous;
		if (p == head)
			head = p->next;
		cout << "ɾ���ɹ���" << endl;
		delete p;
	}
	return;
}

void List::check(){
	cout << "[1] ��ѯȫ��\t[2] ����Ų�ѯ" << endl;
	int n; cin >> n;
	if (cin.fail()) {
		cout << "�������" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		return;
	}
	node *p = head;
	if (n == 1) {
		if (p == NULL) { cout << "�б�Ϊ�գ�" << endl; return; }
		while (p != NULL) {
			output(p);
			cout << "------------------------------" << endl;
			p = p->next;
		}
	}
	if(n == 2) {
		cout << "������Ҫ��ѯ��Ա����ţ�";
		long long num;
		cin >> num;
		if (cin.fail()) {
			cout << "�������" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			return;
		}
		while (p != NULL) {
			if (p->data.getNum() == num) {
				output(p);
				return;
			}
			else
				p = p->next;
		}
		cout << "��ѯʧ�ܣ���Ա����ſ��ܲ����ڡ�" << endl;
	}
}

List::node* List::check(long long num) {
	node *p = head;
	while (p != NULL) {
		if (p->data.getNum() == num) {
			return p;
		}
		else
			p = p->next;
	}
	cout << "��ѯʧ�ܣ���Ա����ſ��ܲ����ڡ�" << endl;
	return p;
}

void List::output(node *p) {
	cout << "Ա����ţ�" << p->data.getNum() << endl;
	cout << "������" << p->data.getName() << endl;
	cout << "�Ա�" << p->data.getSex() << endl;
	cout << "�������ڣ�" << p->data.getBirth() << endl;
	cout << "ְ��" << p->data.getPost() << endl;
	cout << "���ڲ��ţ�" << p->data.getDepartment() << endl;
}

void List::isExit(bool &flag) {
	cout << "[1] ����\t[����] ����" << endl;
	int f;
	cin >> f;
	switch (f) {
	case 1:
		return;
	default:
		flag = false;
	}
}

ostream & operator <<(ostream &out,List &data){
	List::node *p = data.head;
	while (p != NULL) {
		out << "Ա����ţ�" << p->data.getNum() << endl;
		out << "������" << p->data.getName() << endl;
		out << "�Ա�" << p->data.getSex() << endl;
		out << "�������ڣ�" << p->data.getBirth() << endl;
		out << "ְ��" << p->data.getPost() << endl;
		out << "���ڲ��ţ�" << p->data.getDepartment() << endl;
		out << "------------------------------------------------" << endl;
		p = p->next;
	}
	return out;
}

istream & operator >> (istream &in, List &data) {
	string name, sex, birth, post, department;
	string line, str; int begin;
	while (!in.eof()) {
		getline(in, line);
		while (line.find('��') != string::npos) {
			begin = line.find('��'); begin += 4;
			str = line.substr(begin, line.size() - begin);
			long long num = 0;
			for (int i = 0; i < str.size(); i++) {
				num = num + (str[i] - '0')*pow(10, str.size() - 1 - i);
			}getline(in, line);
			begin = line.find('��'); begin += 1;
			str = line.substr(begin, line.size() - begin);
			name = str; getline(in, line);
			begin = line.find('��'); begin += 1;
			str = line.substr(begin, line.size() - begin);
			sex = str; getline(in, line);
			begin = line.find('��'); begin += 1;
			str = line.substr(begin, line.size() - begin);
			birth = str; getline(in, line);
			begin = line.find('��'); begin += 1;
			str = line.substr(begin, line.size() - begin);
			post = str; getline(in, line);
			begin = line.find('��'); begin += 1;
			str = line.substr(begin, line.size() - begin);
			department = str; getline(in, line);
			data.add(num, name, sex, birth, post, department);
		}
	}
	return in;
}

void mainSys::save() {
	ofstream fo; string adr;
	cout << "�����뱣��·�����ļ�����";
	cin >> adr; fo.open(adr, ios::_Noreplace);
	if (fo.fail()) {
		cout << "�ļ��Ѵ��ڣ��Ƿ�Ҫ�����ļ���" << endl;
		cout << "[1] ��\t[2] ��" << endl;
		int i; cin >> i;
		if (i == 1) {
			fo.close();
			fo.open(adr, ios::trunc);
			fo << *this;
			cout << "����ɹ���" << endl;
			return;
		}
		if (i == 2)
			return;
	}
	else
		fo << *this; fo.close();
	cout << "����ɹ���" << endl;
}

void List::clear() {
	node *temp;
	while (head != NULL) {
		temp = head->next;
		delete head;
		head = temp;
		if (head == NULL)
			tail = head;
	}
}

void mainSys::read() {
	ifstream fi; string adr;
	cout << "������Ҫ��ȡ��·�����ļ���:";
	cin >> adr;
	fi.open(adr, ios::_Nocreate);
	if (fi.fail()) {
		cout << "��ȡ�ļ�ʧ�ܣ�" << endl;
		return;
	}
	else {
		if (this->getHead() != NULL)
			this->clear();
		fi >> *this;
		cout << "��ȡ�ɹ���" << endl;
	}
}

void mainSys::launch() {
	bool run = true;
	while (run) {
		cout << "                 **********************************" << endl;
		cout << "                 *    ��ӭʹ��Ա����Ϣ����ϵͳ��  *" << endl;
		cout << "******************************************************************" << endl;
		cout << "* [1] ���Ա����Ϣ\t[2] �޸�Ա����Ϣ\t[3] ɾ��Ա����Ϣ *" << endl;
		cout << "* [4] ��ѯԱ����Ϣ\t[5] ��/����\t\t[6] �˳�         *" << endl;
		cout << "******************************************************************" << endl;
		int function;
		cin >> function;
		switch (function)
		{
		case 1: {
			bool flag = true;
			while (flag) { system("cls"); this->add(); this->isExit(flag); system("cls"); }break;
		}
		case 2:
			system("cls"); this->revise(); system("pause"); system("cls"); break;
		case 3: {
			bool flag = true;
			while (flag) { system("cls"); this->remove(); this->isExit(flag); system("cls"); } break;
		}
		case 4:
			system("cls"); this->check(); system("pause"); system("cls"); break;
		case 5: {
			system("cls"); cout << "[1] ����\t[2] ����" << endl;
			int n; cin >> n;
			if (n < 1 || n > 2||cin.fail()) { 
				cin.clear(); cin.ignore(INT_MAX, '\n'); 
				cout << "�������" << endl; 
				system("pause"); system("cls"); break;
			}
			switch (n)
			{
			case 1:
				this->save(); break;
			case 2:
				this->read(); break;
			}
			system("pause"); system("cls"); break;
		}
		default:
			run = false;
			break;
		}
	}
}

void main() {
	mainSys table;
	table.launch();
}
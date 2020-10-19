#include<iostream>
#include<string>
#include<fstream>
#include"Person.h"
#include<math.h>
/*
对以下各项管理功能进行分析和设计，编写出可运行的正确的C++语言程序，基本实现系统的各项管理功能。
员工基本信息管理功能：
员工基本信息的录入，包括员工编号、姓名、性别、出生日期、职务、所在部门等信息；
员工基本信息的修改；
员工基本信息的删除；
员工基本信息的查询；
员工基本信息的存盘；
员工基本信息的读盘；
*/

using namespace std;

void List::add() {
	node *temp;
	temp = new node;
	long long num;
	string name, sex, post, department, birth;
	cout << "输入员工编号：";
	cin >> num;
	if (cin.fail()) {
		cout << "输入错误！" << endl;
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		return;
	}
	temp->data.setNum(num);
	cout << "输入姓名：";
	cin >> name;
	temp->data.setName(name);
	cout << "输入性别：";
	cin >> sex;
	temp->data.setSex(sex);
	cout << "输入出生日期：";
	cin >> birth;
	temp->data.setBirth(birth);
	cout << "输入职务：";
	cin >> post;
	temp->data.setPost(post);
	cout << "输入所在部门：";
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
	cout << "请输入要修改的员工编号：";
	long long num;
	node *p;
	cin >> num;
	if (cin.fail()) {
		cout << "输入错误！" << endl;
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
			cout << "请输入要修改的内容：" << endl;
			cout << "[1] 姓名\t[2] 性别\t[3] 出生日期" << endl;
			cout << "[4] 职务\t[5] 所在部门\t[6] 退出" << endl;
			int i;
			cin >> i;
			if (cin.fail()) {
				cout << "输入错误！" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				return;
			}
			if (i < 1 || i>6) {
				cout << "输入错误！请输入1-6范围的数字。" << endl;
				system("pause");
				system("cls");
			}
			else {
				switch (i)
				{
				case 1: {
					cout << "输入修改后的姓名：";
					string name;
					cin >> name;
					p->data.setName(name);
					break;
				}
				case 2: {
					cout << "输入修改后的性别：";
					string sex;
					cin >> sex;
					p->data.setSex(sex);
					break;
				}
				case 3: {
					cout << "输入修改后的出生日期：";
					string birth;
					cin >> birth;
					p->data.setBirth(birth);
					break;
				}
				case 4: {
					cout << "输入修改后的职务：";
					string post;
					cin >> post;
					p->data.setPost(post);
					break;
				}
				case 5: {
					cout << "输入修改后的部门：";
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
	cout << "请输入要删除的员工编号：";
	long long num;
	cin >> num;
	if (cin.fail()) {
		cout << "输入错误！" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		return;
	}
	node *p = check(num);
	if (p == NULL)  return;
	output(p);
	cout << "是否确认要删除该员工信息？" << endl;
	cout << "[0] 是\t[其他]否" << endl;
	int n;
	cin >> n;
	if (n == 0) {
		if (p->previous != NULL)
			p->previous->next = p->next;
		if (p == tail)
			tail = p->previous;
		if (p == head)
			head = p->next;
		cout << "删除成功！" << endl;
		delete p;
	}
	return;
}

void List::check(){
	cout << "[1] 查询全部\t[2] 按编号查询" << endl;
	int n; cin >> n;
	if (cin.fail()) {
		cout << "输入错误！" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		return;
	}
	node *p = head;
	if (n == 1) {
		if (p == NULL) { cout << "列表为空！" << endl; return; }
		while (p != NULL) {
			output(p);
			cout << "------------------------------" << endl;
			p = p->next;
		}
	}
	if(n == 2) {
		cout << "请输入要查询的员工编号：";
		long long num;
		cin >> num;
		if (cin.fail()) {
			cout << "输入错误！" << endl;
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
		cout << "查询失败，该员工编号可能不存在。" << endl;
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
	cout << "查询失败，该员工编号可能不存在。" << endl;
	return p;
}

void List::output(node *p) {
	cout << "员工编号：" << p->data.getNum() << endl;
	cout << "姓名：" << p->data.getName() << endl;
	cout << "性别：" << p->data.getSex() << endl;
	cout << "出生日期：" << p->data.getBirth() << endl;
	cout << "职务：" << p->data.getPost() << endl;
	cout << "所在部门：" << p->data.getDepartment() << endl;
}

void List::isExit(bool &flag) {
	cout << "[1] 继续\t[其他] 返回" << endl;
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
		out << "员工编号：" << p->data.getNum() << endl;
		out << "姓名：" << p->data.getName() << endl;
		out << "性别：" << p->data.getSex() << endl;
		out << "出生日期：" << p->data.getBirth() << endl;
		out << "职务：" << p->data.getPost() << endl;
		out << "所在部门：" << p->data.getDepartment() << endl;
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
		while (line.find('：') != string::npos) {
			begin = line.find('：'); begin += 4;
			str = line.substr(begin, line.size() - begin);
			long long num = 0;
			for (int i = 0; i < str.size(); i++) {
				num = num + (str[i] - '0')*pow(10, str.size() - 1 - i);
			}getline(in, line);
			begin = line.find('：'); begin += 1;
			str = line.substr(begin, line.size() - begin);
			name = str; getline(in, line);
			begin = line.find('：'); begin += 1;
			str = line.substr(begin, line.size() - begin);
			sex = str; getline(in, line);
			begin = line.find('：'); begin += 1;
			str = line.substr(begin, line.size() - begin);
			birth = str; getline(in, line);
			begin = line.find('：'); begin += 1;
			str = line.substr(begin, line.size() - begin);
			post = str; getline(in, line);
			begin = line.find('：'); begin += 1;
			str = line.substr(begin, line.size() - begin);
			department = str; getline(in, line);
			data.add(num, name, sex, birth, post, department);
		}
	}
	return in;
}

void mainSys::save() {
	ofstream fo; string adr;
	cout << "请输入保存路径与文件名：";
	cin >> adr; fo.open(adr, ios::_Noreplace);
	if (fo.fail()) {
		cout << "文件已存在，是否要覆盖文件？" << endl;
		cout << "[1] 是\t[2] 否" << endl;
		int i; cin >> i;
		if (i == 1) {
			fo.close();
			fo.open(adr, ios::trunc);
			fo << *this;
			cout << "保存成功！" << endl;
			return;
		}
		if (i == 2)
			return;
	}
	else
		fo << *this; fo.close();
	cout << "保存成功！" << endl;
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
	cout << "请输入要读取的路径与文件名:";
	cin >> adr;
	fi.open(adr, ios::_Nocreate);
	if (fi.fail()) {
		cout << "读取文件失败！" << endl;
		return;
	}
	else {
		if (this->getHead() != NULL)
			this->clear();
		fi >> *this;
		cout << "读取成功！" << endl;
	}
}

void mainSys::launch() {
	bool run = true;
	while (run) {
		cout << "                 **********************************" << endl;
		cout << "                 *    欢迎使用员工信息管理系统！  *" << endl;
		cout << "******************************************************************" << endl;
		cout << "* [1] 添加员工信息\t[2] 修改员工信息\t[3] 删除员工信息 *" << endl;
		cout << "* [4] 查询员工信息\t[5] 存/读盘\t\t[6] 退出         *" << endl;
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
			system("cls"); cout << "[1] 存盘\t[2] 读盘" << endl;
			int n; cin >> n;
			if (n < 1 || n > 2||cin.fail()) { 
				cin.clear(); cin.ignore(INT_MAX, '\n'); 
				cout << "输入错误！" << endl; 
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
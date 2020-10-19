#pragma once
#include<iostream>
#include<string>
using namespace std;
class ID {
public:
	long long num;
	virtual void setNum(long long) = 0;
};

class Person:public ID {
public:
	void setNum(long long _num) { num = _num; }
	void setName(string _name) { name = _name; }
	void setSex(string _sex) { sex = _sex; }
	void setBirth(string _birth) { birth=_birth; }
	void setPost(string _post) { post = _post; }
	void setDepartment(string _department) { department = _department; }
	long long getNum() { return num; }
	string getName() { return name; }
	string getSex() { return sex; }
	string getBirth() { return birth; }
	string getPost() { return post; }
	string getDepartment() { return department; }
private:
	string name, sex, post, department,birth;
};

class List{
	struct node
	{
		Person data;
		node *next, *previous;
	} *head, *tail;
public:
	List() { head = NULL; tail = NULL; }
	void add();
	void add(long long num, string name, string sex, string birth, string post, string department);
	void revise();
	void remove();
	void check();
	node* check(long long);
	void output(node*);
	void isExit(bool &flag);
	friend ostream & operator << (ostream &, List &);
	friend istream & operator >> (istream &, List &);
	node* getHead() { return head; }
	node* getTail() { return tail; }
	void clear();
};

class Wages :public ID {
private:
	int a, b, c, d;
};

class mainSys :public List {
public:
	void save();
	void read();
	void launch();
};
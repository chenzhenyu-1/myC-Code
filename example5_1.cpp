#include<iostream>

using namespace std;

class Person
{
public:
	Person(){}
	Person(char *str, int a, int s) { strcpy_s(name, str); age = a; sex = s; }
	void print();
	void input();

private:
	char name[10];
	int age, sex;
};

void Person::input()
{
	cout << "����������" << endl;
	cin >> name;
	cout << "�����Ա�(1�������ԣ�0����Ů��)��" << endl;
	cin >> sex;
	cout << "�������䣺" << endl;
	cin >> age;
};

void Person::print()
{
	cout << "������" << name << endl;
	cout << "�Ա�" << sex << endl;
	cout << "���䣺" << age << endl;
};

class Student :public Person
{
public:
	Student() {}
	Student(char *str, int a, int s,int n,char *d);
	void print();
	void input();

private:
	int num;
	char depart[10];
};

Student::Student(char *str, int a, int s, int n, char *d):Person(str, a, s)
{
	num = n;
	strcpy_s(depart, d);
}

void Student::input()
{
	Person::input();
	cout << "����ѧ�ţ�" << endl;
	cin >> num;
	cout << "����ϵ��" << endl;
	cin >> depart;
}

void Student::print()
{
	Person::print();
	cout << "ѧ�ţ�" << num << endl;;
	cout << "ϵ��" << depart << endl;
}

class Teacher :public Person
{
public:
	Teacher(){}
	Teacher(char *str, int a, int s, char *t, char *c);
	void print();
	void input();

private:
	char title[10], course[10];
};

Teacher::Teacher(char *str, int a, int s, char *t, char *c):Person(str,a,s)
{
	strcpy_s(title, t);
	strcpy_s(course, c);
}

void Teacher::input() 
{
	Person::input();
	cout << "����ְ�ƣ�" << endl;
	cin >> title;
	cout << "���뵣�ογ̣�" << endl;
	cin >> course;
}

void Teacher::print()
{
	Person::print();
	cout << "ְ�ƣ�" << title << endl;
	cout << "���ογ̣�" << course << endl;
}

class GraduateStudent:public Student
{
public:
	GraduateStudent(){}
	GraduateStudent(char *str, int a, int s, int n, char *d, char *t);
	void print();
	void input();

private:
	char teach[10];
};

GraduateStudent::GraduateStudent(char *str, int a, int s, int n, char *d, char *t) :Student(str, a, s, n, d)
{
	strcpy_s(teach, t);
}

void GraduateStudent::print()
{
	Student::print();
	cout << "��ʦ:" << endl;
}

void GraduateStudent::input()
{
	Student::input();
	cout << "�����뵼ʦ���֣�" << endl;
	cin >> teach;
}

int main() {
	Teacher t1;
	t1.input();
	cout << "--------------���---------------" << endl;
	t1.print();
	cout << "---------------------------------" << endl;
	Person p1("����",16,1);
	cout << "--------------���-------------- - " << endl;
	p1.print();
	cout << "---------------------------------" << endl;
	Student s1;
	s1.input();
	cout << "--------------���---------------" << endl;
	s1.print();
	cout << "---------------------------------" << endl;
	GraduateStudent g1("����", 22, 0, 19164512, "��ѧϵ", "����");
	cout << "--------------���---------------" << endl;
	g1.print();
	cout << "---------------------------------" << endl;
}
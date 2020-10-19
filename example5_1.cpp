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
	cout << "输入姓名：" << endl;
	cin >> name;
	cout << "输入性别(1代表男性，0代表女性)：" << endl;
	cin >> sex;
	cout << "输入年龄：" << endl;
	cin >> age;
};

void Person::print()
{
	cout << "姓名：" << name << endl;
	cout << "性别：" << sex << endl;
	cout << "年龄：" << age << endl;
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
	cout << "输入学号：" << endl;
	cin >> num;
	cout << "输入系别：" << endl;
	cin >> depart;
}

void Student::print()
{
	Person::print();
	cout << "学号：" << num << endl;;
	cout << "系别：" << depart << endl;
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
	cout << "输入职称：" << endl;
	cin >> title;
	cout << "输入担任课程：" << endl;
	cin >> course;
}

void Teacher::print()
{
	Person::print();
	cout << "职称：" << title << endl;
	cout << "担任课程：" << course << endl;
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
	cout << "导师:" << endl;
}

void GraduateStudent::input()
{
	Student::input();
	cout << "请输入导师名字：" << endl;
	cin >> teach;
}

int main() {
	Teacher t1;
	t1.input();
	cout << "--------------输出---------------" << endl;
	t1.print();
	cout << "---------------------------------" << endl;
	Person p1("张三",16,1);
	cout << "--------------输出-------------- - " << endl;
	p1.print();
	cout << "---------------------------------" << endl;
	Student s1;
	s1.input();
	cout << "--------------输出---------------" << endl;
	s1.print();
	cout << "---------------------------------" << endl;
	GraduateStudent g1("李四", 22, 0, 19164512, "数学系", "王明");
	cout << "--------------输出---------------" << endl;
	g1.print();
	cout << "---------------------------------" << endl;
}
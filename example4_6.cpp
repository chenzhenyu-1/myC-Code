#include<iostream>
/*
设计一个学生类Student，具有私有数据成员：学号、姓名、数学成绩、英语成绩、计算机成绩、总成绩、平均成绩。
具有公有函数成员：求三门课总成绩sum（）、平均成绩average（），显示学生数据信息display（），设置学生数据信息setData（）。
编写主函数，实现一个班学生数据的输入和计算每个学生的总成绩、平均成绩，按总成绩排序输出学生信息
*/
using namespace std;

class Student;
class Class
{
public:
	Class();
	void display();
	void sort();
	~Class() { delete[] start; }

private:
	int n;
	Student *cla, *start;
};

class Student
{
public:
	float sum() { return math + english + computor; }
	float average() { return totle / 3; }
	void display();
	void setData();
	//float getTotle() { return totle; }
	friend void Class::sort();

private:
	char num[11], name[11];
	float math, english, computor, totle, aver;

};


void Student::display()
{
	cout << "学号：" << num << endl;
	cout << "姓名：" << name << endl;
	cout << "数学成绩：" << math << " 英语成绩：" << english << " 计算机成绩：" << computor << endl;
	cout << "总成绩：" << totle << " 平均成绩：" << aver << endl;
}

void Student::setData()
{
	cout << "请输入学号：";
	cin >> num;
	cout << "姓名：";
	cin >> name;
	cout << "数学、英语、计算机成绩：";
	cin >> math;cin >> english;cin >> computor;
	totle = sum();
	aver = average();
}


Class::Class()
{
	cout << "班级人数："; cin >> n;
	cla = new Student[n];
	start = cla;
	for (int i = 0; i < n; i++)
	{
		cla->setData();
		cla++;
	}
}

void Class::display()
{
	cla = start;
	for (int i = 0; i < n; i++)
	{
		cla->display();
		cla++;
	}
}

void Class::sort()
{
	Student temp,*p;
	cla = start;
	for (int j = 0; j < n; j++)
	{
		p = cla;
		for (int i = j; i < n; i++)
		{
			//if (cla->getTotle() < p->getTotle())
			if (cla->totle < p->totle)
			{
				temp = *cla;
				*cla = *p;
				*p = temp;
			}
			p++;
		}
		cla++;
	}
}

void main()
{
	Class c1;
	c1.sort();
	cout << "按总成绩排序：" << endl;
	c1.display();
}
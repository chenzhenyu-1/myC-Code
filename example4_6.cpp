#include<iostream>
/*
���һ��ѧ����Student������˽�����ݳ�Ա��ѧ�š���������ѧ�ɼ���Ӣ��ɼ���������ɼ����ܳɼ���ƽ���ɼ���
���й��к�����Ա�������ſ��ܳɼ�sum������ƽ���ɼ�average��������ʾѧ��������Ϣdisplay����������ѧ��������ϢsetData������
��д��������ʵ��һ����ѧ�����ݵ�����ͼ���ÿ��ѧ�����ܳɼ���ƽ���ɼ������ܳɼ��������ѧ����Ϣ
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
	cout << "ѧ�ţ�" << num << endl;
	cout << "������" << name << endl;
	cout << "��ѧ�ɼ���" << math << " Ӣ��ɼ���" << english << " ������ɼ���" << computor << endl;
	cout << "�ܳɼ���" << totle << " ƽ���ɼ���" << aver << endl;
}

void Student::setData()
{
	cout << "������ѧ�ţ�";
	cin >> num;
	cout << "������";
	cin >> name;
	cout << "��ѧ��Ӣ�������ɼ���";
	cin >> math;cin >> english;cin >> computor;
	totle = sum();
	aver = average();
}


Class::Class()
{
	cout << "�༶������"; cin >> n;
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
	cout << "���ܳɼ�����" << endl;
	c1.display();
}
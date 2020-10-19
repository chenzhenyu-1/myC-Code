#include<iostream>
#include<fstream>
/*
建立学生成绩类，实现简单的成绩管理
*/
using namespace std;

class Scores {	
public:
	void setMath() { cout << "数学成绩："; cin >> math; }
	void setEnglish() { cout << "英语成绩："; cin >> english; }
	void setSpecialized() { cout << "专业成绩："; cin >> specialized; }
	int getMath() { return math; }
	int getEnglish() { return english; }
	int getSpecialized() { return specialized; }
	int sum() { return math + english + specialized; }
	int aver() { return sum() / 3; }

private:
	int math, english, specialized;
};
//成绩类，记录成绩和计算总、分平均分等功能

class Student{	
public:
	void setName() { cout << "姓名："; cin >> name; }
	void setNum() { cout << "学号："; cin >> num; }
	char* getName() { return name; }
	int getNum() { return num; }
	void setScores() { s.setMath(); s.setEnglish(); s.setSpecialized(); }
	Scores getScores() { return s; }
	void outputScores() { 
		cout << "数学成绩：" << s.getMath() << endl;
		cout << "英语成绩：" << s.getEnglish() << endl;
		cout << "专业成绩：" << s.getSpecialized() << endl;
		cout << "总成绩:" << s.sum() << endl;
	}
	void check() { 
		cout << "------------------" << endl;
		cout << "姓名：" << getName() << endl;
		cout << "学号：" << getNum() << endl;
		outputScores();
	}
	void setall() { setName(); setNum(); setScores(); }

private:
	char name[10];
	int num;
	Scores s;
};
//学生类，记录学生姓名学号和成绩

class list {	
public:
	list() { head = NULL; tail = NULL; }
	void insert(Student);
	void append(Student);
	Student gethead();
	void rank();
	void check() { 
		node *p = head; 
		while (p != NULL) {
			p->data.check();
			p = p->next;
		} 
	}
	void save(char*);
	int getSize() { return size; }

private:
	struct node
	{
		Student data;
		node *next,*previous;	//链表是双向的，方便排序功能的实现
	} *head, *tail;
	int size = 0;
};
//链表类，创建学生成绩记录的链表，并有排序、保存文件等功能

void list::insert(Student item) {
	node *temp;
	temp = new node;
	temp->data = item;
	temp->next = head;
	temp->previous = NULL;
	head->previous = temp;
	head = temp;
	if (tail == NULL)
		tail = head;
	size++;
}
//向链表头插入内容

void list::append(Student item) {
	node *temp;
	temp = new node;
	temp->data = item;
	temp->next = NULL;
	temp->previous = tail;
	if (tail != NULL)
		tail->next = temp;
	tail = temp;
	if (head == NULL)
		head = tail;
	size++;
}
//向链表尾插入内容

Student list::gethead() {
	if (head == NULL)
		exit(0);
	Student tp;
	node *np;
	tp = head->data;
	np = head;
	head = head->next;
	if(head!=NULL)
		head->previous = NULL;
	if (head == NULL)
		tail = NULL;
	delete(np);
	size--;
	return tp;
}
//取出链表头内容

void list::rank() {
	node *p, *q, *end;
	Student temp;
	Scores a, b;
	p = q = head;
	end = tail;
	a = q->data.getScores();
	while (end!=head) {
		while (p != end)
		{
			p = p->next;
			b = p->data.getScores();
			if (a.sum() < b.sum()) {
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
			q = q->next;
			a = q->data.getScores();
		}
		p = q = head;
		a = q->data.getScores();
		end = end->previous;
	}

}
//排序功能

void list::save(char *f) {
	ofstream out(f);
	out << "学生成绩：" << endl;
	node *p = head;
	while (p != NULL) {
		out << "-------------------------------" << endl;
		out << "姓名：" << p->data.getName() << endl;
		out << "学号：" << p->data.getNum() << endl;
		out << "数学成绩：" << p->data.getScores().getMath() << endl;
		out << "英语成绩：" << p->data.getScores().getEnglish() << endl;
		out << "专业成绩：" << p->data.getScores().getSpecialized() << endl;
		out << "总成绩:" << p->data.getScores().sum() << endl;
		p = p->next;
	}
	out.close();
}
//保存功能

int main() {	
	int mode; list group;
	while (1) {		//进入程序后不断循环，直到输入功能5退出系统
		cout << "欢迎使用学生成绩管理系统。" << endl;
		cout << "功能：\n1.输入学生成绩" << endl
			<< "2.查看学生成绩列表" << endl
			<< "3.对学生按总成绩高低进行降序排名" << endl
			<< "4.保存成绩列表到txt文件" << endl
			<< "5.退出系统" << endl;
		cout << "请输入要使用的功能:";
		cin >> mode;	//输入不同的数字使用不同的功能
		switch (mode)
		{
		case 1: {	//输入学生成绩，创建链表
			cout << "请输入学生人数：";
			int n;
			cin >> n;
			Student *p;
			p = new Student[n];
			for (int i = 0; i < n; i++) {
				(p + i)->setall();
				group.append(*(p + i));
			}
			delete[] p;
			cout << "输入完成。" << endl;
			system("pause");
			system("cls");
		}break;
		case 2: {	//输出当前链表的内容
			if (group.getSize() == 0)
				cout << "当前成绩列表为空。" << endl;
			else
				group.check();
			system("pause");
			system("cls");
		}break;
		case 3: {	//对链表以总分大小降序排序，给出排名
			if (group.getSize() == 0)
				cout << "当前成绩列表为空。" << endl;
			else {
				Student output;
				group.rank();
				cout << "排名完毕。" << endl;
				int size = group.getSize();
				for (int i = 0; i < size; i++) {
					output = group.gethead();
					cout << "------------------------------" << endl;
					cout << "排名" << i + 1 << "：" << output.getName();
					cout << "，总分：" << output.getScores().sum() << endl;
					group.append(output);
				}
			}
			system("pause");
			system("cls");
		}break;
		case 4: {	//保存当前链表内容到指定名字的文件中
			if (group.getSize() == 0)
				cout << "当前成绩列表为空。" << endl;
			else {
				cout << "输入要保存的文件名:";
				char name[20];
				cin >> name;
				group.save(name);
				cout << "保存完毕。" << endl;
			}
			system("pause");
			system("cls");
		}break;
		case 5:	//退出学生成绩管理系统
			cout << "即将退出系统。" << endl;
			return 0;
		default:	//输入的功能超出范围的一律以出错处理
			cout << "输入错误，请重新输入。" << endl;
			system("pause");
			system("cls");
		}
	}

}
//主程序
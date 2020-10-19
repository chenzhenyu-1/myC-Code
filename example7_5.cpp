#include<iostream>
#include<fstream>
/*
����ѧ���ɼ��࣬ʵ�ּ򵥵ĳɼ�����
*/
using namespace std;

class Scores {	
public:
	void setMath() { cout << "��ѧ�ɼ���"; cin >> math; }
	void setEnglish() { cout << "Ӣ��ɼ���"; cin >> english; }
	void setSpecialized() { cout << "רҵ�ɼ���"; cin >> specialized; }
	int getMath() { return math; }
	int getEnglish() { return english; }
	int getSpecialized() { return specialized; }
	int sum() { return math + english + specialized; }
	int aver() { return sum() / 3; }

private:
	int math, english, specialized;
};
//�ɼ��࣬��¼�ɼ��ͼ����ܡ���ƽ���ֵȹ���

class Student{	
public:
	void setName() { cout << "������"; cin >> name; }
	void setNum() { cout << "ѧ�ţ�"; cin >> num; }
	char* getName() { return name; }
	int getNum() { return num; }
	void setScores() { s.setMath(); s.setEnglish(); s.setSpecialized(); }
	Scores getScores() { return s; }
	void outputScores() { 
		cout << "��ѧ�ɼ���" << s.getMath() << endl;
		cout << "Ӣ��ɼ���" << s.getEnglish() << endl;
		cout << "רҵ�ɼ���" << s.getSpecialized() << endl;
		cout << "�ܳɼ�:" << s.sum() << endl;
	}
	void check() { 
		cout << "------------------" << endl;
		cout << "������" << getName() << endl;
		cout << "ѧ�ţ�" << getNum() << endl;
		outputScores();
	}
	void setall() { setName(); setNum(); setScores(); }

private:
	char name[10];
	int num;
	Scores s;
};
//ѧ���࣬��¼ѧ������ѧ�źͳɼ�

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
		node *next,*previous;	//������˫��ģ����������ܵ�ʵ��
	} *head, *tail;
	int size = 0;
};
//�����࣬����ѧ���ɼ���¼�������������򡢱����ļ��ȹ���

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
//������ͷ��������

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
//������β��������

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
//ȡ������ͷ����

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
//������

void list::save(char *f) {
	ofstream out(f);
	out << "ѧ���ɼ���" << endl;
	node *p = head;
	while (p != NULL) {
		out << "-------------------------------" << endl;
		out << "������" << p->data.getName() << endl;
		out << "ѧ�ţ�" << p->data.getNum() << endl;
		out << "��ѧ�ɼ���" << p->data.getScores().getMath() << endl;
		out << "Ӣ��ɼ���" << p->data.getScores().getEnglish() << endl;
		out << "רҵ�ɼ���" << p->data.getScores().getSpecialized() << endl;
		out << "�ܳɼ�:" << p->data.getScores().sum() << endl;
		p = p->next;
	}
	out.close();
}
//���湦��

int main() {	
	int mode; list group;
	while (1) {		//�������󲻶�ѭ����ֱ�����빦��5�˳�ϵͳ
		cout << "��ӭʹ��ѧ���ɼ�����ϵͳ��" << endl;
		cout << "���ܣ�\n1.����ѧ���ɼ�" << endl
			<< "2.�鿴ѧ���ɼ��б�" << endl
			<< "3.��ѧ�����ܳɼ��ߵͽ��н�������" << endl
			<< "4.����ɼ��б�txt�ļ�" << endl
			<< "5.�˳�ϵͳ" << endl;
		cout << "������Ҫʹ�õĹ���:";
		cin >> mode;	//���벻ͬ������ʹ�ò�ͬ�Ĺ���
		switch (mode)
		{
		case 1: {	//����ѧ���ɼ�����������
			cout << "������ѧ��������";
			int n;
			cin >> n;
			Student *p;
			p = new Student[n];
			for (int i = 0; i < n; i++) {
				(p + i)->setall();
				group.append(*(p + i));
			}
			delete[] p;
			cout << "������ɡ�" << endl;
			system("pause");
			system("cls");
		}break;
		case 2: {	//�����ǰ���������
			if (group.getSize() == 0)
				cout << "��ǰ�ɼ��б�Ϊ�ա�" << endl;
			else
				group.check();
			system("pause");
			system("cls");
		}break;
		case 3: {	//���������ִܷ�С�������򣬸�������
			if (group.getSize() == 0)
				cout << "��ǰ�ɼ��б�Ϊ�ա�" << endl;
			else {
				Student output;
				group.rank();
				cout << "������ϡ�" << endl;
				int size = group.getSize();
				for (int i = 0; i < size; i++) {
					output = group.gethead();
					cout << "------------------------------" << endl;
					cout << "����" << i + 1 << "��" << output.getName();
					cout << "���ܷ֣�" << output.getScores().sum() << endl;
					group.append(output);
				}
			}
			system("pause");
			system("cls");
		}break;
		case 4: {	//���浱ǰ�������ݵ�ָ�����ֵ��ļ���
			if (group.getSize() == 0)
				cout << "��ǰ�ɼ��б�Ϊ�ա�" << endl;
			else {
				cout << "����Ҫ������ļ���:";
				char name[20];
				cin >> name;
				group.save(name);
				cout << "������ϡ�" << endl;
			}
			system("pause");
			system("cls");
		}break;
		case 5:	//�˳�ѧ���ɼ�����ϵͳ
			cout << "�����˳�ϵͳ��" << endl;
			return 0;
		default:	//����Ĺ��ܳ�����Χ��һ���Գ�����
			cout << "����������������롣" << endl;
			system("pause");
			system("cls");
		}
	}

}
//������
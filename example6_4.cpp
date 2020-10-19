#include <iostream>
#include <process.h>
using namespace std;

template <class T> class list {

	struct node {
		T data;
		node * next;
	} *head, *tail;

	/*
	���ݳ�Աhead��tail��Ϊָ�롣���е�head��ָ����������
	��tail��ָ�������β�ÿ��׼���������м���һ������(��
	�����data����)ʱ������������ʹ�á�new node������̬����
	һ���µı���ռ䣬�������롱�ñ����data���ݣ�����ͨ��ָ
	��ĸı�����������ñ�����뵽��headΪ����tailΪβ�ĵ�ǰ
	����ṹ��(���γ�һ�����º������)��
	*/
public:
	bool find(T *item);//����find����������ʵ��������

	list() {    //���캯��������һ����������
		head = tail = NULL;
	}

	void Insert(T * item) {
		//��̬����������ռ䣬����item��ָ���T�����ݷ��������data��
		//���������ɵĸ���������뵽ԭ�������ף�����ġ�ջ��ʽ�÷�����
		node *pn;
		pn = new node;
		pn->next = head;
		pn->data = *item;
		head = pn;
		if (tail == NULL)tail = pn;
	}

	void Append(T * item) {
		//��̬����������ռ䣬����item��ָ���T�����ݷ�������data��
		//���������ɵĸ���ӵ�ԭ������β������ġ����С�ʽ�÷����� 
		node *pn;
		pn = new node;
		pn->next = NULL;
		pn->data = *item;
		if (tail == NULL)
			head = tail = pn;
		else {
			tail->next = pn;
			tail = pn;
		}
	}

	T get() {
		//ȡ��������������ݣ�data��ֵ���������������������ɾȥ 
		if (head == NULL)
			exit(0);
		T temp = head->data;
		node *pn = head;
		if (head->next == NULL)
			head = tail = NULL;
		else
			head = head->next;
		delete(pn);
		return temp;
	}

};    //��ģ��list�������
class person {
public:
	char name[20];
	int age;
	float hight;
	//Ϊ��ʹfind����������person���������==�����
	bool operator ==(person &a) {
		if (strcmp(a.name, name) == 0 && a.age == age&&a.hight == hight)
			return true;
		else
			return false;
	}
};
/*  ע����˵��Ϊ��char* name;��������������Ҫͨ��newΪÿһ����
��name�����붯̬�ռ䣡  */

template<class T>
bool list<T>::find(T *item) {
	node *p = head;
	while (p != NULL)
	{
		if (p->data == *item)
			return true;
		p = p->next;
	}
	return false;
}//����find����

void main() {
	person ps;
	list <int> link1;
	list <person> link2;
	cout << "  --- Input 5 person's information ---" << endl;
	for (int i = 0; i<5; i++) {
		//����5���˵��й���Ϣ�����д��� 
		cin >> ps.name >> ps.age >> ps.hight;
		link2.Insert(&ps);
		link1.Append(&i);
	}
	/*
	����ѭ��������link1��link2������߼��ṹ����������:
	link1����:     	head -> 0 -> 1 -> 2 -> 3 -> 4
	link2����:     	head -> 4����Ա��Ϣ -> 3����Ա��Ϣ -> 2����Ա��Ϣ -> 1����Ա��Ϣ -> 0����Ա��Ϣ
	*/

	cout << "  ----- The result ----" << endl;
	for (int i = 0; i<5; i++) {
		ps = link2.get();      //ȡ��link2�����������Ա��Ϣ
		link2.Append(&ps);
		//���մ�link2��ȡ������Ա��Ϣ��
		//��һ�θ��ӵ�link2�������β
		cout << ps.name << " " << link1.get() << endl;
		//���link2������Ա��Ϣ��name��
		//�Լ�link1��������еĶ����˳���
	}
	//��ʼ����find����
	person p1;
	cin >> p1.name >> p1.age >> p1.hight;
	if (link2.find(&p1))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}
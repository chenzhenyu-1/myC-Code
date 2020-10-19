#include <iostream>
#include <process.h>
using namespace std;

template <class T> class list {

	struct node {
		T data;
		node * next;
	} *head, *tail;

	/*
	数据成员head与tail均为指针。其中的head总指向链表的首项，
	而tail总指向链表的尾项。每当准备往链表中加入一个表项(及
	其表项data数据)时，程序中首先使用“new node”来动态生成
	一个新的表项空间，并“填入”该表项的data数据，而后通过指
	针的改变与关联，将该表项加入到以head为首以tail为尾的当前
	链表结构中(以形成一个更新后的链表)。
	*/
public:
	bool find(T *item);//声明find函数，具体实现在类外

	list() {    //构造函数，创建一个“空链表”
		head = tail = NULL;
	}

	void Insert(T * item) {
		//动态生成链表项空间，并将item所指向的T型数据放至该项的data；
		//而后将新生成的该链表项插入到原链的链首（链表的“栈”式用法）。
		node *pn;
		pn = new node;
		pn->next = head;
		pn->data = *item;
		head = pn;
		if (tail == NULL)tail = pn;
	}

	void Append(T * item) {
		//动态生成链表项空间，并将item所指向的T型数据放入该项的data；
		//而后将新生成的该项附加到原链的链尾（链表的“队列”式用法）。 
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
		//取出链表首项的数据（data域值），并将该首项从链表中删去 
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

};    //类模板list定义结束
class person {
public:
	char name[20];
	int age;
	float hight;
	//为了使find函数适用于person类对象，重载==运算符
	bool operator ==(person &a) {
		if (strcmp(a.name, name) == 0 && a.age == age&&a.hight == hight)
			return true;
		else
			return false;
	}
};
/*  注：若说明为“char* name;”，则主函数处要通过new为每一对象
的name域申请动态空间！  */

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
}//定义find函数

void main() {
	person ps;
	list <int> link1;
	list <person> link2;
	cout << "  --- Input 5 person's information ---" << endl;
	for (int i = 0; i<5; i++) {
		//输入5个人的有关信息并进行处理 
		cin >> ps.name >> ps.age >> ps.hight;
		link2.Insert(&ps);
		link1.Append(&i);
	}
	/*
	上述循环结束后，link1和link2链表的逻辑结构及内容如下:
	link1链表:     	head -> 0 -> 1 -> 2 -> 3 -> 4
	link2链表:     	head -> 4号人员信息 -> 3号人员信息 -> 2号人员信息 -> 1号人员信息 -> 0号人员信息
	*/

	cout << "  ----- The result ----" << endl;
	for (int i = 0; i<5; i++) {
		ps = link2.get();      //取出link2链表首项的人员信息
		link2.Append(&ps);
		//将刚从link2首取来的人员信息，
		//再一次附加到link2链表的链尾
		cout << ps.name << " " << link1.get() << endl;
		//输出link2链表人员信息的name，
		//以及link1链表表项中的对象的顺序号
	}
	//开始测试find函数
	person p1;
	cin >> p1.name >> p1.age >> p1.hight;
	if (link2.find(&p1))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}
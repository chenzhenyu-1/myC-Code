#include<iostream>
using namespace std;
void main(void) {
	int i;
	struct person {
		char name[12];
		int age;
		char sex;
		person *next;
	};
	person *head, *tail, *temp;
	temp = new person;
	head = temp;
	tail = head;
	for (i = 1; ; i++) {
		cout << endl << i << " " << "name:";
		cin >> temp->name;
		if (temp->name[0] != '*') {
			cout << "age:"; cin >> temp->age;
			cout << "sex:"; cin >> temp->sex;
			temp->next = NULL;
			tail = temp;
		}
		else {
			delete temp;
			tail->next = NULL;
			break;
		}
		temp->next = new person;
		temp = temp->next;
	}
	temp = head;
	while (temp != NULL) {
		cout << endl << temp->name << " " << temp->age;
		cout << " " << temp->sex << endl;
		temp = temp->next;
	}
}

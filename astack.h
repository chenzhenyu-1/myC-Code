//astack.h 
#include <iostream>
using namespace std;
const int MaxSize=50;//栈的最大容量
//实现栈的功能
class Stack 
	{
	private:
		char slist[MaxSize];
		int top;
	public:
		Stack(void){top=0;};
		~Stack(void){};
		void Push(const char &item);
		char Pop(void);
		int StackEmpty(void) const {return top==0;};
		int StackFull(void) const {return top==MaxSize;};
};

void Stack::Push(const char &item){
	if (top==MaxSize)
		cout<<"Stack overflow!"<<endl;
	else {
		slist[top]=item;
		top++;
	}
}

char Stack::Pop(void){
	if (top==0){
		cout<<"an empty stack!"<<endl;
		return 0;
	}
	top--;
	return slist[top];
}

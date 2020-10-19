//program8_6.cpp
# include<iostream>
using namespace std;
class B0	//声明基类B0
{
public:	//外部接口
	B0(int n) { nV = n; cout << "Member of B0" << endl; }
	int nV;
};
class B1 : virtual public B0
{
public:
	B1(int a) : B0(a) { cout << "Member of B1" << endl; }
	int nV1;
};
class B2 : virtual public B0
{
public:
	B2(int a) : B0(a) { cout << "Member of B2" << endl; }
	int nV2;
};
class D1 : public B1, public B2
{
public:
	D1(int a, int b, int c) : B1(b), B2(c), B0(a) { cout << "Member of D1" << endl; }
	int nVd;
};
void main()
{
	D1 d1(4, 5, 6);
	cout << d1.nV << endl;
}

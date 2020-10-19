#include <math.h>
#include <iostream>
using namespace std;
class point {   //定义一个point 类（平面上的点）
private://私有成员，本类成员可以直接访问，对象不能直接访问。
	float Xcoord;//数据成员，横坐标
	float Ycoord;//数据成员，纵坐标
public://公有成员
	point()
	{
		cout << " point() invoked" << endl;
		Xcoord = 0;
		Ycoord = 0;
	}
	point(float x, float y)
	{
		cout << " point(float x,float y) invoked" << endl;
		Xcoord = x;
		Ycoord = y;
	}
	void print()
	{
		cout << "(" << Xcoord << "," << Ycoord << ")" << endl;
	}

	void  SetX(float x)//成员函数，设置Xcoord
	{
		Xcoord = x;
	}
	void  SetY(float y)//成员函数，设置Ycoord
	{
		Ycoord = y;
	}

	float GetX()//成员函数，返回Xcoord
	{
		return Xcoord;
	}
	float GetY()//成员函数，返回Ycoord
	{
		return Ycoord;
	}
	double GetDistance(point p) //成员函数,求两点间的距离。
								//调用形式为：dis=p1.GetDistance(p2);即求p1、p2两点间的距离。
	{
		float x = Xcoord - p.Xcoord;
		float y = Ycoord - p.Ycoord;
		return sqrt(x*x + y*y);
	}
	point midpoint(point p)
	{
		point mid((Xcoord + p.Xcoord) / 2, (Ycoord + p.Ycoord) / 2);
		return mid;
	}
	~point()
	{
		cout << " ~point() invoked" << endl;
	}
};//类point定义结束 ,注意要有分号

void main()
{

	point point1(2, 4), point2;
	point2.SetX(3);
	point2.SetY(6);
	cout << "(" << point1.GetX() << "," << point1.GetY() << ")"<<"到";
	cout << "(" << point2.GetX() << "," << point2.GetY() << ")"<<"的距离是：";
	cout << point1.GetDistance(point2) << endl;
	cout << "(" << point1.GetX() << "," << point1.GetY() << ")" << "与";
	cout << "(" << point2.GetX() << "," << point2.GetY() << ")" << "的中点是：";
	point1.midpoint(point2).print();
	point1.print();
}

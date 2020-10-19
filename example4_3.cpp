#include <math.h>
#include <iostream>
using namespace std;
class point {   //����һ��point �ࣨƽ���ϵĵ㣩
private://˽�г�Ա�������Ա����ֱ�ӷ��ʣ�������ֱ�ӷ��ʡ�
	float Xcoord;//���ݳ�Ա��������
	float Ycoord;//���ݳ�Ա��������
public://���г�Ա
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

	void  SetX(float x)//��Ա����������Xcoord
	{
		Xcoord = x;
	}
	void  SetY(float y)//��Ա����������Ycoord
	{
		Ycoord = y;
	}

	float GetX()//��Ա����������Xcoord
	{
		return Xcoord;
	}
	float GetY()//��Ա����������Ycoord
	{
		return Ycoord;
	}
	double GetDistance(point p) //��Ա����,�������ľ��롣
								//������ʽΪ��dis=p1.GetDistance(p2);����p1��p2�����ľ��롣
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
};//��point������� ,ע��Ҫ�зֺ�

void main()
{

	point point1(2, 4), point2;
	point2.SetX(3);
	point2.SetY(6);
	cout << "(" << point1.GetX() << "," << point1.GetY() << ")"<<"��";
	cout << "(" << point2.GetX() << "," << point2.GetY() << ")"<<"�ľ����ǣ�";
	cout << point1.GetDistance(point2) << endl;
	cout << "(" << point1.GetX() << "," << point1.GetY() << ")" << "��";
	cout << "(" << point2.GetX() << "," << point2.GetY() << ")" << "���е��ǣ�";
	point1.midpoint(point2).print();
	point1.print();
}

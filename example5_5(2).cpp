//program8_5.cpp 
# include<iostream>
using namespace std;
float function(float x) { //��������
	return 4.0 / (1 + x*x);
};

float f1(float x) {
	return x*x - x;
}

class inte_algo {         //�����ֻ���
protected:
	float a, b;           //��������
	int n;               //��������ĵȷ���
	float h, sum;         //�����ͻ���ֵ
	float (*function)(float);
public:
	inte_algo(float left, float right, int steps,float (*f)(float)) {//���캯��
		a = left;
		b = right;
		n = steps;
		h = (b - a) / n;
		sum = 0.0;
		function = f;
	};
	virtual void integrate(void) = 0;//�󶨻��ֵ��麯���������Ϊ���麯��
};

class rectangle :public inte_algo {//���η�������
public:
	rectangle(float left, float right, int steps, float (*f)(float)) :inte_algo(left, right, steps, f) {};
	void integrate(void);
};

class ladder :public inte_algo {//���η�������
public:
	ladder(float left, float right, int steps, float (*f)(float)) :inte_algo(left, right, steps,f) {};
	void integrate(void);
};

class simpson :public inte_algo {//����ѷ��������
public:
	simpson(float left, float right, int steps, float (*f)(float)) :inte_algo(left, right, steps,f) {};
	void integrate(void);
};

/*void inte_algo::integrate(void) {//���ڻ��������Ϊ���麯��������δ���Ӧɾ��
	cout << sum << endl;
}*/

void rectangle::integrate(void) {
	float a1 = a;
	for (int i = 0; i<n; i++) {
		sum += function(a1);
		a1 += h;
	}
	sum *= h;             //sum=(f(a)+f(a+h)+f(a+2h)+...+f(a+(n-1)*h))*h
	cout << sum << endl;
}

void ladder::integrate(void) {
	float a1 = a;
	sum = (function(a) + function(b)) / 2.0;
	for (int i = 1; i<n; i++) {
		a1 += h;
		sum += function(a1);
	}
	sum *= h;            //sum=(f(a)+2f(a+h)+2f(a+2h)+...+2f(a+(n-1)h)+f(b))h/2
	cout << sum << endl;
}

void simpson::integrate(void) {
	sum = function(a) + function(b);
	float s = 1.0, a1 = a;
	for (int i = 1; i<n; i++) {
		a1 += h;
		sum += (3.0 + s)*function(a1); //ϵ��4,2���棬ʹ��3��1ʵ��
		s = -s;
	}
	sum *= h /= 3.0;        //sum=(f(a)+4f(a+h)+2f(a+2h)+4f(a+3h)+2f(a+4h)+...+2f(a+(n-2)h+4f(a+(n-1)h)+f(b))h/3
	cout << sum << endl;
}
void main(void) {
	rectangle rec(0.0, 1.0, 10,&f1);
	ladder lad(0.0, 1.0, 10, &f1);
	simpson sim(0.0, 1.0, 10, &f1);
	inte_algo *p1 = &rec, *p2 = &lad, *p3 = &sim;//ʹ�û���ָ��ָ���������
	p1->integrate();
	p2->integrate();
	p3->integrate();//�麯�������ÿ����ֳ��������õķֱ��Ǹ���������麯��
}

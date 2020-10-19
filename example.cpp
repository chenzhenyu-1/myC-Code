#include <iostream >
/*
编程序，解决搬砖问题。有36块砖，由成年男、女和小孩共30人来搬，
男子每人搬4块，女子每人搬3块，两个小孩抬一块，要求一次全搬完，
问需要男、女、小孩各几人?
*/

using namespace std;
class Worker
{
private:
	float brick = 0;
public:
	int count = 0;
	void set(float a) { brick = a; };
	float move(float b) { count++; return b - brick; };
};

void main()
{
	Worker man, woman, child;
	man.set(4); woman.set(3); child.set(0.5);
	float brick = 36;
	int am, bm, totle = 0;
	am = bm = 30;
	while(totle!=30){
		while (brick != 0)
		{
			for (int a = 0; a < am; a++) {
				if (brick >= 4)
					brick = man.move(brick);
				else
					break;
			}
			for(int b = 0; b < bm; b++) {
				if (brick >= 3)
					brick = woman.move(brick);
				else
					break;
			}
			for (int c = 0; c < 30; c++) {
				if (brick >= 1) {
					brick = child.move(brick);
					brick = child.move(brick);
				}
				else
					break;
			}
			totle = man.count + woman.count + child.count;
			if (totle != 30) {
				if (am > 1)
					am = man.count - 1;
				else
					bm = woman.count - 1;
				man.count = woman.count = child.count = 0;
				brick = 36;
			}
		}
	}
	cout << "结果：" << endl;
	cout << "man:" << man.count << " woman:" << woman.count << " child:" << child.count << endl;
}
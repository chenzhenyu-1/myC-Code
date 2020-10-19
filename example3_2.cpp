#include<iostream>
using namespace std;
void main() {
	int lin, col, i, j;
	cin >> lin >> col;
	int **a;
	a = new int*[lin];
	for (i = 0; i < lin; i++)
		a[i] = new int[col];
	for (i = 0; i < lin; i++)
	{
		for (j = 0; j < col; j++)
		{
			a[i][j] = i + j;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
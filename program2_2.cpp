#include "astack.h"

void main() {
	Stack S;
	char palstring[80], ch;
	int i = 0;
	bool ispalindrom = true;
	cin >> palstring;
	while (palstring[i] != 0) {
		S.Push(palstring[i]);
		i++;
	}
	i = 0;
	while (!S.StackEmpty()) {
		ch = S.Pop();
		if (ch != palstring[i]) {
			ispalindrom = false;
			break;
		}
		else
			i++;
	}
	if (ispalindrom)
		cout << '\'' << palstring << "'" << "is palindrom" << endl;
	else
		cout << '\'' << palstring << "'" << "is not palindrom" << endl;

}
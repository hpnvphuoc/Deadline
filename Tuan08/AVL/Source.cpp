#include"AVL.h"
void main() {
	NODE* p = nullptr;
	Insert(p, 10);
	NLR(p);
	cout << endl;
	Insert(p, 8);
	NLR(p);
	cout << endl;

	Insert(p, 11);
	NLR(p);
	cout << endl;

	Insert(p, 7);
	NLR(p);
	cout << endl;

	Insert(p, 9);
	NLR(p);
	cout << endl;

	Insert(p, 1);
	NLR(p);
	cout << endl;
	Insert(p, 2);
	NLR(p);
	cout << endl;
	Insert(p, 3);
	NLR(p);
	cout << endl;
	Insert(p, 4);
	NLR(p);
	cout << endl;
	Insert(p, 5);
	NLR(p);
	cout << endl;
	Insert(p, 6);
	NLR(p);
	cout << endl;
	Insert(p, 20);
	NLR(p);
	cout << endl;
	Insert(p, 21);
	NLR(p);
	cout << endl;
	Insert(p, 22);
	NLR(p);
	cout << endl;
	Insert(p, 23);
	NLR(p);
	cout << endl;
	Remove(p,8);
	Insert(p, 8);
	Remove(p, 3);
	Remove(p, 2);
	Remove(p, 6);
	Remove(p, 20);
	NLR(p);
	system("pause");


}
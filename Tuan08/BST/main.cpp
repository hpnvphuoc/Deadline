#include"header.h"
void main() {
	NODE* p = nullptr;
	Insert(p, 6);
	Insert(p, 4);
	Insert(p, 15);
	Insert(p, 3);
	Insert(p, 5);
	Insert(p, 16);
	Insert(p, 10);
	Insert(p, 2);
	Insert(p, 7);
	Insert(p, 11);
	Insert(p, 1);
	Insert(p, 8);
	Insert(p, 9);
	//Remove(p, 7);
	cout << endl;
	cout<<IsBST(p);
	system("pause");

}
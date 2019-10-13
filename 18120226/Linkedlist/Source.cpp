#include"list.h"
void main() {
	List* L;
	L=createList();
	addHead(L, 5);
	addHead(L, 6);
	addTail(L, 4);
	addTail(L, 4);
	addTail(L, 3);
	removeDuplicate(L);
	removeAll(L);
}
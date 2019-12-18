#ifndef AVL_H_
#define AVL_H_
#include<iostream>
using namespace std;
#include<math.h>
#include <algorithm>
#include<vector>
#include<queue>
struct NODE {
	int key;
	NODE* p_left;
	NODE* p_right;
	int height;
};
NODE* CreateNode(int data);
void Insert(NODE*& p_root, int x);
void Remove(NODE*& p_root, int x);
bool IsAVL(NODE* p_root);
void NLR(NODE* p_root);
void LNR(NODE* p_root);
void LRN(NODE* p_root);
void LevelOrder(NODE* p_root);
#endif // !AVL_H_


#include "header.h"

NODE* CreateNode(int data)
{
	NODE* temp = new NODE;
	temp->key = data;
	temp->p_left = nullptr;
	temp->p_right = nullptr;
	return temp;
}

void NLR(NODE* p_root)
{
	if (p_root == nullptr) {
		return;
	}
	cout << p_root->key<<" ";
	NLR(p_root->p_left);
	NLR(p_root->p_right);
}
NODE* Search(NODE* p_root, int x)
{
	if (p_root == nullptr) {
		cout << "Not Found"<<endl;
		return nullptr;
	}
	if (x == p_root->key) {
		return p_root;
	}
	if (x > p_root->key) {
		Search(p_root->p_right, x);
	}
	else{
		Search(p_root->p_left, x);
	}
}
void LNR(NODE* p_root) {
	
	if (p_root == nullptr) {
		return;
	}
	LNR(p_root->p_left);
	cout << p_root->key<<" ";
	LNR(p_root->p_right);

}
void LRN(NODE* p_root) {

	if (p_root == nullptr) {
		return;
	}
	LNR(p_root->p_right);
	LNR(p_root->p_left);
	cout << p_root->key<<" ";

}
void Insert(NODE*& p_root, int x)
{
	if (p_root == nullptr) {
		p_root = CreateNode(x);
		return;
	}
	if (x > p_root->key) {
		if (p_root->p_right == nullptr) {
			p_root->p_right = CreateNode(x);
			return;
		}
		Insert(p_root->p_right,x);
	}
	if (x < p_root->key) {
		if (p_root->p_left == nullptr) {
			p_root->p_left = CreateNode(x);
			return;
		}
		Insert(p_root->p_left, x);
	}
}

int Height(NODE* p_root) {
	if (p_root==nullptr) {
		return 0;
	}
	int heightLeft = Height(p_root->p_left);
	int heightRight = Height(p_root->p_right);
	if (heightLeft > heightRight) {
		return heightLeft + 1;
	}
	else
	{
		return heightRight + 1;
	}
}
int CountNode(NODE* p_root) {
	if (p_root == nullptr) {
		return 0;
	}
	int NumNodeLeft = CountNode(p_root->p_left);
	int NumNodeRight = CountNode(p_root->p_right);
	return NumNodeLeft + NumNodeRight + 1;
}
bool IsBST(NODE* p_root)
{
	bool isBST_Left=true;
	bool isBST_Right=true;
	if (p_root == nullptr) {
		return true;
	}
	if (p_root->p_left == nullptr) {
		//TH la node la
		if (p_root->p_right == nullptr)
		{
			return true;
		}
		else //chi co con phai di ve ben phai
		{
			if (p_root->key > p_root->p_right->key) {
				return false;
			}
			 isBST_Right = IsBST(p_root->p_right);
		}
	}else {
		if (p_root->p_right == nullptr)//chi co con trai thi di ve ben trai
		{
			if (p_root->key < p_root->p_left->key) {
				return false;
			}
			 isBST_Left = IsBST(p_root->p_left);
		}
		else {//co ca 2 con thi di ve ben trai truoc roi sau do di ve ben phai
			if (p_root->key < p_root->p_left->key) {
				return false;
			}
			isBST_Left = IsBST(p_root->p_left);
			if (p_root->key > p_root->p_right->key) {
				return false;
			}
			isBST_Right = IsBST(p_root->p_right);
		}
	}
	return isBST_Left && isBST_Right;

}
void Remove(NODE*& p_root, int x) {
	if (p_root == nullptr) {
		cout << "NOT FOUND";
		return;
	}
	if (p_root->key == x) {
		if (p_root->p_left == nullptr) {
			if (p_root->p_right == nullptr) {
				delete p_root;
				p_root = nullptr;
				return;
			}
			else {
				NODE* p = p_root;
				p_root=p->p_right;
				delete p;
				return;

			}
			
		}
		else {
			if (p_root->p_right == nullptr) {
				NODE* p = p_root;
				p_root = p->p_left;
				delete p;
				return;
			}
			else {
				NODE* p = p_root->p_right;
				while (p->p_left != nullptr) {
					p = p->p_left;
				};
				p_root->key = p->key;
				Remove(p_root->p_right, p->key);
				return;
			}
		}
		
	}
	if (x > p_root->key) {
		Remove(p_root->p_right,x);
	}
	else {
		Remove(p_root->p_left,x);
	}	
}
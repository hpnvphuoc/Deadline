#include "AVL.h"

NODE* CreateNode(int data)
{
	NODE* temp = new NODE;
	temp->key = data;
	temp->p_left = nullptr;
	temp->p_right = nullptr;
	temp->height = 0;
	return temp;
}
int Height(NODE* p_root)
{
	if (p_root) {
		return max(Height(p_root->p_left), Height(p_root->p_right)) + 1;
	}
	return 0;
}

bool IsAVL(NODE* p_root) {
	if (p_root) {
		int leftHeight = Height(p_root->p_left);
		int rightHeight = Height(p_root->p_right);
		if (abs(leftHeight - rightHeight) <= 1 && IsAVL(p_root->p_left) && IsAVL(p_root->p_right)) {
			return true;
		}
		return false;
	}
	return true;
}

void NLR(NODE* p_root) {
	if (p_root == nullptr) {
		return;
	}
	cout << p_root->key << "(" << p_root->height << ") ";
	NLR(p_root->p_left);
	NLR(p_root->p_right);
}
void LNR(NODE* p_root) {
	if (p_root == nullptr) {
		return;
	}
	LNR(p_root->p_left);
	cout << p_root->key<<"("<<p_root->height<<") ";
	LNR(p_root->p_right);
}
void LRN(NODE* p_root) {

	if (p_root == nullptr) {
		return;
	}
	LNR(p_root->p_right);
	LNR(p_root->p_left);
	cout << p_root->key<<"("<<p_root->height<<") ";

}

void LeftRotate(NODE*& p_root) {
	NODE* tempRoot = p_root;
	p_root = p_root->p_right;
	tempRoot->p_right = p_root->p_left;
	p_root->p_left = tempRoot;
}
void RightRotate(NODE*& p_root) {
	NODE* tempRoot = p_root;
	p_root = p_root->p_left;
	tempRoot->p_left = p_root->p_right;
	p_root->p_right = tempRoot;

}
int IsBalanced(NODE* p_root) {

	if (p_root->p_left == nullptr) {
		if (p_root->p_right == nullptr) {
			return 0;
		}
		else {
			return p_root->p_right->height;
		}
	}
	else {
		if (p_root->p_right == nullptr) {
			return -p_root->p_left->height;
		}
		else {
			return p_root->p_right->height - p_root->p_left->height;
		}
	}
}

void Insert(NODE*& p_root, int x) {
	if (p_root == nullptr) {
		p_root = CreateNode(x);
		p_root->height = 1;
		return;
	}
	if (x > p_root->key) {
		if (p_root->p_right == nullptr) {
			p_root->p_right = CreateNode(x);
			p_root->p_right->height = 1;
			p_root->height = 2;
			return;
		}
		Insert(p_root->p_right, x);
		p_root->height = Height(p_root);

	}
	if (x < p_root->key) {
		if (p_root->p_left == nullptr) {
			p_root->p_left = CreateNode(x);
			p_root->p_left->height = 1;
			p_root->height = 2;
			return;
		}
		Insert(p_root->p_left, x);
		p_root->height = Height(p_root);
	}

	if (p_root) {
		if (IsBalanced(p_root)<-1) {
			if (IsBalanced(p_root->p_left) == -1) {
				RightRotate(p_root);
				p_root->p_right->height = Height(p_root->p_right);
				p_root->height = Height(p_root);
			}
			else {
				LeftRotate(p_root->p_left);
				RightRotate(p_root);
				p_root->p_left->height = Height(p_root->p_left);
				p_root->p_right->height = Height(p_root->p_right);
				p_root->height = Height(p_root);
			}
			
		}
		else {
			if (IsBalanced(p_root)>1) {
				if (IsBalanced(p_root->p_right) == 1) {
					LeftRotate(p_root);
					p_root->p_left->height = Height(p_root->p_left);
					p_root->height = Height(p_root);

				}
				else {
					RightRotate(p_root->p_right);
					LeftRotate(p_root);
					p_root->p_left->height = Height(p_root->p_left);
					p_root->p_right->height = Height(p_root->p_right);
					p_root->height = Height(p_root);
				}
			}
		}
	}
}
	
	


 void Remove(NODE*& p_root, int x)
{
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
				 p_root = p->p_right;
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
		 Remove(p_root->p_right, x);
	 }
	 else {
		 Remove(p_root->p_left, x);
	 }
	//update chieu cao cua cay
	 p_root->height = Height(p_root);
	 //xoay cay neu xay ra bat thuong
	 if (p_root) {
		if (IsBalanced(p_root)<-1) {
			if (IsBalanced(p_root->p_left) == -1) {
				RightRotate(p_root);
				p_root->p_right->height = Height(p_root->p_right);
				p_root->height = Height(p_root);
			}
			else {
				LeftRotate(p_root->p_left);
				RightRotate(p_root);
				p_root->p_left->height = Height(p_root->p_left);
				p_root->p_right->height = Height(p_root->p_right);
				p_root->height = Height(p_root);
			}
			
		}
		else {
			if (IsBalanced(p_root)>1) {
				if (IsBalanced(p_root->p_right) == 1) {
					LeftRotate(p_root);
					p_root->p_left->height = Height(p_root->p_left);
					p_root->height = Height(p_root);

				}
				else {
					RightRotate(p_root->p_right);
					LeftRotate(p_root);
					p_root->p_left->height = Height(p_root->p_left);
					p_root->p_right->height = Height(p_root->p_right);
					p_root->height = Height(p_root);
				}
			}
		}
	}
}

void LevelOrder(NODE* p_root)
{
	vector <NODE*> queue;
	NODE* current = p_root;
	queue.push_back(current);
	while (!queue.empty())
	{
		current = queue[0];
		cout << queue[0]->key<< "(" << queue[0]->height <<") " << endl;
		queue.erase(queue.begin());
		if (current->p_left)
			queue.push_back(current->p_left);
		if (current->p_right)
			queue.push_back(current->p_right);
	}
}
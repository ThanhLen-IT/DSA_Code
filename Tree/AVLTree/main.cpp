/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -


struct node {
	int info;
	node* left, * right;
};

typedef node* Tree;

node* getNode(int x) {
	node* p = new node;
	p->info = x;
	p->left = p->right = NULL;
	return p;
}

void insertNode(Tree& T, int x) {
	if (T == NULL) {
		T = getNode(x);
		return;
	}

	if (x == T->info)
		return;

	if (x < T->info)
		insertNode(T->left, x);
	else
		insertNode(T->right, x);
}

void inputTree(Tree& T) {
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		insertNode(T, x);
	}
}

int height(Tree T) {
	if (!T) return 0;
	int h1 = height(T->left);
	int h2 = height(T->right);
	return 1 + max(h1, h2);
}

bool isAVL(Tree T) {
	if (!T) return 1;
	
	if (abs(height(T->left) - height(T->right)) > 1)
		return 0;
	
	return isAVL(T->left) && isAVL(T->right);


}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << isAVL(T);
	return 0;
}

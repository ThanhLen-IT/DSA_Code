/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct node
{
	int info;
	node* left;
	node* right;
};
typedef node* Tree;

Tree getNode(int x) {
	Tree p = new node;
	p->info = x;
	p->left = p->right = NULL;
	return p;
}

void insertTree(Tree& T, int x) {
	if (!T) {
		T = getNode(x);
		return;
	}
	if (x < T->info) insertTree(T->left, x);
	if (x > T->info) insertTree(T->right, x);
}

void inputTree(Tree& T) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		insertTree(T, x);
	}
}

void NLR(Tree T) {
	if (!T) return;
	cout << T->info << " ";
	NLR(T->left);
	NLR(T->right);
}

void replaceNode(Tree& p, Tree& q) {
	if (q->left) {
		replaceNode(p, q->left);
	}
	else {
		p->info = q->info;
		p = q;
		q = q->right;
	}
}

void deleteNode(Tree& T, int x) {
	if (T == NULL) return;
	if (x < T->info)
		deleteNode(T->left, x);
	else if (x > T->info)
		deleteNode(T->right, x);
	else {
		Tree p = T;
		if (T->left == NULL)
			T = T->right;
		else if (T->right == NULL)
			T = T->left;
		else
			replaceNode(p, T->right);
		delete p;
	}
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "NLR: "; NLR(T);
	int x; cout << "\nEnter the element you want to delete: ";cin >> x;
	deleteNode(T, x);
	cout << "\nNLR: "; NLR(T);

	return 0;
}

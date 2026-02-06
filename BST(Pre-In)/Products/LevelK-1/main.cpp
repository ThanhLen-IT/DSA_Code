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

void nodesWithLevel(Tree T, int k, int curLevel = 0) {
	if (!T) return;

	if (curLevel == k) {
		cout << T->info << " "; 
		return; 
	}

	nodesWithLevel(T->right, k, curLevel + 1);
	nodesWithLevel(T->left, k, curLevel + 1);
	
}


int main()
{
	Tree T = NULL;
	inputTree(T);
	int k; cout << "Enter k: "; cin >> k;
	cout << "\nList of nodes with level " << k << " (R->L) : ";
	nodesWithLevel(T, k);

	return 0;
}

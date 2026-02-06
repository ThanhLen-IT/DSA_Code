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

int countNodes(Tree T) {
	if (T == NULL) return 0;
	return countNodes(T->left) + countNodes(T->right) + 1;
}

int countLeafs(Tree T) {
	if (!T) return 0;
	return (T->left == NULL && T->right == NULL) ? countLeafs(T->left) + countLeafs(T->right) + 1 : countLeafs(T->left) + countLeafs(T->right);
}

void LNR(Tree T) {
	if (!T) return;
	LNR(T->left);
	cout << T->info << " ";
	LNR(T->right);
}

int countInternalNodes2(Tree T) {
	if (!T) return 0;
	int dem = 0;
	if (T->left || T->right)
		dem++;
	return dem + countInternalNodes2(T->left) + countInternalNodes2(T->right);
}
int countInternalNodes(Tree T) {

	return max(0,countInternalNodes2(T) - 1);
}

int countOneChild(Tree T) {
	if (!T) return 0;
	int dem = 0;
	if ((T->left && !T->right) || (!T->left && T->right))
		dem++;
	return dem + countOneChild(T->left) + countOneChild(T->right);
}

int countTwoChildren(Tree T) {
	if (!T) return 0;
	int dem = 0;
	if (T->left && T->right)
		dem++;
	return dem + countTwoChildren(T->left) + countTwoChildren(T->right);
}

int countLess(Tree T, int x) {
	if (!T) return 0;
	int dem = 0;
	if (T->info < x)
		dem++;
	return dem + countLess(T->left, x) + countLess(T->right, x);
}

int countBetweenValues(Tree T, int x, int y) {
	if (!T) return 0;
	int dem = 0;
	if (T->info > x && T->info<y)
		dem++;
	return dem + countBetweenValues(T->left, x,y) + countBetweenValues(T->right, x,y);
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "Number of nodes: " << countNodes(T) << endl;
	cout << "Number of leaf nodes: " << countLeafs(T) << endl;
	cout << "Number of internal nodes: " << countInternalNodes(T) << endl;
	cout << "Number of nodes with one child: " << countOneChild(T) << endl;

	cout << "Number of nodes with two children: " << countTwoChildren(T) << endl;

	int x;cout << "Enter x: ";cin >> x;
	cout << "\nNumber of nodes less than " << x << ": " << countLess(T, x) << endl;
	int y; cout << "Enter x,y: ";cin >> x >> y;
	cout << "\nNumber of nodes greater than " << x << " and less than " << y << ": " << countBetweenValues(T, x, y) << endl;

	return 0;
}

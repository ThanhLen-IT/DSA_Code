/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -


struct Node {
	int info;
    Node* left, * right;
};

typedef Node* Tree;

Node* getNode(int x) {
	Node* p = new Node;
	p->info = x;
	p->left = p->right = NULL;
	return p;
}

void insertNode(Tree& T, int x) {
	if (!T)
		T = getNode(x);
	if (x == T->info) return;
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
void LNR(Tree T) {
	if (!T)
		return;
	LNR(T->left);
	cout << T->info << " ";
	LNR(T->right);
}

Node* Search(Tree T, int x) {
	if (!T) return NULL;
	if (x == T->info) {
		Node* p = getNode(x);
		return p;
	}
	if (x < T->info)
		return Search(T->left, x);
	else
		return Search(T->right, x);
}


int minValue(Tree T) {
	Node* p = T;
	while (p->left) {
		p = p->left;
	}
	return p->info;
}

int maxValue(Tree T) {
	Node* p = T;
	while (p->right) {
		p = p->right;
	}
	return p->info;
}
int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "LNR: "; LNR(T); cout << endl;


    int x; cout << "\nEnter the element you want to find: ";cin >> x;
    Node* p = Search(T, x);
    if (p) cout << "Found";
    else cout << "Not found";
    cout << "\nminimum value in bts is " << minValue(T);
    cout << "\nminimax value in bts is " << maxValue(T);


    return 0;
}

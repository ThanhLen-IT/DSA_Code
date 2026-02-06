#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int info;
	Node* left;
	Node* right;
};

typedef Node* Tree;

void initTree(Tree& T) {
	T = NULL;
}

Node* getNode(int x) {
	Node* p = new Node;
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

bool searchTree(Tree T, int key, vector<int>& vt) {
	if (!T) return false;

	vt.push_back(T->info);

	if (T->info == key) return true;

	if (key < T->info)
		return searchTree(T->left, key, vt);
	else
		return searchTree(T->right, key, vt);
}



int main() {
	int n;
	cin >> n;
	Tree T;
	initTree(T);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		insertTree(T, x);
	}
	int key; cin >> key;
	vector<int> vt;
	if (searchTree(T, key, vt)) {
		cout << "Found. Path: ";
		for (int x : vt) {
			cout << x << " ";
		}
	}
	else {
		cout << "Not found";
	}
}
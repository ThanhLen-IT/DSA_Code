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
	for (int i = 0; i < n; i ++ ) {
		cin >> x;
		insertNode(T, x);
	}
}

void NLR(Tree T) {
	if (!T)
		return;
	cout << T->info << " ";
	NLR(T->left);
	NLR(T->right);
}

void LRN(Tree T) {
	if (!T)
		return;
	
	LRN(T->left);
	LRN(T->right);
	cout << T->info << " ";
}

void LNR(Tree T) {
	if (!T)
		return;
	LNR(T->left);
	cout << T->info << " ";
	LNR(T->right);
}

void listLeafs(Tree T) {
	if (T) {
		if (!T->left && !T->right)
			cout << T->info << " ";
		listLeafs(T->left);
		listLeafs(T->right);
	}

}

void listInternalNodes(Tree T, int i) {
	if (!T) return;
	if (i != 0 && (T->left || T->right)) {
		cout << T->info << " ";
	}
	listInternalNodes(T->left, 1);
	listInternalNodes(T->right, 1);
}

void  listNodesWithOneChild(Tree T) {
	if (!T) return;
	if ((T->left && !T->right) || (!T->left && T->right)) {
		cout << T->info << " ";
	}
	listNodesWithOneChild(T->left);
	listNodesWithOneChild(T->right);
}

void listNodesWithTwoChildren(Tree T) {
	if (!T) return;
	if (T->left && T->right) {
		cout << T->info << " ";
	}
	listNodesWithTwoChildren(T->left);
	listNodesWithTwoChildren(T->right);
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "\nNLR: "; NLR(T);
	cout << "\nLRN: "; LRN(T);
	cout << "\nLNR: "; LNR(T);

	cout << "\nleaf nodes: "; listLeafs(T);
	cout << "\nInternal nodes: "; listInternalNodes(T, 0); //co de san tham so thu 2 cho ai co nhu cau dung, SV khong dung tham so thu 2 nay cung khong sao
	cout << "\nNodes with one child: "; listNodesWithOneChild(T);
	cout << "\nNodes with two children: "; listNodesWithTwoChildren(T);

	return 0;
}

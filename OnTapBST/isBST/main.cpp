/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>

using namespace std;

struct TNode {
    int key;
    TNode * left, * right;
};

typedef TNode * TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}


bool isBST(TREE);

int main() {
    vector<int> nlr, lnr;
    int n, key;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> key;
        nlr.push_back(key);
    }

    for (int i = 0; i < n; i++) {
        cin >> key;
        lnr.push_back(key);
    }
    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);
    if (isBST(r))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

//###INSERT CODE HERE -


void LNR(TREE T, vector<int>& v) {
    if (!T) return;
    LNR(T->left, v);
    v.push_back(T->key);
    LNR(T->right, v);
}

bool isBST(TREE T) {
    vector<int> v;
    LNR(T, v);

    for (int i = 1; i < v.size(); i++) {
        if (v[i] <= v[i - 1])
            return false;
    }
    return true;
}



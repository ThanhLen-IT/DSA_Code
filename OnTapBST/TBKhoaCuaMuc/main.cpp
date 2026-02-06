/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>
#include <iomanip>

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


double AverageByLevel(TREE, int);

int main() {
    vector<int> nlr, lnr;
    int n, key, m, lvl;

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

    cin >> m;

    cout << setprecision(2) << fixed;

    for (int i = 0; i < m; i++) {
        cin >> lvl;
        cout << AverageByLevel(r, lvl) << endl;
    }

    return 0;
}


//###INSERT CODE HERE -
double AverageByLevel(TREE T, int level){
    if (!T) return 0;

    vector<TREE> p;
    p.push_back(T);

    int curLevel = 0;

    while (!p.empty()) {
        int tmp = p.size();
        long long sum = 0;

        for (int i = 0; i < tmp; i++) {
            TNode* cur = p.front();
            p.erase(p.begin());

            if (curLevel == level) {
                sum += cur->key;
            }
            if (cur->left)  p.push_back(cur->left);
            if (cur->right) p.push_back(cur->right);
        }

        if (curLevel == level) {
            return (double)sum / tmp;
        }

        curLevel++;
    }

    return 0;
}

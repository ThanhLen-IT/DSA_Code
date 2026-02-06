/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>
#include <map>



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

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}


int MaxLevel(TREE);

int main() {
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    Input(nlr);
    Input(lnr);


    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);

    cout << MaxLevel(r) << endl;

    return 0;
}


//###INSERT CODE HERE -


int MaxLevel(TREE root) {
    if (!root) return -1;

    vector<TNode*> p;
    p.push_back(root);

    int level = 0;
    int bestLevel = 0;
    long long bestSum = root->key;

    while (!p.empty()) {
        long long sum = 0;
        int tmp = p.size();

        for (int i = 0; i < tmp; i++) {
            TNode* cur = p.front();
            p.erase(p.begin());

            sum += cur->key;
            if (cur->left)  p.push_back(cur->left);
            if (cur->right) p.push_back(cur->right);
        }

        if (sum > bestSum) {
            bestSum = sum;
            bestLevel = level;
        }
        level++;
    }

    return bestLevel;
}


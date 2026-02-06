/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct TNode {
    int key;
    TNode *left, *right;
};

typedef TNode * TREE;

void CreateTree(TREE &t) {
    t = NULL;
}

TNode * CreateTNode(int x) {
    TNode * p = new TNode;
    if (p == NULL) return NULL;
    p->left = p->right = NULL;
    p->key = x;
    return p;
}

void InsertNode(TREE &t, int x) {
    TNode *p = CreateTNode(x);

    if (t == NULL) {
        t = p;
        return;
    }
    TREE q = t;
    while (q != NULL) {
        if (x == q->key) return;
        if (x > q->key) {
            if (q->right == NULL) {
                q->right = p;
                return;
            }
            q = q->right;
        }
        else {
            if (q->left == NULL) {
                q->left = p;
                return;
            }
            q = q->left;
        }
    }
}

void LoadTree(TREE &t) {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        InsertNode(t, k);
    }
}

void MaxFindingCost(TREE);

int main()
{
    vector<int> keys;
    TREE t;
    CreateTree(t);
    LoadTree(t);
    MaxFindingCost(t);
    return 0;
}


//###INSERT CODE HERE -

int heightTree(TREE T){
	if (!T) return 0;

	int hLeft = heightTree(T->left);
	int hRight= heightTree(T->right);

	return 1 + (hLeft > hRight? hLeft : hRight);
}

void MaxFindingCost(TREE T){
	int maxLevel = heightTree(T)-1;

	vector<TREE> p;
	int curLevel=0;
	p.push_back(T);

	while(!p.empty()){
		int sizeLevel = p.size();

		for (int i=0; i< sizeLevel; i++){
			TREE cur = p.front();
			p.erase(p.begin());

			if (curLevel==maxLevel){
				cout<<cur->key<<" ";
			}
			if (cur->left) p.push_back(cur->left);
			if (cur->right) p.push_back(cur->right);
		}
		if (curLevel == maxLevel) return;

		curLevel++;
	}
	return;

}

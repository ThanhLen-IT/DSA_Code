/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using namespace std;

struct TNode{
    int key;
    TNode* pLeft;
    TNode* pRight;
};

struct Tree{
    TNode* root;
};

void CreateTree(Tree &T)
{
    T.root = NULL;
}

TNode* CreateTNode(int x) {
    TNode* p;
    p = new TNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(Tree &, int);
bool isBrother(Tree, int, int);
void run(int q, Tree T);

//###INSERT CODE HERE -
void Insert2(TNode *&T, int x){
	if (!T){
		T=CreateTNode(x);
		return;
	}

	if (x<T->key){
		Insert2(T->pLeft,x);
	}else{
		Insert2(T->pRight,x);
	}
}

void Insert(Tree &T, int x){
	Insert2(T.root,x);
}


bool isBrother(Tree T , int a, int b){
	TNode* p=T.root;
	TNode* prev=NULL;
	while (p){
		if (a == p->key){
			if (prev->pLeft && prev->pLeft->key==b ){
				return true;
			}else if (prev->pRight && prev->pRight->key==b ){
				return true;
			}
			return false;
		}
		prev =p;
		if (a < p->key){
			p=p->pLeft;
		}else{
			p=p->pRight;
		}
	}
	return false;
}
void run(int q, Tree T){
	int x, y;
    while (q > 0) {
        cin >> x >> y;
        if (isBrother(T, x, y)) {
            cout << x << " va " << y <<" la anh em"<< endl;
        } else if (isBrother(T, y, x)) {
            cout << x << " va " << y <<" la anh em" << endl;
        } else {
            cout << x << " va " << y << " khong phai la anh em" << endl;
        }
        q--;
    }
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree T;
    CreateTree(T);
    int n; cin >> n;
    int data;
    while(n != 0) {
        cin >> data;
        Insert(T, data);
        n--;
    }
    int q; cin >> q;
    run(q, T);

    return 0;
}

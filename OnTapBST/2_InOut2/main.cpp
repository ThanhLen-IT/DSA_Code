/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
LRN
###End banned keyword*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct node
{
    int info;
    node *left, *right;
};
typedef node* Tree;
node* getNode(int x)
{
    node* p =new node;
    p->info=x;
    p->left=p->right=NULL;
    return p;
}
void insertTree(Tree &T, int x)
{
    if(!T) T=getNode(x);
    else
    {
        if(T->info==x) return;
        if(x<T->info) insertTree(T->left,x);
        else insertTree(T->right, x);
    }

}
void inputTree(Tree &T)
{
    int n,x; cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insertTree(T, x);
    }
}
void LRN(Tree T)
{

//###INSERT CODE HERE -
	stack<Tree> S1;
	stack<Tree> S2;
	Tree p=T;

	S1.push(p);
	while (!S1.empty()){
		p = S1.top();
		S1.pop();
		S2.push(p);

		if (p->left){
			S1.push(p->left);
		}

		if (p->right){
			S1.push(p->right);
		}
	}

	while(!S2.empty()){
		cout<<S2.top()->info<<" ";
		S2.pop();
	}


}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nLRN: "; LRN(T);
	return 0;
}

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/
#include <iostream>

using namespace std;



//###INSERT CODE HERE -
struct Node{
	int info;
	Node* next;
};

struct List{
	Node* head;
	Node* tail;
};

void initList(List& L){
	L.head=L.tail=nullptr;
}

Node* getNode(int x){
	Node* p= new Node;
	p->info=x;
	p->next=nullptr;
	return p;
}
void AddHead(List& L, int x){
	if (!L.head){
		L.head=L.tail=getNode(x);
		return;
	}

	Node* p= getNode(x);
	p->next =L.head;
	L.head=p;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin>>n;
	List L;
	initList(L);
	int dem=0;
	for (int i=0; i<n && dem <10; i++){
		int x; cin>>x;
		if (x>=90) {
			AddHead(L,x);
			dem++;
		}
	}
	Node*p= L.head;
	while(p){
		cout<<p->info<<" ";
		p=p->next;
	}
	cout<<"END";
}

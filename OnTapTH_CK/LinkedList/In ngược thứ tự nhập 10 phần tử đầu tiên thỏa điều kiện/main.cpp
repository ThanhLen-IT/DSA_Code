/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/
#include <iostream>

using namespace std;

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
	L.tail=p;
}

//###INSERT CODE HERE -

int main(){
	int n; cin>>n;
	List L;
	initList(L);
	for (int i=0; i<n; i++){
		int x; cin>>x;
		AddHead(L,x);
	}
	int dem=0;
	Node* p=L.head;
	while(dem<=10 && p){
		if(p->info>=90){
			cout <<p->info<<" ";
		}
	}
	cout<<"END";
}

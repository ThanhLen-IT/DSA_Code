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
	Node* head, *tail;
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

void addTail(List& L, int x){
	if (!L.head) {
		L.head=L.tail=getNode(x);
		return;
	}

	Node* p=getNode(x);
	L.tail->next=p;
	L.tail=p;
}

void inputList(List& L, int n, int& dem){
	for (int i=0; i<n; i++){
		int x;
		cin>>x;
		if (x%2==0) {
			addTail(L,x);
			dem++;
		}
	}
}

void printResult(List L, int n){
	Node* p=L.head;
	int i=0;
	while (p){
		if (i==n/2) break;
		i++;
		p=p->next;
	}
	cout<<p->info;
}


int main(){
	int n; cin>>n;
	int dem=-1;
	List L;
	initList(L);
	inputList(L,n, dem);
	Node* p= L.head;
	printResult(L,dem);
}

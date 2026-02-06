/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -

struct node {
	int info;
	node* next;
};

struct List {
	node* head;
	node* tail;
};

void initList(List& L) {
	L.head = L.tail = NULL;
}

node* getNode(int x) {
	node* p = new node;
	p->info = x;
	p->next = NULL;
	return p; 
}


void printList(List L) {
	if (!L.head) cout << "blank";
	node* p = L.head;
	while (p) {
		cout << p->info << " ";
		p = p->next;
	}
}

void addHead(List& L, int x) {
	node* p = getNode(x);
	if (!L.head) {
		L.head = L.tail = p;
	}
	else {
		p->next = L.head;
		L.head = p;
	}

}

void addTail(List& L, int x) {
	node* p = getNode(x);
	if (!L.head) {
		L.head = L.tail = p;
	}
	else {
		L.tail->next = p;
		L.tail = p;
	}
}

void addAfter(List& L, int a, int b) {
	node* k = L.head;
	while (k) {
		if (k->info == a) break;
		k = k->next;
	}

	if (!k) {
		addHead(L, b);
	}
	else {
		node* p = getNode(b);
		p->next = k->next;
		k->next = p;

		if (k == L.tail) {
			L.tail = p;
		}
	}
}

void delFistEle(List& L, int x) {
	if (!L.head) return;
	node* p = L.head;
	node* prev = NULL;
	while (p) {
		if (p->info == x) break;
		prev = p;
		p = p->next;
	}

	if (p) {
		if (p == L.head) {
			L.head = L.head->next;
			if (!L.head) L.tail = NULL;
			delete p;
		}
		else
		{
			prev->next = p->next;
			if (p == L.tail) L.tail = prev;
			delete p;
		}
	}
}

void delAllEle(List& L, int x) {
	if (!L.head) return;
	node* p = L.head;
	node* prev = NULL;

	while (p) {
		if (p->info == x) {
			node* tmp = p;          
			if (p == L.head) {
				L.head = L.head->next;
				if (!L.head) L.tail = NULL;
				p = L.head;          
			}
			else {
				prev->next = p->next;
				if (p == L.tail) L.tail = prev;
				p = p->next;         
			}
			delete tmp;
		}
		else {
			prev = p;
			p = p->next;
		}
	}
}


void delHead(List& L) {
	if (!L.head) return;
	
	node* p = L.head;
	L.head = L.head->next;
	delete p;

	if (!L.head) L.tail = NULL;
}


int main() {
	List L;
	initList(L);
	int type; 

	while (cin >> type) {
		if (type == 6) break; 

		if (type == 0) {           
			int x; cin >> x;
			addHead(L, x);
		}
		else if (type == 1) {     
			int x; cin >> x;
			addTail(L, x);
		}
		else if (type == 2) {       
			int a, b; cin >> a >> b;
			addAfter(L, a, b);
		}
		else if (type == 3) {      
			int n; cin >> n;
			delFistEle(L, n);
		}
		else if (type == 4) {       
			int n; cin >> n;
			delAllEle(L, n);
		}
		else if (type == 5) {      
			delHead(L);
		}
	}
   
	printList(L);
	return 0;
}

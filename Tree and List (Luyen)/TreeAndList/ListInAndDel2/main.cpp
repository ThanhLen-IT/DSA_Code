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

void delTail(List& L) {
	if (!L.head) return;

	if (!L.head->next) {
		delete L.head;
		L.head = L.tail = NULL; 
		return;
	}

	node* p = L.head;
	while (p->next->next) {
		p = p->next;
	}

	delete p->next;
	p->next = NULL;
	L.tail = p; 
}


void delHead(List& L) {
	if (!L.head) return;

	node* p = L.head;
	L.head = L.head->next;
	delete p;

	if (!L.head) L.tail = NULL;
}

void printList(List L) {
	node* p = L.head;
	while (p) {
		cout << p->info << " ";
		p = p->next;
	}
}


int main() {
	

	int n;
	cin >> n;
	List L;
	initList(L);

	char x, y;
	int z;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		if (x == '+') {
			if (y == 'H') addHead(L, z);
			else if (y == 'T') addTail(L, z);
		}
		else if (x == '-') {
			if (y == 'H') delHead(L);
			else if (y == 'T') delTail(L);
		}
	}

	printList(L);
	return 0;
}
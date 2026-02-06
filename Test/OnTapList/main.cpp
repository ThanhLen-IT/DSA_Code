#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* next;
};

struct List {
	Node* head;
	Node* tail;
};

void initList(List& L) {
	L.head = L.tail = NULL;
}

Node* getNode(int x) {
	Node* p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}

//Them vao duoi
void addTail(List& L, int x) {
	Node* p = getNode(x);
	if (!L.head) {
		L.head = L.tail = p;
		return;
	}

	L.tail->next = p;
	L.tail = p;
}

//Them vao dau
void addHead(List& L, int x) {
	Node* p = getNode(x);
	if (!L.head) {
		L.head = L.tail = p;
		return;
	}

	p->next = L.head;
	L.head = p;
}

//Duyet List
void printList(List L) {
	Node* p = L.head;
	while (p) {
		cout << p->info << " ";
		p = p->next;
	}
}

//Chen 1 phan tu sau k
void InsertAfter(List& L, int key, int x) {
	//Tim k
	Node* k = L.head;
	while (k) {
		if (k->info == key) break;
		k = k->next;
	}

	//Chen k
	if (!k) {
		//Xu ly khi khong tim thay k
		addHead(L, x);
	}
	else
	{
		Node* p = getNode(x);
		p->next = k->next;
		k->next = p;

		if (k == L.tail) {
			L.tail = p;
		}
	}
}

//Xoa 1 phan tu co gia tri x
void deleteEle(List& L, int x) {
	Node* key = L.head;
	Node* preKey = NULL;
	while (key) {
		if (key->info == x) break;
		preKey = key;
		key = key->next;
	}

	if (!key) {
		//Xu li khi khong tim thay x
	}
	else
	{
		if (key == L.head) {
			L.head = key->next;
			if (L.head == NULL) L.tail = NULL;
			delete key;
		}
		else
		{
			preKey->next = key->next;
			if (key == L.tail) L.tail = preKey;
			delete key;
		}
		
	}
}

void deleteAllEle(List& L, int x) {
	Node* key = L.head;
	Node* preKey = NULL;
	while (key) {
		if (key->info == x) {
			Node* tmp = key;
			if (key == L.head) {
				L.head = key->next;
				if (L.head == NULL) L.tail = NULL;
				key = L.head;
			}
			else
			{
				preKey->next = key->next;
				if (key == L.tail) L.tail = preKey;
				key = preKey->next;
			}
			delete tmp;
			continue;
		}
		preKey = key;
		key = key->next;
	}
}

void deleteHead(List& L) {
	if (L.head) {
		Node* key = L.head;
		L.head = key->next;
		if (L.head == NULL) L.tail = NULL;
		delete key;
	}
}




int main() {

	List L;
	initList(L);
	int x, y, z;
	while (true) {
		cin >> x;

		if (x == 6) break;  // stop

		if (x == 5) {       // delete head, no y needed
			deleteHead(L);
			continue;
		}

		cin >> y;           // only read y for commands that NEED y

		switch (x)
		{
		case 0: addHead(L, y); break;
		case 1: addTail(L, y); break;
		case 2:
			cin >> z;
			InsertAfter(L, y, z);
			break;
		case 3: deleteEle(L, y); break;
		case 4: deleteAllEle(L, y); break;
		default: break;
		}
	}

	printList(L);
	return 0;
}
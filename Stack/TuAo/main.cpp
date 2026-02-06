/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multi_set
map
unordered_map
include
[
]
###End banned keyword*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//###INSERT CODE HERE -



struct Ao {
	string name;
	int size;
	Ao(string n, int s) {
		name = n;
		size = s;
	}
};
struct node
{
	Ao info;
	node* next;
	node(Ao x) : info(x), next(NULL) {}
};
struct Stack
{
	node* pHead;
};

void Init(Stack& S) {
	S.pHead = NULL;
}

node* getNode(Ao x) {
	node* p = new node(x);
	return p;
}

bool isEmty(Stack S) {
	return S.pHead == NULL;
}

void Push(Stack& S, Ao x) {
	node* p = getNode(x);
	if (!S.pHead) {
		S.pHead = p;
		return;
	}
	p->next = S.pHead;
	S.pHead = p;
}

void Pop(Stack& S) {
	if (isEmty(S)) return;
	node* p = S.pHead;
	S.pHead = p->next;
	delete p;
}

void findTop(Stack& S) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Pop(S);
	}
	cout << S.pHead->info.name << " " << S.pHead->info.size;
}

int main() {
	Stack S;
	Init(S);

	while (true) {
		string name;
		int size;
		cin >> name;
		if (name == "-1") break;
		cin >> size;
		Ao a(name, size);
		Push(S, a);
	}

	findTop(S);
	return 0;
}
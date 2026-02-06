/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <stack>

#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int num;
    Node * next;
};

struct List {
    Node * head, * tail;
};

Node * CreateNode(int x) {
    Node * p = new Node;
    if (p == NULL) exit(1);
    p->num = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node * RemoveHead(List &l) {
    if (l.head == NULL)
        return NULL;
    Node * p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l) {
    Node *p = l.head;
    while (p != NULL) {
        cout << p->num << ' ';
        p = p->next;
    }
}
void Sum(List, List, List &);

int main()
{
    List a, b, c;
    CreateList(a);
    CreateList(b);
    CreateList(c);
    int m, n, k;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        AddTail(a, k);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        AddTail(b, k);
    }

    Sum(a, b, c);
    PrintList(c);
    return 0;
}

void printStack(stack<int>a){
	while(!a.empty()){
		cout<<a.top()<<" ";
		a.pop();
	}
}

void Sum(List a, List b, List &c) {

//###INSERT CODE HERE -

	stack<int> sa;
	stack<int> sb;

	Node* p= a.head;
	while(p){
		sa.push(p->num);
		p=p->next;
	}
	Node* q= b.head;
	while(q){
		sb.push(q->num);
		q=q->next;
	}


	int carry=0;
	while (!sa.empty()||!sb.empty()||carry>0){
		int x = (!sa.empty()) ? sa.top() : 0;
		int y = (!sb.empty()) ? sb.top() : 0;

		if (!sa.empty()) sa.pop();
		if (!sb.empty()) sb.pop();

		int sum = x + y + carry;
		AddHead(c,sum%10);
		carry = sum /10;
	}

}

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;


//###INSERT CODE HERE -

struct node
{
	char info;
	node* next;
};
struct Stack
{
	node* pHead;
};

void Init(Stack& S) {
	S.pHead = NULL;
}

node* getNode(char x) {
	node* p = new node;
	p->info = x;
	p->next = NULL;
	return p;
}

bool isEmty(Stack S) {
	return S.pHead == NULL;
}

void Push(Stack& S, char x) {
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

bool isValid(string expr) {
	Stack S1,S2,S3;
	Init(S1);
	Init(S2);
	Init(S3);
	for (int i = 0; i < expr.length(); i++) {
		if (expr[i] == '(') Push(S1, '(');
		else if (expr[i] == ')') {
			if (isEmty(S1)) return 0;
			Pop(S1);
		}
		if (expr[i] == '{') Push(S2, '{');
		else if (expr[i] == '}') {
			if (isEmty(S2)) return 0;
			Pop(S2);
		}
		if (expr[i] == '[') Push(S3, '[');
		else if (expr[i] == ']') {
			if (isEmty(S3)) return 0;
			Pop(S3);
		}
	}
	return (isEmty(S1)&&isEmty(S2)&&isEmty(S3)) ? 1 : 0;

}

int main()
{
	string expr; cin >> expr;
	cout << isValid(expr);

	return 0;
}




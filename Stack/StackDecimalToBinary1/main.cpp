/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

#define MAX 2000

/*Cach 1: Khi da cai dat List roi, dinh nghia Stack dua tren List
struct Stack
{
    List L;
};

Cach 2: Cai dat lai Stack tu dau, giong nhu List
struct node
{
    int info;
    node *next;
};
struct Stack
{
    node *pHead; // pTail khong co cung duoc

};*/

//###INSERT CODE HERE -

struct Stack
{
    int arr[MAX];
    int t; 
};
void Init(Stack& S)
{
    S.t = -1; 
}


bool isFull(Stack S) {
    return S.t - 1 == MAX;
}

void Push(Stack& S, int x) {
    if (isFull(S))  return;
    S.t++;
    S.arr[S.t] = x;
}

bool isEmpty(Stack S) {
    return S.t == -1;
}
void printStack(Stack S) {
    if (isEmpty(S)) cout << "Stack is empty";
    for (int i = 0; i <= S.t; i++) {
        cout << S.arr[i] << " ";
    }
}

void DecimaltoBinary1(int n, Stack& S) {
	if (n == 0) Push(S, 0);
	while (n > 0) {
		int r = n % 2;
		Push(S, r);
		n = n / 2;
	}
}

int main()
{
    Stack S;Init(S);
    int n, x;
    cin >> n;
    DecimaltoBinary1(n, S);
    printStack(S);
    return 0;
}


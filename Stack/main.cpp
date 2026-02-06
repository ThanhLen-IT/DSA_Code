/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

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


struct node
{
    int info;
    node* next;
};

struct Stack {
    node* pHead;
};

void Init(Stack& S) {
    p
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


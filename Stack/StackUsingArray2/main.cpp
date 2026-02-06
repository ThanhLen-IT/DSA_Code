/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int t; // t là ch? s? c?a ph?n t? cu?i m?ng, t?c là ??nh stack
};
void Init(Stack& S)
{
    S.t = -1; //Khi stack ch?a có ph?n t? nào thì top ???c kh?i t?o là -1,
    // n?u kh?i t?o t = 0 là SAI vì khi ?ó s? hi?u top t?i a[0]
}
//###INSERT CODE HERE -

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

int Top(Stack S) {
    if (isEmpty(S)) return NULLDATA;
    return S.arr[S.t];
}

void Pop(Stack& S) {
    if (isEmpty(S)) return;
    S.arr[S.t] == NULLDATA;
    S.t--;
}
int main()
{
    Stack S;Init(S);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        Push(S, x);

    }
    cout << "Stack:";
    printStack(S);
    cout << "\nTop:" << Top(S);
    Pop(S);
    cout << "\nUpdated Stack:";
    printStack(S);
    cout << "\nTop:" << Top(S);
    return 0;
}





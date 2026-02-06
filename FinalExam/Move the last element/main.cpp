/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -

struct Node {
    int info;
    Node* next;
    Node* prevTail;
};

struct List {
    Node* pHead;
    Node* pTail;
};

Node* getNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    p->prevTail = NULL;
    return p;
}

void addTail(List& L, int x) {
    if (!L.pHead) {
        L.pHead = L.pTail = getNode(x);
        return;
    }
    Node* p = getNode(x);
    p->prevTail = L.pTail;
    L.pTail->next = p;
    L.pTail = p;
}

void inputList(List& L, int n) {

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        addTail(L, x);
    }
}

void outputList(List L) {
    if (!L.pHead) {
        cout << "List is empty";
        return;
    }
    Node* p = L.pHead;
    while (p) {
        cout << p->info << " ";
        p = p->next;
    }
}


void moveLastToFront(List& L) {
    if (!L.pHead || !L.pHead->next) return;

    Node* oldTail = L.pTail;
    Node* newTail = oldTail->prevTail;

    // Nối tail cũ lên trước head
    oldTail->next = L.pHead;
    L.pHead->prevTail = oldTail;

    // Cắt đuôi
    newTail->next = NULL;

    oldTail->prevTail = NULL;
    L.pHead = oldTail;
    L.pTail = newTail;
}
int main()
{
    List L;
    L.pHead = L.pTail = NULL;
    int n; cin >> n;
    inputList(L, n);
    cout << "Created List: " << endl;
    outputList(L);
    cout << endl;

    moveLastToFront(L); //di chuyen node cuoi ve dau danh sach
    cout << "Updated List after moving the last element to front of L: " << endl;
    outputList(L);
    return 0;
}

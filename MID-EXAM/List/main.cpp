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
struct node {
    int info;
    node* next;
};

struct List {
    int n;
    node* head;
    node* tail;
};

void Init(List& L) {
    L.head = 0;
    L.tail = 0;
    L.n = 0;
}

node* getNode(int x) {
    node* p = new node;
    p->info = x;
    p->next = 0;
    return p;
}

void addTail(List& L, int x) {
    node* p = getNode(x);
    L.n++;
    if (!L.head) {
        L.head = L.tail = p;
        return;
    }
    L.tail->next = p;
    L.tail = p;
}

void addHead(List& L, int x) {
    node* p = getNode(x);
    if (!L.head) {
        L.head = L.tail = p;
        return;
    }
    p->next = L.head;
    L.head = p;
}

void inputList(List& L, int n) {
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        addTail(L, x);
    }
}

void outputList(List& L) {
    if (!L.head) {
        cout << "List is empty";
        return;
    }
    node* p = L.head;
    while (p) {
        cout << p->info;
        p = p->next;
    }
}

node* findElementFromEnd(List L, int id) {
    if (!L.head) {
        cout << "List is empty";
        return 0;
    }
    node* p = L.head;
    int steps = L.n - id;
    for (int i = 0; i < steps; i++) {
        p = p->next;
    }
    cout << "The index is invalid";
    return p;
}

int main()
{
    List L;
    Init(L);
    int n; cout << "Enter a number: "; cin >> n;
    cout << "\nEnter a sequence of " << n << " numbers: ";
    inputList(L, n);
    cout << "\nThe created Linked List: ";
    outputList(L);

    int i; cout << "\nEnter a number: "; cin >> i;
    cout << "\nThe element at index " << i << " (from the end of L): ";
    node* p = findElementFromEnd(L, i);
    if (p) cout << p->info;


    return 0;
}

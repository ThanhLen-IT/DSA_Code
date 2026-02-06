/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

//###INSERT CODE HERE -

struct Node {
    int info;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

struct Hash {
    int m;
    List* pList;
};

void initHash(Hash& H) {

    H.pList = new List[H.m];
    for (int i = 0; i < H.m; i++) {
        H.pList[i].head = NULL;
        H.pList[i].tail = NULL;
    }
}

Node* getNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

void insertList(List& L, int x) {
    if (!L.head) {
        L.head = L.tail = getNode(x);
        return;
    }
    Node* q = getNode(x);
    if (q->info < L.head->info) {
        q->next = L.head;
        L.head = q;
    }
    else {
        Node* p = L.head->next;
        Node* prev = L.head;
        while (p) {
            if (q->info < p->info) break;
            prev = p;
            p = p->next;
        }
        prev->next = q;
        q->next = p;
        if (!p) {
            L.tail = q;
        }
    }
}

void printList(List L) {
    Node* p = L.head;
    while (p) {
        cout << p->info << " ";
        p = p->next;
    }
}

void traverseAllHash(Hash H) {
    for (int i = 0; i < H.m; i++) {
        cout << "Bucket " << i << ": ";
        printList(H.pList[i]);
        cout << endl;
    }
}

void insertHash(Hash& H, int key) {

    int hash = key % H.m;
    insertList(H.pList[hash], key);
}

int main()
{
    Hash H;
    cin >> H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n, x;cin >> n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i <= n;i++)
    {
        cin >> x;
        insertHash(H, x); // them 1 gia tri du lieu vao bang bam
    }
    cout << "Created Hash:" << endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    return 0;
}


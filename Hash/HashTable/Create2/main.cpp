/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include<iostream>
using namespace std;

struct node {
    int info;
    node* next;
};

struct List {
    node* head, * tail;
};

struct Hash {
    int m;
    int n;
    float load;
    List* pL; // con trỏ quản lý mảng List
};

//###INSERT CODE HERE -

void initList(List& L) {
    L.head = L.tail = NULL;
}

void initHash(Hash& H) {
    H.n = 0;
    H.pL = new List[H.m];
    for (int i = 0; i < H.m; i++) {
        initList(H.pL[i]);
    }
}

bool canInput(Hash H) {
    return ((H.n + 1.0) / H.m <= H.load);
}

int hashFunction(Hash H, int key) {
    return key % H.m;
}

node* getNode(int x) {
    node* p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

void addTail(List& L, int x) {
    node* p = getNode(x);
    if (!L.head)
        L.head = L.tail = p;
    else {
        L.tail->next = p;
        L.tail = p;
    }
}

void inputHash(Hash& H, int n) {
    initHash(H);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;                  // đọc trước giá trị
        if (canInput(H)) {         // kiểm tra load factor
            int idx = hashFunction(H, x);
            addTail(H.pL[idx], x);
            H.n++;
        }
    }
}

void printList(List L) {
    node* p = L.head;
    while (p) {
        cout << p->info << " ";
        p = p->next;
    }
}

void printHash(Hash H) {
    for (int i = 0; i < H.m; i++) {
        cout << "List " << i << ": ";
        printList(H.pL[i]);
        cout << endl;
    }
}

void searchHash(Hash H, int key) {
    int idx = hashFunction(H, key);
    node* p = H.pL[idx].head;
    int pos = 1;
    while (p) {
        if (p->info == key) {
            cout << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    }
    cout << "KHONG" << endl;
}

int main() {
    Hash H;  cin >> H.m >> H.load;
    int n; cin >> n;
    inputHash(H, n);
    printHash(H);
    int nkey, key; cin >> nkey;

    for (int i = 0; i < nkey; i++) {
        cin >> key;
        searchHash(H, key);
    }
    return 0;
}

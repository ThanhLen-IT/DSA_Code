/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using namespace std;

struct TNode{
    int key;
    TNode* pLeft;
    TNode* pRight;
};

struct Tree{
    TNode* root;
};

void CreateTree(Tree &T)
{
    T.root = NULL;
}

TNode* CreateTNode(int x) {
    TNode* p;
    p = new TNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(Tree &, int);
bool isFather(Tree, int, int);
void run(int q, Tree T);

//###INSERT CODE HERE -
void Insert(Tree &T, int x) {
    if (T.root == NULL) {
        T.root = CreateTNode(x);
        return;
    }
    TNode* curr = T.root;
    TNode* prev = NULL;
    while (curr != NULL) {
        prev = curr;
        if (x < curr->key)
            curr = curr->pLeft;
        else if (x > curr->key)
            curr = curr->pRight;
        else
            return; // Khóa đã tồn tại, không chèn
    }
    if (x < prev->key)
        prev->pLeft = CreateTNode(x);
    else
        prev->pRight = CreateTNode(x);
}

bool isFather(Tree T, int parentVal, int childVal) {
    // Tìm nút có giá trị parentVal
    TNode* curr = T.root;
    while (curr != NULL && curr->key != parentVal) {
        if (parentVal < curr->key)
            curr = curr->pLeft;
        else
            curr = curr->pRight;
    }

    // Nếu không tìm thấy cha hoặc cha không có con
    if (curr == NULL) return false;

    // Kiểm tra con trái hoặc con phải trực tiếp
    if (curr->pLeft != NULL && curr->pLeft->key == childVal) return true;
    if (curr->pRight != NULL && curr->pRight->key == childVal) return true;

    return false;
}

void run(int q, Tree T) {
    int x, y;
    while (q > 0) {
        cin >> x >> y;
        if (isFather(T, x, y)) {
            cout << x << " la cha cua " << y << endl;
        } else if (isFather(T, y, x)) {
            cout << y << " la cha cua " << x << endl;
        } else {
            cout << x << " va " << y << " khong co quan he cha con" << endl;
        }
        q--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree T;
    CreateTree(T);
    int n; cin >> n;
    int data;
    while(n != 0) {
        cin >> data;
        Insert(T, data);
        n--;
    }
    int q; cin >> q;
    run(q, T);

    return 0;
}

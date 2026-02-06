/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct node {
    int info;
    node* left;
    node* right;
};
typedef node* Tree;

void initTree(Tree& T) {
    T = NULL;
}

Tree getNode(int x) {
    node* p = new node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertTree(Tree& T, int x) {
    if (!T) {
        T = getNode(x);
        return;
    }

    if (x < T->info)
        insertTree(T->left, x);
    else if (x > T->info)
        insertTree(T->right, x);
}

bool isLeaf(Tree T) {
    return T && !T->left && !T->right;
}

int heightTree(Tree T) {
    if (!T) return 0;
    int hLeft = heightTree(T->left);
    int hRight = heightTree(T->right);
    return 1 + (hLeft > hRight ? hLeft : hRight);
}

bool isIdealTree(Tree T) {
    if (!T) return true; // cây rỗng vẫn là cây lý tưởng

    // kiểm tra chiều cao 2 nhánh con
    if (heightTree(T->left) != heightTree(T->right))
        return false;

    // nếu không phải lá, phải có đủ 2 con
    if (!isLeaf(T)) {
        if (!T->left || !T->right)
            return false;
    }

    // kiểm tra đệ quy 2 cây con
    bool leftOk = isIdealTree(T->left);
    bool rightOk = isIdealTree(T->right);

    return leftOk && rightOk;
}

int main() {
    Tree T;
    initTree(T);

    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertTree(T, x);
    }

    if (isIdealTree(T))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

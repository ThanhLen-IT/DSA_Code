/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/
#include <iostream>

using namespace std;

struct Hocsinh {
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh& x) {
    getline(cin >> ws, x.Hodem);
    getline(cin >> ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
        << ' ' << hs.Ten
        << '\t' << hs.Gioitinh
        << '\t' << hs.Ngay
        << '/' << hs.Thang
        << '/' << hs.Nam
        << '\t' << hs.Toan
        << '\t' << hs.Van
        << '\t' << hs.Ly
        << '\t' << hs.Hoa
        << '\t' << hs.Anh
        << '\t' << hs.Sinh << endl;
}

struct TNode {
    Hocsinh data;
    TNode* left, * right;
};

typedef TNode* TREE;

void CreateTree(TREE& r) {
    r = NULL;
}

TNode* CreateTNode(Hocsinh x) {
    TNode* p = new TNode;
    if (p == NULL) exit(1);
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}


//###INSERT CODE HERE -

void InsertNode(TREE& T, Hocsinh x) {
    if (T == NULL) {
        T = CreateTNode(x);
        return;
    }
    if (x.Ten < T->data.Ten)
        InsertNode(T->left, x);
    else if (x.Ten > T->data.Ten)
        InsertNode(T->right, x);
    else {//Trung ten
        if (x.Hodem < T->data.Hodem)
            InsertNode(T->left, x);
        else if (x.Hodem > T->data.Hodem)
            InsertNode(T->right, x);
        else
            return; //Trung ten + hodem
    }
}

void InputTree(TREE& T) {
    int n;
    cin >> n;
    Hocsinh hs;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        InsertNode(T, hs);
    }
}

void LNR(TREE T) {
    if (T == NULL) return;
    LNR(T->left);
    OutputElement(T->data);
    LNR(T->right);
}

int main() {
    TREE T;
    CreateTree(T);
    InputTree(T);
    LNR(T);
    return 0;
}

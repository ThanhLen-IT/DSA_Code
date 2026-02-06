/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

typedef struct Product
{
    int id;
    string name;
    string type;
    int year;
    int warranty;
} PRO;

struct Node
{
    PRO info;
    Node* pLeft;
    Node* pRight;
};
typedef struct Node* Tree;

void printProduct(PRO x)
{
    cout << x.id << "\t" << x.name << "\t" << x.type << "\t" << x.year << "\t" << x.warranty << endl;

}


//###INSERT CODE HERE -
Tree getNode(PRO x) {
    Tree p = new Node;
    p->info.id = x.id;
    p->info.name = x.name;
    p->info.type = x.type;
    p->info.year = x.year;
    p->info.warranty = x.warranty;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void insertTree(Tree& T, PRO x) {
    if (!T) {
        T = getNode(x);
        return;
    }
    if (x.id < T->info.id) insertTree(T->pLeft,x);
    if (x.id > T->info.id) insertTree(T->pRight, x);
}

void inputTree(Tree& T) {
    int n;
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; i++) {
        Product p;
        cin >> p.id;
        cin.ignore(); 
        getline(cin, p.name);
        getline(cin, p.type);
        cin >> p.year;
        cin >> p.warranty;
        insertTree(T, p);
        cin.ignore();
    }
}

void LNR(Tree T) {
    if (!T) return;
    LNR(T->pLeft);
    printProduct(T->info);
    LNR(T->pRight);
}

int countProducts(Tree T, int year) {
    if (!T) return 0;
    int dem = 0;
    if (T->info.year == year) {
        dem++;
    }

    return dem + countProducts(T->pLeft, year) + countProducts(T->pRight, year);

}

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "List of products: ";
    cout << "\nID\tName\tType\tYear\tWarranty\n";
    LNR(T);

    int year;cin >> year;
    cout << "Number of products produced in " << year << ": " << countProducts(T, year) << endl;

    return 0;
}


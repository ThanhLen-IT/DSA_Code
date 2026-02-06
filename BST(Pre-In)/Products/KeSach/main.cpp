/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multi_set
map
unordered_map
include
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct Sach
{
	string name;
	int gia;
	int trongLuong;
	int soTrang;
};

struct node
{
	Sach info;
	node* left;
	node* right;
};
typedef node* Tree;

Tree getNode(Sach x) {
	Tree p = new node;
	p->info.name = x.name;
	p->info.gia = x.gia;
	p->info.trongLuong = x.trongLuong;
	p->info.soTrang = x.soTrang;
	p->left = p->right = NULL;
	return p;
}

void insertTree(Tree& T, Sach x) {
	if (!T) {
		T = getNode(x);
		return;
	}
	if (x.name < T->info.name) insertTree(T->left, x);
	if (x.name > T->info.name) insertTree(T->right, x);
}

void inputTree(Tree& T) {
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		Sach s;
		cin >> s.name;
		cin.ignore();
		cin >> s.gia;
		cin.ignore();
		cin >> s.trongLuong;
		cin.ignore();
		cin >> s.soTrang;
		cin.ignore();
		insertTree(T, s);
	}
}

int doSauNode(Tree T, string name) {
	if (!T) return 0;
	int dem = 1;

	if (name < T->info.name) {
		dem+=doSauNode(T->left, name);
	}
	else if (name > T->info.name) {
		dem += doSauNode(T->right, name);
	}
	return dem;
}

void printNodeTrai(Tree T, string name) {
	

	if (!T || T->left == NULL) {
		cout << "Node nay la node la'";
		return;
	}
	else {
		if (name < )
	}
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	string str;
	cin >> str;
	cout << "Do sau la: " << doSauNode(T, str);
}
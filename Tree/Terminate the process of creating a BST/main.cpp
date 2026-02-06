/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct node {
	int info;
	node* left, * right;
};

typedef node* Tree; 

void insertTree(Tree T, int x) {

}

void inputTree(Tree& T) {
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		insertEle(T, x);
	}
}


int main()
{
	Tree T = NULL;
	inputTree(T); //Khi bi trung gia tri thi ket thuc qua trinh tao cay, khong nhap tiep nua
	cout << "NLR: "; NLR(T);
	return 0;
}




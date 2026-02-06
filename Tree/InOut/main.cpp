/*MÔ TẢ BÀI TOÁN
Khai báo kiểu Cây nhị phân tìm kiếm có tên là Tree mà mỗi phần tử chứa một số nguyên.Hãy viết các hàm thực hiện các yêu cầu sau :

Xây dựng CNPTK gồm n số nguyên, theo thứ tự các giá trị được nhập từ bàn phím.

Duyệt cây theo thứ tự Node - Left - Right, Left - Node - Right, Left - Right - Node.

INPUT

- Một số nguyên dương n, chỉ số nút của cây, 0 < n < 100

	- Dãy gồm n số nguyên dương, đôi một khác nhau.Các giá trị được thêm vào cây theo thứ tự mà nó được nhập.

	OUTPUT

	- Xuất theo template.*/


#include <iostream>
using namespace std;

struct node {
	int info;
	node* left, * right;
};
/*node* p là con trỏ tới node gốc xem như nó quản lí cây
và đại diện cho cây*/

typedef node* Tree; //Tree là tên gọi khác của node*

node* getNode(int x) {
	node* p = new node;
	p->info = x;
	p->left = p->right = NULL;
	return p;
}

void insertNode(Tree &T, int x) {
	if (T == NULL)
		T = getNode(x);
	if (x == T->info) return;
	if (x < T->info)
		insertNode(T->left, x);
	else
		insertNode(T->right, x);
	
}
void inputTree(Tree &T) {
	int n,x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		insertNode(T, x);
	}

}
void NLR(Tree T) {
	if (!T) return;
	cout << T->info << " ";
	NLR(T->left);
	NLR(T->right);
}

void LRN(Tree T) {
	if (!T) return;
	LRN(T->left);
	LRN(T->right);
	cout << T->info << " ";
}

void LNR(Tree T) {
	if (!T) return;
	LNR(T->left);
	cout << T->info << " ";
	LNR(T->right);
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "\nNLR: "; NLR(T);
	cout << "\nLRN: "; LRN(T);
	cout << "\nLNR: "; LNR(T);

	return 0;
}

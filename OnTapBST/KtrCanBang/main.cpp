/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *left, *right;
};

void add(Node* &root, int x){
    /*
        Hàm thêm một số vào cây
        Hàm này đã được viết đầy đủ và đảm bảo đúng
        Sinh viên không cần phải viết hàm này
    */
    if (root == NULL){
        root = new Node;
        root->val = x;
        root->left = root->right= NULL;
    } else {
        if (x < root->val) add(root->left, x);
        else if (x > root->val) add(root->right, x);
    }
}


//###INSERT CODE HERE -


int heightTree(Node* T){
	if (!T) return 0;

	int hLeft = heightTree(T->left);
	int hRight = heightTree(T->right);

	return 1 + max(hLeft,hRight);
}
void LNR(Node* T, int& count){
	if (!T) return;

	LNR(T->left,count);
	int tmp=heightTree(T->left) - heightTree(T->right);
	if (tmp >= 2 || tmp <= -2)
		count++;
	LNR(T->right, count);
}

int unbalance(Node* T){
	int count=0;;
	LNR(T,count);
	return count;
}






int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    Node *root = NULL;

    int x;
    while (cin >> x){
        add(root, x);
    }

    cout << "So node bi mat can bang la " << unbalance(root);
    return 0;
}

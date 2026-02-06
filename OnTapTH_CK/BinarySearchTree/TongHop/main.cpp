#include <iostream>
using namespace std;

/* ========= CẤU TRÚC ========= */

struct Node {
    int data;
    Node* left;
    Node* right;
};

/* ========= TẠO / KHỞI TẠO ========= */

Node* CreateNode(int x) {
    // TODO
    Node* p= new Node;
    p->data=x;
    p->left=p->right= NULL;
    return p;
}

/* ========= INSERT ========= */

Node* Insert(Node* root, int x) {
    // TODO
	if (!root){
		root = CreateNode(x);
		return root;
	}

	if (x < root->data){
		root->left=Insert(root->left, x);
	}else{
		root->right=Insert(root->right,x);
	}
	return root;

}

/* ========= SEARCH ========= */

Node* Search(Node* root, int x) {
    // TODO

    if (!root || root->data==x){
		return root;
    }

	if (x < root->data){
		root->left=Search(root->left, x);
	}else{
		root->right=Search(root->right,x);
	}


}

/* ========= DUYỆT ========= */

// Inorder (LNR)
void Inorder(Node* root) {
    // TODO
    if (!root) return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

// Preorder (NLR)
void Preorder(Node* root) {
    // TODO
    if (!root) return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

// Postorder (LRN)
void Postorder(Node* root) {
    // TODO
    if (!root) return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

/* ========= ĐẾM ========= */

int Count(Node* root) {
    // TODO
    if (!root) return 0;

    return 1 + Count(root->left) + Count(root->right);
}

int CountLeaf(Node* root) {
    // TODO
    if (!root) return 0;

    int dem = 0;

    if (!root->left && !root->right)
		dem++;
	return dem + CountLeaf(root->left) + CountLeaf(root->right);
}

int CountOneChild(Node* root) {
    // TODO
    if (!root) return 0;

    int dem=0;
    if ((!root->left && root->right) || (root->left && !root->right))
		dem++;
	return dem + CountOneChild(root->left) + CountOneChild(root->right);
}

int CountTwoChild(Node* root) {
    // TODO
     if (!root) return 0;

    int dem=0;
    if (root->left && root->right)
		dem++;
	return dem + CountTwoChild(root->left) + CountTwoChild(root->right);
}

/* ========= TÍNH ========= */

int Sum(Node* root) {
    // TODO
    if (!root) return 0;

    return root->data + Sum(root->left) + Sum(root->right);

}

int Height(Node* root) {
    // TODO
    if (!root) return 0;
    int hl = Height(root->left);
    int hr = Height(root->right);

    return 1 + max(hl,hr);
}

int Level(Node* root, int x, int lvl) {
    // TODO
    if (!root) return -1;

    if (root->data==x){
		return lvl;
    }

    int left = Level(root->left, x, lvl+1);
    if (left != -1)
		return left;

	return Level(root->right, x, lvl +1);

}

/* ========= MIN / MAX ========= */

Node* FindMin(Node* root) {
    // TODO
    if (!root){
		return root;
    }

    while (root->left){
		root=root->left;
    }
    return root;
}

Node* FindMax(Node* root) {
    // TODO

    if (!root){
		return root;
    }

    while (root->right){
		root=root->right;
    }

    return root;
}

/* ========= KIỂM TRA ========= */

bool IsLeaf(Node* p) {
    // TODO
	if (!p) return false;
    return (!p->left && !p->right);

}

bool IsBST(Node* root, int minVal, int maxVal) {
    // TODO
    if (!root)
		return true;

	if (root->data <= minVal || root->data >= maxVal)
		return false;

	return IsBST(root->left, minVal, root->data) &&
           IsBST(root->right, root->data, maxVal);


}

/* ========= DELETE ========= */

Node* Delete(Node* root, int x) {
    // TODO

    if (!root) return NULL;

    if (x<root->data){
		root->left= Delete(root->left, x);
    }else if(x > root->data){
		root->right= Delete((root->right, x));
    }else{
		if (!root->left){
			Node * tmp = root->right;
			delete root;
			return tmp;
		}
		if (!root->right){
			Node* tmp = root->left;
			delete root;
			return tmp;
		}

		Node * tmp = FindMin(root->right);
		root->data=tmp->data;
		root->right=Delete(root->right, tmp->data);


    }
    return root;

}

/* ========= GIẢI PHÓNG ========= */

void Clear(Node* &root) {
    // TODO

     if (!root) return;

    Clear(root->left);
    Clear(root->right);
    delete root;
    root = NULL;
}

Node* insertAVL(Node* root, int x ){
	if (!root) return CreateNode(x);

	if (x<root->data){
		root->left =insertAVL(root->left)
	}
}

/* ========= MAIN TEST ========= */

int main() {
    Node* root = NULL;

    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = Insert(root, x);
    }

    // GỢI Ý TEST
    // Inorder(root);
    // cout << Count(root);
    // cout << Height(root);
    // root = Delete(root, x);

    return 0;
}

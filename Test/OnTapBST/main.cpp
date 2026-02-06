#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int info;
	Node* left;
	Node* right;
};

typedef Node* Tree;

void initTree(Tree T) {
	T->left = T->right = NULL;
}
Node* getNode(int x) {
	Node* p = new Node;
	p->info = x;
	p->left = p->right = NULL;
	return p;
}

void insertNode(Tree& T, int x) {
	if (!T) {
		T->info = x;
		return;
	}
	if (x < T->info) insertNode(T->left, x);
	if (x > T->info) insertNode(T->right, x);
}

Node* searchNode(Tree T, int x) {
	if (!T || T->info == x) return T;
	if (x < T->info) searchNode(T->left, x);
	else { searchNode(T->right, x); }
}
void findReplaceNode(Node*& p, Node*& q) {
	if (q->left != nullptr) {
		findReplaceNode(p, q->left);
	}
	else {
		p->info = q->info;     // Copy giá trị
		p = q;                 // Trả về node sẽ bị xóa
		q = q->right;          // Nối lại cây
	}
}


void DeleteNode(Tree& T, int x) {
	if (!T) return;

	if (x < T->info) DeleteNode(T->left, x);
	else if (x > T->info) DeleteNode(T->right, x);
	else
	{
		Node* p = T;
		//Khong co con trai
		if (!T->left) {
			T = T->right;
		}
		else { //Khong co con ben phai
			if (!T->right) {
				T = T->left;
			}
			else
			{
				//Node co 2 con
				//Trai nhat ben phai
				findReplaceNode(p, T->right);
			}

		}
	    
		delete p;
	}
}

vector<vector<int>> duyetTheoMuc(Tree T) {
	vector<vector<int>> res;
	queue<Node*> q;
	q.push(T);
	while (!q.empty()) {
		int sz = q.size();
		vector<int> level;
		for (int i = 0; i < sz; i++) {
			Node* curr = q.front(); q.pop();

			level.push_back(curr->info);
			if (curr->left) q.push(curr->left);
			if (curr->right) q.push(curr->right);
		}
		res.push_back(level);
	}
	return res;
}

int height(Tree T) {
	if (!T) return 0;
	return 1 + max(height(T->left), height(T->right));
}

void NLR(Tree T) {
	if (!T) return;

	cout << T->info << " ";
	NLR(T->left);
	NLR(T->right);
}

void LNR(Tree T) {
	if (!T) return;
	
	LNR(T->left);
	cout << T->info << " ";
	LNR(T->right);
}
void LRN(Tree T) {
	if (!T) return;

	LRN(T->left);
	LRN(T->right);
	cout << T->info << " ";
}

int countX(Tree T, int x) {
	if (!T) return 0;
	int dem = 0;
	if (T->info == x) dem++;
	return dem + countX(T->left, x) + countX(T->right, x);
}

Node* rotateLeft(Tree& T) {
	Node* y = T->right;
	Node* T2 = y->left;

	y->left = T;
	T->right = T2;

	return y;

}

Node* rotateRight(Tree& T) {
	Node* y = T->left;
	Node* T3 = y->right;

	y->right = T;
	T->left = T3;

	return y;
}


Node* rotateLeftRight(Tree& T) {
	T->left = rotateLeft(T);
	return rotateRight(T);
}

Node* rotateRightLeft(Tree& T) {
	T->right = rotateRight(T);
	return rotateLeft(T);
}


void Rotate(Tree& T, int x) {
	switch (x)
	{
	case 1:
		T = rotateLeft(T);
		break;
	case 2:
		T = rotateRight(T);
		break;
	case 3:
		T = rotateLeftRight(T);
		break;
	case 4:
		T = rotateRightLeft(T);
		break;
	default:
		cout << "Khong hop le" << endl;
		break;
	}
	
}

bool isALV(Tree T) {
	if (!T) return 1;

	int lHeight = height(T->left);
	int rHeight = height(T->right);

	return (lHeight == rHeight) ? 1 : 0;
}

void MENU(Tree &T) {
	while (true) {
		cout << "1.Nhap cay" << endl;
		cout << "2.Tim kiem node co gia tri x" << endl;
		cout << "3.Xoa node" << endl;
		cout << "4.Duyet theo muc" << endl;
		cout << "5.Tinh chieu cao" << endl;
		cout << "6.Duyet cay(in cay LNR, NLR, LRN)" << endl;
		cout << "7.Đếm giá trị x xuất hiện bao nhiêu lần" << endl;
		cout << "8.In cây theo dạng xoay (rotate tree)" << endl;
		cout << "9.AVL Tree?" << endl;
		cout << "10.Red-Black Tree?" << endl;
		cout << "11.Ket thuc" << endl;
		cout << "-------------------------------------------------" << endl;
		int check, n, x;
		cout << "Moi ban chon: ";
		cin >> check;
		if (check == 11) break;
		switch (check) 
		{
		case 1:
			cin >> n;
			for (int i = 0; i < n; i++) {
				cin >> x;
				insertNode(T, x);
			}
			break;
		case 2:
			cin >> x;
			Node* p = searchNode(T, x);
			if (p) cout << p->info;
			break;
		case 3:
			cin >> x;
			DeleteNode(T, x);
			break;
		case 4:
		{
			vector<vector<int>> vt = duyetTheoMuc(T);
			for (int i = 0; i < vt.size(); i++) {
				for (int j = 0; j < vt[i].size(); j++) {
					cout << vt[i].at(j) << " ";
				}
				cout << endl;
			}
			break;
		}
		case 5:
			cout << "Chieu cao cay: " << height(T);
			break;
		case 6:
			cout << "NLR: "; NLR(T); cout << endl;
			cout << "LNR: "; LNR(T); cout << endl;
			cout << "LRN: "; LRN(T); cout << endl;
			break;
		case 7:
			cin >> x;
			cout << "So lan xuat hien: " << countX(T, x);
		case 8:
			cout << "Chon huong xoay (1.Trai/2.Phai/3.KepTrai-Phai/4.KepPhai-Trai): ";
			cin >> x;
			Rotate(T, x);
			break;
		case 9:
			cout << isALV(T);
			break;
		default:
			cout << "Lua chon khong hop le" << endl;
			break;
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Tree T;
	initTree(T);
	MENU(T);
	return 0;
}
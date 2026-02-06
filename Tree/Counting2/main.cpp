/*MÔ TẢ BÀI TOÁN

Khai báo kiểu Cây nhị phân tìm kiếm có tên là Tree mà mỗi phần tử chứa một số nguyên. Hãy viết các hàm thực hiện các yêu cầu đếm sau:

Đếm xem trong cây T có bao nhiêu số chẵn, bao nhiêu số lẻ ?

Đếm xem trong cây có bao nhiêu nút có giá trị âm? bao nhiêu nút có giá trị dương?

Đếm xem cây có bao nhiêu số nguyên tố và liệt kê các số nguyên tố có trong cây (theo cơ chế NLR)

Xác định chiều cao của cây

 

INPUT

- Một số nguyên dương n, chỉ số nút của cây, 0<n<100

- Dãy gồm n số nguyên dương, đôi một khác nhau. Các giá trị được thêm vào cây theo thứ tự mà nó được nhập.

OUTPUT

- Xuất theo template.*/

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

node* getNode(int x) {
    node* p = new node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void insertNode(Tree& T, int x) {
    if (!T)
        T = getNode(x);
    if (x == T->info) return;
    if (x < T->info)
        insertNode(T->left, x);
    else
        insertNode(T->right, x);

}

void inputTree(Tree& T) {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertNode(T, x);
    }
}
void LNR(Tree T) {
    if (!T) return;
    LNR(T->left);
    cout << T->info << " ";
    LNR(T->right);
}

int countNodes(Tree T) {
    if (T == NULL) return 0;
    return countNodes(T->left) + countNodes(T->right) + 1;
}

int depthOfTree(Tree T) {
    if (!T) return -1;
    return max(depthOfTree(T->left), depthOfTree(T->right)) + 1;
}

void countEven(Tree T, int& count) {
    if (!T) return;
    if (T->info % 2 == 0)
        count++;
    countEven(T->left, count);
    countEven(T->right, count);
}
void countOdd(Tree T, int& count) {
    if (!T) return;
    if (T->info % 2 != 0)
        count++;
    countOdd(T->left, count);
    countOdd(T->right, count);
}

int countPositive(Tree T) {
    if (!T) return 0;
    int count = 0;
    if (T->info > 0)
        count++;
    return count + countPositive(T->left) + countPositive(T->right);
}


int countNegative(Tree T) {
    if (!T) return 0;
    int count = 0;
    if (T->info < 0)
        count++;
    return count + countNegative(T->left) + countNegative(T->right);
}

bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int countPrime(Tree T) {
    if (!T) return 0;
    int count = 0;
    if (isPrime(T->info))
        count++;
    return count + countPrime(T->left) + countPrime(T->right);
}

void listPrime(Tree T) {
    if (!T) return;
    if (isPrime(T->info))
        cout << T->info << " ";
    listPrime(T->left);
    listPrime(T->right);
}

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "LNR: "; LNR(T); cout << endl;

    cout << "Number of nodes: " << countNodes(T) << endl;
    cout << "Depth of Tree: " << depthOfTree(T) << endl;

    int count_even = 0, count_odd = 0;
    countEven(T, count_even);countOdd(T, count_odd);
    cout << "Number of even nodes: " << count_even << endl;
    cout << "Number of odd nodes: " << count_odd << endl;

    cout << "Number of positive nodes: " << countPositive(T) << endl;
    cout << "Number of negative nodes: " << countNegative(T) << endl;

    cout << "Number of prime nodes: " << countPrime(T) << endl;
    cout << "Prime numbers: "; listPrime(T);



    return 0;
}

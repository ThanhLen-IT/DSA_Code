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
struct Node {
    int key;
    Node* left;
    Node* right;
};

typedef Node* TREE;

Node* createNode(int x) {
    Node* p = new Node;
    p->key = x;
    p->left = p->right = NULL;
    return p;
}

void insertNode(TREE &t, int x) {
    if (!t) {
        t = createNode(x);
        return;
    }
    if (x < t->key) insertNode(t->left, x);
    else if (x > t->key) insertNode(t->right, x);
}

// Duyệt theo tầng từ dưới lên, không dùng vector
void levelOrderBottom(TREE root) {
    if (!root) return;

    // Hàng đợi thủ công bằng mảng
    Node* queue[1000]; // giả sử tối đa 1000 node
    int front = 0, rear = 0;

    // Mảng lưu kết quả duyệt
    int result[1000];
    int count = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* cur = queue[front++];
        result[count++] = cur->key;

        if (cur->left) queue[rear++] = cur->left;
        if (cur->right) queue[rear++] = cur->right;
    }

    // In ngược lại
    for (int i = count - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
}

int main() {
    TREE t = NULL;
    int x;
    while (cin >> x && x != -1) {
        insertNode(t, x);
    }
    levelOrderBottom(t);
    return 0;
}

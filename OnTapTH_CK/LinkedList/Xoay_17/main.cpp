/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
#include <limits>
#include <tuple>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
        void printLinkedList();

};

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}


void SinglyLinkedList::printLinkedList() {
    SinglyLinkedListNode* cur = head;
    while (cur) {
        cout << cur -> data << " ";
        cur = cur -> next;
    }
    cout << '\n';
}


//###INSERT CODE HERE -

void xoayTrai(SinglyLinkedList &L, int k, int N) {
    if (N <= 1) return;
    k %= N;
    if (k == 0) return;

    SinglyLinkedListNode* cur = L.head;

    // tìm node thứ k
    for (int i = 1; i < k; i++) {
        cur = cur->next;
    }

    SinglyLinkedListNode* newHead = cur->next;
    cur->next = nullptr;
    L.tail->next = L.head;

    L.head = newHead;
    L.tail = cur;
}

int main() {
    int N;
    cin >> N;

    SinglyLinkedList list;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        list.insert_node(x);
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; i++) {
        int x;
        string y;
        cin >> x >> y;

        if (y == "CC") {
            xoayTrai(list, x, N);
        } else {
            xoayTrai(list, N - (x % N), N);
        }

        list.printLinkedList();
    }

    free_singly_linked_list(list.head);
    return 0;
}

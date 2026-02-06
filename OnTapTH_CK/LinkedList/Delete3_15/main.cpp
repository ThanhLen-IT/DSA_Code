/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
#include <limits>
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

SinglyLinkedListNode* removeNthFromEnd(SinglyLinkedListNode* head, int n);

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }
    int n; cin >> n;
    llist->head = removeNthFromEnd(llist->head, n);
    llist->printLinkedList();
    free_singly_linked_list(llist->head);

    return 0;
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

SinglyLinkedListNode* removeNthFromEnd(SinglyLinkedListNode* head, int n){
	SinglyLinkedListNode* fake = new SinglyLinkedListNode(0);
    fake->next = head;

    SinglyLinkedListNode* p = fake;
    SinglyLinkedListNode* prev=fake;

    for (int i=0; i<=n+1; i++){
		if (p)
			p=p->next;
    }

    while (p){

		p=p->next;
		prev=prev->next;
    }

     SinglyLinkedListNode* del = prev->next;
     if (del){
		prev->next=del->next;
		delete del;
     }

	SinglyLinkedListNode* newHead = fake->next;
    delete fake;
    return newHead;
}

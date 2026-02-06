#include <iostream>
using namespace std;

/* ========= CẤU TRÚC ========= */

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

/* ========= KHỞI TẠO ========= */

void Init(List &l) {
    // TODO
    l.head = l.tail= NULL;
}

/* ========= TẠO NODE ========= */

Node* CreateNode(int x) {
    // TODO
    Node* p= new Node;
    p->data=x;
    p->next=NULL;
    return p;
}

/* ========= THÊM ========= */

// Thêm đầu
void AddHead(List &l, int x) {
    // TODO
    if(!l.head){
		l.head=l.tail=CreateNode(x);
		return;
    }

    Node* p= CreateNode(x);
    p->next=l.head;
    l.head=p;
}

// Thêm cuối
void AddTail(List &l, int x) {
    // TODO
    if (!l.head){
		l.head=l.tail=CreateNode(x);
		return;
    }

    Node *p= CreateNode(x);
    l.tail->next=p;
    l.tail=p;
}

/* ========= XÓA ========= */

// Xóa đầu
void RemoveHead(List &l) {
    // TODO
    if (!l.head) return;
    Node* del = l.head;

    l.head=l.head->next;
    if (!l.head) l.tail=NULL;
    delete del;
}

// Xóa sau node q
void RemoveAfter(List &l, Node* q) {
    // TODO
    if (!q || !q->next) return;

    Node* del = q->next;
    q->next = del->next;

    if (!q->next) l.tail = q;
    delete del;

}

// Xóa theo giá trị
void RemoveX(List &l, int x) {
    // TODO
   if (!l.head) return;
   if (l.head->data==x){
		RemoveHead(l);
		return;
   }

   Node *p=l.head;
   while (p->next){
		if (p->next->data==x)
			break;
		p=p->next;
   }

   if (p->next) RemoveAfter(l,p);

}

/* ========= DUYỆT / XUẤT ========= */

void PrintList(List l) {
    // TODO
    Node *p =l.head;
    while(p){
		cout<<p->data<<" ";
		p=p->next;
    }
}

/* ========= TÌM KIẾM ========= */

Node* Search(List l, int x) {
    // TODO
    Node* p=l.head;
    while (p){
		if (p->data==x){
			return p;
		}
		p=p->next;
    }
    return NULL;
}

/* ========= ĐẾM / TÍNH ========= */

// Đếm số node
int Count(List l) {
    // TODO
    int dem=0;
    Node* p=l.head;
    while (p){
		dem++;
		p=p->next;
    }
    return dem;
}

// Tổng giá trị
int Sum(List l) {
    // TODO
	int sum=0;
    Node* p=l.head;
    while (p){
		sum+=p->data;
		p=p->next;
    }
    return sum;
}

// Tìm max
int Max(List l) {
    // TODO
    if (!l.head) return -1;
	int max = l.head->data;
    Node* p=l.head->next;
    while (p){
		if (p->data>max){
			max =p->data;
		}
		p=p->next;
    }
    return max;
}

/* ========= SẮP XẾP ========= */

// Bubble Sort (đổi data)
void SortList(List &l) {
    // TODO
    if (!l.head || !l.head->next) return;

    for(Node* i=l.head; i; i=i->next){
		for(Node* j=l.head; j->next; j=j->next){
			if (j->data > j->next->data){
				int tmp = j->data;
				j->data = j->next->data;
				j->next->data=tmp;
			}
		}
    }
}

/* ========= MERGE SORT LIST ========= */

Node* GetMiddle(Node* head) {
    // TODO
    Node * fast = head->next;
    Node * slow = head;

    while (fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
    }
    return slow;
}

Node* Merge(Node* a, Node* b) {
    // TODO
    if (!a) return b;
    if (!b) return a;

    if (a->data < b->data){
		a->next = Merge(a->next,b);
		return a;
    }else{
		b->next=Merge(a,b->next);
		return b;
    }
}

Node* MergeSort(Node* head) {
    // TODO

    if (!head ) return NULL;
    if (!head->next) return head;

    Node* mid = GetMiddle(head);
    Node *right= mid->next;
    mid->next=NULL;

    Node * left = MergeSort(head);
    right = MergeSort(right);

    return Merge(left,right);

}

/* ========= GIẢI PHÓNG ========= */

void Clear(List &l) {
    // TODO
    while (l.head)
		RemoveHead(l);
}

/* ========= MAIN TEST ========= */

int main() {
    List l;
    Init(l);

    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        AddTail(l, x);
    }

    // GỢI Ý TEST
    // SortList(l);
    // l.head = MergeSort(l.head);

    PrintList(l);
    return 0;
}

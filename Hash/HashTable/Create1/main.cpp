/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

//###INSERT CODE HERE -

struct Node {
    int info;
    Node* next;
};

struct Hash {
    int m;//kích thước bảng băm, số lượng địa chỉ
    Node** heads; //là con trỏ cấp 2 -> qli mảng các con trỏ đầu của các list
    int n; //slg phần tử đang có trong Hash
};

void initHash(Hash& H) {
    H.n = 0;
    H.heads = new Node * [H.m];
    for (int i = 0; i < H.m; i++) {
        H.heads[i] = NULL;
    }
}

int hashFunction(Hash H,int k) {
    return k % H.m;
}


Node* getNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;

}


void addList(Node*& head, int x) {

    Node* newEle = getNode(x);
    if (!head) {
        head = newEle;
        return;
    }

    Node* p = head;
    Node* q = NULL;
    while (p && x > p->info) {
        q = p;
        p = p->next;
    }
    //Thêm đầu
    if (!q) {
        newEle->next = p;
        head = newEle;
    }
    else {//Thêm giữa và cuối
        newEle->next = p;
        q->next = newEle;
    }
 
    
}

void insertHash(Hash& H, int x) {
    //B1: Băm x -> địa chỉ (index) của mảng
    int idx = hashFunction(H, x);
    //B2: Thêm đầu/cuối dslk (xử lí theo y/c đề bài)
    addList(H.heads[idx], x);
    //B3: Cập nhật slg phần tử
    H.n++;
}

void printList(Node* H) {
    Node* p = H;
    while (p) {
        cout << p->info << " ";
        p = p->next;
    }
}

void traverseAllHash(Hash H) {
    for (int i = 0; i < H.m; i++) {
        cout << "Bucket " << i << ": ";
        printList(H.heads[i]);
        cout << endl;
    }
}

int main()
{
    Hash H;
    cin >> H.m; // m la so dia chi co trong bang bam
    initHash(H); //khoi tao cac bucket

    int n, x;cin >> n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i <= n;i++)
    {
        cin >> x;
        insertHash(H, x); // them 1 gia tri du lieu vao bang bam
    }
    cout << "Created Hash:" << endl;
    traverseAllHash(H); // Xuat toan bo cac bucket cua Bang bam

    return 0;
}


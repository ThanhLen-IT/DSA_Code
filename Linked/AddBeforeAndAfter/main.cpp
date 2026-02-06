/*MÔ TẢ BÀI TOÁN

Viết 1 chương trình game đơn giản như sau:

- Chương trình cho phép người dùng (user) chọn thực hiện 1 thao tác nào đó từ Menu, trả về kết quả thực hiện thao tác đó.

- Tiếp theo bài trước, viết các hàm cho phép Thêm một phần tử mới vào sau hoặc trước một phần tử nào đó có trong danh sách.

Cụ thể là, thêm 1 phần tử mới chứa giá trị y vào sau (hoặc vào trước) 1 phần tử chứa giá trị x có trong danh sách. Nếu có nhiều phần tử chứa giá trị x thì chỉ chèn thêm một phần tử mới vào sau phần tử đầu tiên chứa giá trị x tìm thấy trong danh sách (tính từ đầu danh sách). Nếu danh sách không chứa x thì không thêm gì cả và  xuất thông báo  theo câu lệnh: cout << "\nCan't find the value "<<x;  (nhớ có Enter)

*** Trường hợp thêm vào danh sách rỗng thì ưu tiên xuất thông báo "không tìm thấy". Chỉ khi nào là yêu cầu in danh sách mới "List is empty".

INPUT & OUTPUT

 -  Theo template*/

 /*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
 define
 include
 using
 ###End banned keyword*/

#include  <iostream>
using namespace std;

struct DNode
{
    int info;
    DNode* pNext, * pPrev;
};

struct DList
{
    DNode* pHead, * pTail;
};

//###INSERT CODE HERE -

void init(DList& L) {
    L.pHead = L.pTail = NULL;
}

DNode* getNode(int x) {
    DNode* p = new DNode;
    p->info = x;
    p->pNext = p->pPrev = NULL;
    return p;
}

void addTail(DList& L, int x) {
    DNode* p = getNode(x);
    if (!L.pHead) {
        L.pHead = L.pTail = p;
    }
    else {
        L.pTail->pNext = p;
        p->pPrev = L.pTail;
        L.pTail = p;
    }
}

void createList(DList& L) {
    int x;
    while (true) {
        cin >> x;
        addTail(L, x);
    }
}

void printList(DList& L) {
    DNode* p = L.pHead;
    if (!p) {
        cout << "List is empty";
    }
    else {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void addHead(DList& L, int x) {
    DNode* p = new DNode;
    if (!p) {
        L.pHead = L.pTail = NULL;
    }
    else {
        L.pHead->pPrev = p;
        p->pNext = L.pHead;
        L.pHead = p;
    }
}

void addAfter(DList& L, int x, int y) {
    DNode* k = L.pHead;
    while (k) {
        if (k->info == x) break;
        k = k->pNext;

    }

    if (k) {
        DNode* p = getNode(y);
        p->pNext = k->pNext;
        p->pPrev = k;
        k->pNext->pPrev = p;
        k->pNext = p;
    }
    else
        cout << "\nCan't find the value " <<x;
}

void addBefore(DList& L, int x, int y) {
    DNode* k = L.pHead;
    while (k) {
        if (k->info == x) break;
        k = k->pNext;

    }
    if (k) {
        DNode* p = getNode(y);
        p->pNext = k;
        p->pPrev = k->pPrev;
        k->pPrev->pNext = p;
        k->pPrev = p;
    }
    else
        cout << "\nCan't find the value " << x;
}


int main()
{
    DList L;
    init(L);
    int x, y, choice;

    cout << "MENU:";
    cout << "\n1. Create a DList";
    cout << "\n2. Print the DList";
    cout << "\n3. Insert a value at the front";
    cout << "\n4. Insert a value at the end";
    cout << "\n5. Insert a value after a given value (only for the first value found)";
    cout << "\n6. Insert a value before a given value (only for the first value found)";
    cout << "\n7. Insert a value after a given value (for all the same values)";
    cout << "\n8. Insert a value before a given value (for all the same values)";
    cout << "\n20. Exit" << endl;

    while (true)
    {
        cout << "\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout << "\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout << "\nEnter a number: ";
            cin >> x;
            addHead(L, x);
            break;
        case 4:
            cout << "\nEnter a number: ";
            cin >> x;
            addTail(L, x);
            break;
        case 5:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addAfter(L, x, y);
            break;
        case 6:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addBefore(L, x, y);
            break;
        case 20:
            cout << "\nGOOD BYE";
            return 0;

        }
    }

    return 0;
}

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/
#include <iostream>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;;
}

struct Node {
    Hocsinh data;
    Node * next;
};

struct List {
    Node * head, * tail;
};

void Output(List ds) {
    Node *p = ds.head;
    if (p == NULL) {
        cout << "EMPTY";
    }
    while(p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}


//###INSERT CODE HERE -

void initList(List& L){
	L.head=L.tail=nullptr;
}

Node* getNode(Hocsinh x){
	Node* p=new Node;
	p->data=x;
	p->next=nullptr;
	return p;
}

void addTail(List& L, Hocsinh x){
	if (!L.head){
		L.head=L.tail=getNode(x);
		return;
	}

	Node* p= getNode(x);
	L.tail->next=p;
	L.tail=p;
}

double DTB(Hocsinh x){
	return (x.Anh+x.Hoa+x.Ly+x.Sinh+x.Toan+x.Van)/6;
}

void inputList(List& L, int n){
	for (int i=0; i<n; i++){
		Hocsinh x;
		InputElement(x);
		if (DTB(x)>=9.0) addTail(L,x);
	}
}


int main(){
	int n; cin>>n;
	List L;
	initList(L);
	inputList(L,n);
	Output(L);
}

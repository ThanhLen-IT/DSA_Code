#include <iostream>
#include <cstring>
#include <string>
using namespace std;


struct Province
{
	string id;
	string name;
	int population;
	float area;
};
struct node
{
	Province info;
	node* next;
};
struct List
{
	node* head;
	node* tail;
};
void Init(List& L)
{
	L.head = L.tail = NULL;
}
bool isEmpty(List L)
{
	return L.head == NULL;
}

node* getNote(Province x)
{
	node* p = new node;
	p->info = x;
	p->next = NULL;
	return p;
}

void addTail(List& L, Province x)
{
	node* p = getNote(x);
	if (isEmpty(L))
	{
		L.head = L.tail = p;
	}
	else
	{
		L.tail->next = p;
		L.tail = p;
	}
}

void inputListProvinces(List& L)
{
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		Province x;
		cin >> x.id;
		cin.ignore();
		getline(cin, x.name);
		cin >> x.population >> x.area;
		addTail(L, x);
	}
}

void  outputListProvinces(List L)
{
	if (isEmpty(L))
	{
		cout << "List is empty" << endl;
		return;
	}
	node* p = L.head;
    while (p)
	{
		cout << p->info.id << "\t" << p->info.name << "\t" << p->info.population << "\t" << p->info.area << endl;
		p = p->next;
	}
}

string lastWord(string s) {
	return s.substr(s.find_last_of(' ') + 1);
}



int removeProvinceLastName(List& L, string s)
{
	if (isEmpty(L)) {
		cout << "List is empty";
		return 0;
	}

	int count = 0;
	node* p = L.head;
	node* prev = NULL;
	while (p != NULL) {
		string last = lastWord(p->info.name);
		if (last == s) {
			count++;
			node* tmp = p;

			if (p == L.head) {
				L.head = L.head->next;
				if (L.head == NULL) L.tail = NULL;
				p = L.head;
			}
			else {
				prev->next = p->next;
				if (p == L.tail) L.tail = prev;
				p = p->next;
			}
			delete tmp;
		}
		else {
			prev = p;
			p = p->next;
		}
	}
	return count;
}





int main()
{
	List L;
	Init(L);
	inputListProvinces(L);
	cout << "List of provinces:" << endl;
	cout << "ID\t|Province\t|Population\t|Area" << endl;
	outputListProvinces(L);
	string s;
	cout << "Enter the last word of name to search: ";
	
	cin >> s;

	int i = removeProvinceLastName(L, s);

	if (i == 0) {
		cout << "Not found";
	}
	else {
		cout << "Updated List:" << endl;
		cout << "ID\t|Province\t|Population\t|Area" << endl;
		outputListProvinces(L);
	}

	return 0;
}

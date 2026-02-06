
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
	node* p = L.head;
	while (p)
	{
		cout << p->info.id << "\t" << p->info.name << "\t" << p->info.population << "\t" << p->info.area << endl;
		p = p->next;
	}
}

void outputProvincesMore1MillionPop(List L)
{
	node* p = L.head;
	while (p)
	{
		if (p->info.population*1000 > 1000000)
		{
			cout << p->info.id << "\t" << p->info.name << "\t" << p->info.population << "\t" << p->info.area << endl;
		}
		p = p->next;
	}
}

node* findProMaxArea(List& L)
{
	node* p = L.head;
	node* maxNode = p;
	while (p)
	{
		if (p->info.area > maxNode->info.area)
		{
			maxNode = p;
		}
		p = p->next;
	}
	return maxNode;
}

void outputProvince(Province x)
{
	cout << x.id << "\t" << x.name << "\t" << x.population << "\t" << x.area << endl;
}

int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout << "List of provinces:" << endl;
    cout << "ID\t|Province\t|Population\t|Area" << endl;
    outputListProvinces(L);

    cout << "Provinces with a population of more than 1 million:" << endl;
    outputProvincesMore1MillionPop(L);

    cout << "The largest province:" << endl;
    node* p = findProMaxArea(L);
    if (p) outputProvince(p->info);

    return 0;
}




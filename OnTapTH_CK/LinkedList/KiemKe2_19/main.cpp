/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
set
nth_element
priority_queue
sort_heap
multiset
map
multimap
###End banned keyword*/
//###INSERT CODE HERE -

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Hang{
	string id;
	int soLuong;
};

bool cmpLessNumber(string a, string b){
	if (a.length() != b.length() ) return a.length() < b.length();
	return a < b;
}

bool cmpMoreNumber(string a, string b){
	if (a.length() != b.length() ) return a.length() > b.length();
	return a > b;
}

void quickSort(vector<string> & vt, int left, int right){
	int mid = left + (right -left)/2;

	string pivot = vt[mid];
	int i=left, j=right;
	while (i<=j){
		while (cmpLessNumber(vt[i], pivot)) i++;
		while (cmpMoreNumber(vt[j], pivot)) j--;

		if (i<=j){
			swap(vt[i], vt[j]);
			i++; j--;
		}

	}

	if (left < j) quickSort(vt, left, j);
	if ( i < right) quickSort(vt, i, right);
}
void input(vector<Hang>& ls, const vector<string>& vt) {
    if (vt.empty()) return;

    ls.clear(); // đảm bảo ls rỗng

    Hang cur;
    cur.id = vt[0];
    cur.soLuong = 1;

    for (int i = 1; i < vt.size(); i++) {
        if (vt[i] == cur.id) {
            cur.soLuong++;
        } else {
            ls.push_back(cur);
            cur.id = vt[i];
            cur.soLuong = 1;
        }
    }
    ls.push_back(cur);
}


bool cmpLessCount(Hang a, Hang b){
	if (a.soLuong!=b.soLuong) return a.soLuong < b.soLuong;
	return cmpMoreNumber(a.id,b.id);
}

bool cmpMoreCount(Hang a, Hang b){
	if (a.soLuong!=b.soLuong) return a.soLuong > b.soLuong;
	return cmpLessNumber(a.id,b.id);
}

void quickSort_v2(vector <Hang>& ls, int left, int right){

	int mid = left + (right -left)/2;

	Hang pivot = ls[mid];
	int i=left, j=right;
	while (i<=j){
		while (cmpMoreCount(ls[i], pivot)) i++;
		while (cmpLessCount(ls[j], pivot)) j--;

		if (i<=j){
			swap(ls[i], ls[j]);
			i++; j--;
		}

	}

	if (left < j) quickSort_v2(ls, left, j);
	if ( i < right) quickSort_v2(ls, i, right);
}

int main(){
	int N;
	cin>>N;

	vector<string> vt(N);


	for (int i =0; i<N ; i++){
		cin>> vt[i];
	}

	if (N > 0)
		quickSort(vt, 0, N - 1);


	vector <Hang> ls;

	input(ls,vt);

	if (!ls.empty())
		quickSort_v2(ls, 0, ls.size() - 1);


	for (int i=0; i<ls.size(); i++){
		cout<<ls[i].id << " " << ls[i].soLuong<<"\n";
	}

}

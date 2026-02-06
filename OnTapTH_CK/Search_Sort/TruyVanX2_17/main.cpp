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

void input(vector <Hang>& ls, vector<string> vt){
	int n= vt.size();
	if (n==0){
		return;
	}

	int nls =-1;
	for (int i=0; i<vt.size(); i++){
		if (ls.empty() || vt[i]==ls[nls].id ){
			Hang tmp;
			tmp.id= vt[i];
			tmp.soLuong= 1;

			ls.push_back(tmp);
			nls++;
		}else{
			ls[nls].soLuong++;
		}

	}
}

int main(){
	int N;
	cin>>N;

	vector<string> vt(N);


	for (int i =0; i<N ; i++){
		cin>> vt[i];
	}

	quickSort(vt,0,N-1);

	vector <Hang> ls;

	input(ls,vt);

	for (int i=0; i<ls.size(); i++){

		cout <<ls[i].id<<" "<<ls[i].soLuong<<"\n";
	}

}

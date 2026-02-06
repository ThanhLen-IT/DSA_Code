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

void QuickSort(vector<string> &vt, int left, int right){

	if (left>=right) return;
	int i =left;
	int j = right;

	string pivot = vt[left+(right-left)/2];

	while (i<j){
		while (vt[i] < pivot) i++;
		while(vt[j] > pivot) j--;

		if (i<=j){
			swap(vt[i],vt[j]);
			i++;
			j--;
		}

	}

	if (j>left) QuickSort(vt, left, j);
	if (right>i) QuickSort(vt,i,right);
}

int main()
{

	ios:: sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	vector<string> vt(N);

	for (int i=0; i<N; i++){
		cin>>vt[i];
	}

	QuickSort(vt,0,N-1);

	int dem=1;
	for (int i=1; i<N; i++){
		if (vt[i]!=vt[i-1])
			dem++;
	}
	cout<<dem;

}

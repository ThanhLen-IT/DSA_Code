#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>& a, int left, int mid, int right) {
    // TODO: trộn [left..mid] và [mid+1..right]

    vector<int> L;
    vector<int> R;
    for(int i=left; i<=mid; i++)
		L.push_back(a[i]);
	for (int i=mid+1; i<=right; i++){
		R.push_back(a[i]);
	}

	int i=0, j=0, k= left;

	while (i < L.size() && j < R.size()){
		if (L[i] < R[j]){
			a[k++]=L[i++];
		}else{
			a[k++]=R[j++];
		}
	}

	while (i<L.size()) a[k++]=L[i++];
	while (j<R.size()) a[k++]=R[j++];
}

void MergeSort(vector<int>& a, int left, int right) {
    // TODO

    if (left<right){
		int mid = left + (right-left)/2;

		MergeSort(a,left,mid);
		MergeSort(a,mid+1,right);

		Merge(a,left,mid,right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    MergeSort(a, 0, n - 1);

    for (int x : a)
        cout << x << " ";
    return 0;
}

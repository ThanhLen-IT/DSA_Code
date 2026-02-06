#include <iostream>
#include <vector>
using namespace std;



void QuickSort(vector<int>& a, int left, int right) {
    if (left >= right) return;

    int mid = left + (right-left)/2;
    int pivot = a[mid];

    int i=left,j=right;
    while(i<=j){
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;

		if(i<=j){
			swap(a[i],a[j]);
			i++; j--;
		}
    }

    if (left < j) QuickSort(a,left,j);
    if (i < right) QuickSort(a,i,right);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    QuickSort(a, 0, n - 1);

    for (int x : a)
        cout << x << " ";
    return 0;
}

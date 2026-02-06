/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;


//###INSERT CODE HERE -

void quickSort(int* a, int left, int right) {

	if (left >= right) return;
	int mid = (left + right) / 2;
	int pivot = a[mid];

	int i = left, j = right;
	while (i <= j) {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;

		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	quickSort(a, left, j);
	quickSort(a, i, right);
}

bool searchBinary(int* a, int n, int x) {
	int left = 0, right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		int pivot = a[mid];

		if (pivot == x)
			return true;
		if (x < pivot)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return false;
}


int main() {
	int N, Q;
	cin >> N >> Q;
	int* a = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	quickSort(a, 0, N - 1);
	for (int i = 0; i < Q; i++) {
		int x;
		cin >> x;
		if (searchBinary(a,N, x))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
#include <iostream>
using namespace std;


//###INSERT CODE HERE -

void inputArray(int* a, int n) {
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void outputArray(int* a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
void swap(int& a, int& b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void countOnQuickSort(int* a, int left, int right, int& countS) {
	int x = a[(left + right) / 2];
	int i = left, j = right;

	while (i <= j) {
		while (a[i] > x) i++;   
		while (a[j] < x) j--;

		if (i <= j) {
			swap(a[i], a[j]);
			countS++;
			i++;
			j--;
		}
	}

	if (left < j)  countOnQuickSort(a, left, j, countS);
	if (i < right) countOnQuickSort(a, i, right, countS);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int n, countS = 0; cin >> n;
	int* a = new int[n];
	inputArray(a, n);
	countOnQuickSort(a, 0, n - 1, countS);
	cout << "Sorted Array: ";
	outputArray(a, n);
	cout << "\nNumber of times to swap 2 numbers: " << countS;
}
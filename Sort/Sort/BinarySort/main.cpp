#include <iostream>
using namespace std;



int BinarySort(int* a, int left, int right, int x) {
	int count = 0;
	while (left <= right) {
		
		count++;
		int mid = (left + right) / 2;
		if (x == a[mid]) {
			cout << mid <<endl<<count;
			return mid;
		}
		if (x > a[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
		
	}
	
	return -1;
}

int main()
{
	int n,x,count =0; 
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;
	if (BinarySort(a, 0, n - 1, x) == -1) {
		cout << -1;
	}
	return 0;
}
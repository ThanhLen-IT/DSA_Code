/*Yêu cầu: Hãy cài đặt thuật toán sắp selection sort để sắp xếp lại mảng có N phần tử. Trong lúc chạy thuật toán, nếu xảy ra hành động swap 2 phần tử khác nhau, hãy in ra mảng sau hành động swap đó. Bằng cách này, các bạn có thể hình dung được cách hoạt động của thuật toán sắp xếp.

Input:

Dòng đầu tiên là số nguyên N dương (0 < N < 200)

Dòng tiếp theo chứa N số nguyên Ai là các phần tử của mảng

Output:

Các dòng tiếp theo in ra cấu hình của mảng A mỗi lần mảng A xảy ra hành động swap.*/

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> vt) {
	for (int i = 0; i < vt.size(); i++) {
		cout << vt[i] << " ";
	}
	cout << endl;
}

void selectionSort(vector <int> & vt) {
	for (int i = 0; i < vt.size()-1; i++) {
		int minIdx = i;
		for (int j=i+1; j < vt.size(); j++) {
			if (vt[minIdx] > vt[j]) {
				minIdx = j;
			}
		}
		if (minIdx != i) {
			swap(vt[minIdx], vt[i]);
			printVector(vt);
		}
	}
}

int main() {

	int n,x;
	cin >> n;
	vector<int> vt;
	for (int i = 0; i < n; i++) {
		cin >> x;
		vt.push_back(x);
	}

	selectionSort(vt);


	return 0;
}
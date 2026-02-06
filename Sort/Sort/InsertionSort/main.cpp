/*Yêu cầu: Hãy cài đặt thuật toán sắp xếp chèn để sắp xếp lại mảng có N phần tử. Trong lúc chạy thuật toán, nếu xảy ra hành động "dời chỗ", hãy in ra mảng sau hành động "dời chỗ" đó. Bằng cách này, các bạn có thể hình dung được cách hoạt động của thuật toán sắp xếp.

Input:

Dòng đầu tiên là số nguyên N dương (0 < N < 200)

Dòng tiếp theo chứa N số nguyên Ai là các phần tử của mảng

Output:

Các dòng tiếp theo in ra cấu hình của mảng A mỗi lần mảng A xảy ra hành động "dời chỗ".*/

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vt) {
	for (int i = 0; i < vt.size(); i++) {
		cout << vt[i] << " ";
	}
	cout << endl;
}

void insertionSort(vector<int>& vt) {
	for (int i = 1; i < vt.size(); i++) {
		int x = vt[i]; 
		int j;
		for (j = i - 1; j >= 0 && x < vt[j]; j--) {
			vt[j + 1] = vt[j];
			printVector(vt);
		}
		
		vt[j + 1] = x;
		printVector(vt);

	}
}

int main() {

	int x, n;
	cin >> n;
	vector<int> vt;
	for (int i = 0; i < n; i++) {
		cin >> x;
		vt.push_back(x);
	}

	insertionSort(vt);

	return 0;
}
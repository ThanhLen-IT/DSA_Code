#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> vt) {
	for (int i = 0; i < vt.size(); i++) {
		cout << vt[i] << " ";
	}
	cout << endl;
}

void bubbleSort(vector <int>& vt) {
	for (int i = 0; i < vt.size(); i++) {
		for (int j = 0 ; j < vt.size()-1; j++) {
			if (vt[j] > vt[j+1]) {
				swap(vt[j+1], vt[j]);
				printVector(vt);
			}
		}
	}
}

int main() {

	int n, x;
	cin >> n;
	vector<int> vt;
	for (int i = 0; i < n; i++) {
		cin >> x;
		vt.push_back(x);
	}

	bubbleSort(vt);


	return 0;
}
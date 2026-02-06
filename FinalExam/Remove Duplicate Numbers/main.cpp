#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	unordered_set<int> s;
	vector<int> vt(n);
	for (int i = 0; i < n; i++) {
		cin >> vt[i];
	}

	for (int x : vt) {
		cout << x << " ";
	}
	cout << "\nAfter removing the duplicate elements:\n";
	for (int i = 0; i < vt.size(); i++) {
		
		if (s.find(vt[i]) == s.end()) {
			cout << vt[i] << " ";
			s.insert(vt[i]);
		}
	}
}
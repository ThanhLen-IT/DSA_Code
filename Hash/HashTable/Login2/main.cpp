#include <iostream>
#include <set>
#include <map>

using namespace std;


void inputMap(map<string, multiset<string>>& mp, int N) {
	for (int i = 0; i < N; i++) {
		cin.ignore();
		string a, b;
		cin >> a >> b;
		mp[a].insert(b);
	}
}

int main() {
	int N, Q;
	cin >> N >> Q;
	map<string, multiset<string>> mp;

	inputMap(mp, N);
	
	for (int i = 0; i < Q; i++) {
		string x;
		cin >> x;
		if (mp.count(x)) {
			for (auto x : mp[x])
				cout << x << " ";
		}
		else
		{
			cout << "Chua Dang Ky!";
		}
	}


}
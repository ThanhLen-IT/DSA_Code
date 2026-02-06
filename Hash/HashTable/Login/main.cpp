#include <iostream>
#include <map>
#include <sstream>

using namespace std;




int main() {
	int N, Q;
	cin >> N >> Q;
	map<string,string> mp;

	for (int i = 0; i < N; i++) {
		cin.ignore();
		string a, b;
		cin >> a >> b;
		mp.insert({ a,b });
	}


	for (int i = 0; i < Q; i++) {
		string x;
		cin >> x;
		if (mp.find(x) != mp.end()) {
			cout << mp[x] << endl;
		}
		else {
			cout << "Chua Dang Ky!";
		}
	}

}
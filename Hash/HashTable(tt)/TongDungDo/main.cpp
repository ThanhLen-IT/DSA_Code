#include <iostream>
#include <map>

using namespace std;



int main() {
	int M, n;
	cin >> M >> n;
	map<int, int> mp;
	int count = 0;;
	for (int i = 0; i < n; i++) {
		int key; cin >> key;
		int index = key % M;
		if (!mp.count(index))
		{
			mp[index] = key;
		}
		else
		{
			int j = 0;
			while (mp.size() != M && j != M ) {
				j++;
				index = (index + j) % M;
				if (!mp.count(index)) {
					mp[index] = key;
					break;
				}

			}
			count += j;
		}
	}
	cout << count;
}
#include <iostream>
using namespace std;

int SoCCConThieu(char* a, int n) {
    int T[26] = { 0 };

    for (int i = 0; i < n; i++) {
        if (isalpha(a[i])) {   
            char c = toupper(a[i]);
            T[c - 'A']++;
        }
    }

    int dem = 0;
    for (int i = 0; i < 26; i++) {
        if (T[i] == 0)
            dem++;
    }

    return dem;
}

int main() {
	int n;
	cin >> n;
	char* a = new char[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << SoCCConThieu(a, n);
	return 0;
}
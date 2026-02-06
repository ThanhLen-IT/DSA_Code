#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n;
    vector<int> vt1;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vt1.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        while (vt1[i] >= 0 && vt1[i] < n && vt1[i] != vt1[vt1[i]]) {
            swap(vt1[i], vt1[vt1[i]]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (vt1[i] != i) {
            cout << i;
            return 0;
        }
    }
    cout << n;
    return 0;
}

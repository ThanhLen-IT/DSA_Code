#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, int left, int mid, int right) {
    vector<int> L, R;
    for (int i = left; i <= mid; i++) L.push_back(a[i]);
    for (int i = mid + 1; i <= right; i++) R.push_back(a[i]);

    int i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < L.size()) a[k++] = L[i++];
    while (j < R.size()) a[k++] = R[j++];
}

void mergeSort(vector<int>& a, int left, int right, int n) {
    if (left >= right) return;
    int mid = (left + right) / 2;

    mergeSort(a, left, mid, n);
    mergeSort(a, mid + 1, right, n);
    merge(a, left, mid, right);
    for (int i = 0; i < n; i++) {
        if (i == left) cout << "[ ";
        cout << a[i] << " ";
        if (i == right) cout << "] ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    mergeSort(a, 0, n - 1, n);

}

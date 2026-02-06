#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int>& a) {
    // TODO: bubble sort tăng dần
    int N=a.size();

    for (int i=0; i<N-1; i++ ){
		for (int j=0; j < N-i-1; j++){
			if (a[j] > a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    BubbleSort(a);

    for (int x : a)
        cout << x << " ";
    return 0;
}

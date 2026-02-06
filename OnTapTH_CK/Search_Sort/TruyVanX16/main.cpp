#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void searchB(const vector<int> &vt, int x){
	int left = 0;
	int right = vt.size()-1;

	while (left<=right){
		int mid = left + (right-left)/2;

		if (x == vt[mid]){
			cout<<"YES\n";
			return;
		}
		if ( x < vt[mid]){
			right = mid-1;
		}else{
			left = mid +1;
		}
	}

	cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	int N,Q;
	cin>>N>>Q;
	vector<int> vt(N);
    for (int i = 0; i < N; i++) {
        cin >> vt[i];
    }

    sort(vt.begin(),vt.end());

	for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        searchB(vt, x);
    }
}


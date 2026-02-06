#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void input(vector<int> &vt, int N) {
    vt.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> vt[i];
    }
}

void solve(const vector<int> &vt, int Q) {
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;

		int left=0;
		int right=vt.size()-1;
		int ans=-1;
		while (left<= right){
			int mid = left + (right-left)/2;

			if (vt[mid] > x){
				ans=vt[mid];
				right = mid -1;
			}else{
				left=mid+1;
			}

		}

		cout<<ans<<"\n";
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<int> vt;
    input(vt, N);


    sort(vt.begin(), vt.end());
    //sort(vt.begin(), vt.end(), greater<int>());

    solve(vt, Q);

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& vt, int left, int mid, int right)
{
	vector<int> a;
	vector<int> b;
	for (int i=left; i<=mid; i++){
		a.push_back(vt[i]);
	}
	for (int i=mid+1; i<=right; i++){
		b.push_back(vt[i]);
	}

	int na = 0, nb=0, k=left;

	while(na<a.size() && nb<b.size()){
		if (a[na] < b[nb]){
			vt[k++]=a[na++];

		}else{
			vt[k++]=b[nb++];
		}
	}

	while (na < a.size()) vt[k++] = a[na++];
	while (nb < b.size()) vt[k++] = b[nb++];
}

void mergeSort(vector<int>& vt, int left, int right, int N){
	if (left < right){
		int mid = (left+right)/2;

		mergeSort(vt,left,mid,N);
		mergeSort(vt,mid+1,right,N);

		merge(vt,left,mid,right);

		for (int i=0; i<N; i++){
			if (i == left){
				cout<<"[ "<<vt[i]<<" ";
			}else{
				if (i==right){
					cout <<vt[i]<<" ] ";
				}else{
					cout <<vt[i]<<" ";
				}
			}

		}
		cout<<"\n";
	}

}




int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin>>N;

	vector<int> vt(N);

	for(int i=0; i<N; i++)
	{
		cin>>vt[i];
	}

	mergeSort(vt,0,N-1, N);

}

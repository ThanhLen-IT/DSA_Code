#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& vt){
	int N=vt.size();
	for (int i=0; i<N-1; i++){
		int minId=i;
		for (int j=i+1; j<N; j++){
			if (vt[j]<vt[minId]){
				minId=j;
			}
		}
		if (minId != i) {
			swap(vt[i],vt[minId]);
			for (int z =0; z<N; z++){
				cout<<vt[z]<<" ";
			}
			cout<<"\n";
		}
	}
}


int main()
{
    int N; cin>>N;

    vector<int> vt(N);
    for (int i=0; i<N; i++){
		cin>>vt[i];
    }

    selectionSort(vt);
}

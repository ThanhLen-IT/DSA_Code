#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> vt){
	for (int i=0; i<vt.size(); i++){
		cout<<vt[i]<<" ";
	}
	cout<<"\n";
}

void insertionSort(vector<int> &vt){
	int n= vt.size();

	for (int i=1; i<n; i++){
		int key = vt[i];
		int j=i-1;

		while (j>=0 && key < vt[j]){
			vt[j+1]= vt[j];

			print(vt);
			j--;
		}

		vt[j+1]=key;
		print(vt);

	}


}

int main()
{
	int N; cin>>N;
	vector<int> vt(N);

	for (int i=0; i<N; i++){
		cin>>vt[i];
	}


	insertionSort(vt);


}

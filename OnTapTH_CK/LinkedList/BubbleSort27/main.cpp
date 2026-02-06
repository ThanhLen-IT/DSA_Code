#include <iostream>
#include <vector>

using namespace std;


void BubbleSort(vector<int> &A){

	int N=A.size();

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);


                for (int k = 0; k < N; k++) {
                    cout << A[k] << " ";
                }
                cout << endl;
            }
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


	BubbleSort(vt);


}

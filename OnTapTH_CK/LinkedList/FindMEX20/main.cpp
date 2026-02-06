/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
set
nth_element
priority_queue
sort_heap
multiset
map
multimap
###End banned keyword*/
//###INSERT CODE HERE -

#include <iostream>
#include <vector>

using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin>>N;
	vector <bool> vt(N+1);

	for (int i=0; i<N; i++){
		int x; cin>>x;
		if( x >= 0 && x <= N){
			vt[x]=true;
		}
	}

	for(int i=0; i<= N; i++){
		if (!vt[i]){
			cout << i ;
			return 0;
		}
	}

	return 0;
}

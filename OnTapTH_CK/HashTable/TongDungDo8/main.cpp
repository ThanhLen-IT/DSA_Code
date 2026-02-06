#include <iostream>
#include <vector>

using namespace std;

struct hashTable{
	int M;
	int n;
	vector<int> table;
};

void createHashTable(hashTable & ht, int M){
	ht.M=M;
	ht.n=0;
	for (int i=0; i<M; i++){
		ht.table.push_back(-1);
	}
}

int Hash(hashTable ht, int key){
	return key % ht.M;
}

int iHash(hashTable ht, int key, int i){
	return (Hash(ht,key) + i) % ht.M;
}


void insertHashTable(hashTable &ht,int x,int &dem){

	int index = Hash(ht,x);
	int i=0;
	while (ht.table[index] != -1){
		i++;
		dem++;
		index = iHash(ht,x,i);
	}

	ht.table[index] = x;
	ht.n++;
}

int main()
{
	int M, n;
	cin>>M>>n;

	hashTable ht;
	createHashTable(ht,M);

	int dem =0;
	for (int i=0; i<n; i++){
		int x; cin>>x;
		insertHashTable(ht,x,dem);
	}
	cout<<dem;

}

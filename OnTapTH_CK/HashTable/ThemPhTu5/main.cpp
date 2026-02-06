#include <iostream>
#include <vector>
using namespace std;

struct hashTable{
	int n;
	int M;
	vector<vector<int>> table;
};

void createHashTable(hashTable &ht,int M){
	ht.n=0;
	ht.M=M;
	ht.table.resize(M);
}

int Hash(int key, int M){
	return key % M;
}

void insertHashTable(hashTable &ht, int x, double LOAD){
	if (double(ht.n+1)/ht.M > LOAD)
		return;

	int index = Hash(x,ht.M);

	ht.table[index].push_back(x);
	ht.n++;
}

void findKey(const hashTable& ht, int key){
	int index = Hash(key,ht.M);

	for (int i=0; i< ht.table[index].size(); i++){
		if (ht.table[index][i] == key ){
			cout<<i+1<<"\n";
			return;
		}
	}

	cout<<"KHONG\n";
}

int main()
{
    int N,M;
    double LOAD;
    cin>>M>>LOAD>>N;

    hashTable ht;
    createHashTable(ht,M);

    for (int i=0; i<N; i++){
		int x; cin>>x;
		insertHashTable(ht,x,LOAD);
    }


    int Q; cin>>Q;
    for (int i=0; i<Q; i++){
		int x; cin>>x;
		findKey(ht,x);
    }

    return 0;
}

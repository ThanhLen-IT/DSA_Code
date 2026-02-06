#include <iostream>
#include <vector>

using namespace std;

struct hashTable {
    int M;
    vector<int> table;
    vector<int> cnt;

    hashTable(int m) : M(m), table(m, -1), cnt(m, 0) {}
};


int Hash(const hashTable &ht, int key) {
    return key % ht.M;
}


void insertHashTable(hashTable &ht, int x, int &maxCollisions) {
    int h_key = Hash(ht, x);
    int i = 0;
    int index = h_key;


    while (ht.table[index] != -1 && i < ht.M) {
        ht.cnt[index]++;

        if (ht.cnt[index] > maxCollisions) {
            maxCollisions = ht.cnt[index];
        }
        i++;
        index = (h_key + i) % ht.M;
    }

    if (i < ht.M) {
        ht.table[index] = x;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, M;
    if (!(cin >> n >> M)) return 0;

    hashTable ht(M);
    int maxCollisions = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertHashTable(ht, x, maxCollisions);
    }

    if (maxCollisions > 0) {
        for (int i = 0; i < M; i++) {
            if (ht.cnt[i] == maxCollisions) {
                cout << i<<" ";
            }
        }
    }

    return 0;
}

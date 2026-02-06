#include <iostream>
#include <vector>
using namespace std;

#define M 10
#define NULLKEY -1

struct Hash {
    int hashtable[M];
    int n;
};

int hashfunc(int key) {
    return key % M;
}

int hashAgain(int key, int j) {
    return (hashfunc(key) + j * j + j) % M;
}

void initHash(Hash& H) {
    for (int i = 0; i < M; i++) H.hashtable[i] = NULLKEY;
    H.n = 0;
}

bool isHashFull(Hash H) {
    return H.n == M;
}

int insertHash(Hash& H, int key) {
    if (isHashFull(H)) return -1;
    int i = hashfunc(key);
    int j = 0;
    while (H.hashtable[i] != NULLKEY) {
        j++;
        if (j >= M) return -1;
        i = hashAgain(key, j);
    }
    H.hashtable[i] = key;
    H.n++;
    return i;
}

void traverseAllHash(Hash H) {
    for (int i = 0; i < M; i++)
        cout << i << " -> " << H.hashtable[i] << endl;
}

int main() {
    Hash H;
    initHash(H);
    vector<int> b;

    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        int k = insertHash(H, x);
        if (k == -1) b.push_back(x);
    }

    cout << "\nBang bam:" << endl;
    traverseAllHash(H);
    if (!b.empty())
        cout << "Co " << b.size() << " gia tri khong them duoc" << endl;

    return 0;
}

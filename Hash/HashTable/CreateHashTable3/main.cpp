/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
->
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
#define M 10		// M là số nút có trên bảng băm, đủ để chứa các nút nhập vào bảng băm
#define NULLKEY -1
using namespace std;

//###INSERT CODE HERE -

struct Hash {
    
    int hashTable[M];
    int N;
};
void initHash(Hash& H) {
    for (int i = 0; i < M; i++) {
        H.hashTable[i] = NULLKEY;
    }
    H.N = 0;
}

bool isHashFull(Hash H) {
    return (H.N == 10) ? true : false;
}

int hashfunc(int key) {
    return key % M;
}

void insertHash(Hash& H, int key) {
    if (isHashFull(H)) {
        cout << "\nBang bam bi day, khong them duoc";
        return;
    }
    int i = hashfunc(key);
    while (H.hashTable[i] != NULLKEY) {
        i++;
        if (i == M) i = 0;
    }
    H.hashTable[i] = key;
    H.N++;
}

void traverseAllHash(Hash H) {
    for (int i = 0; i < M; i++) {
        cout << H.hashTable[i] << " ";
    }
}
int main()
{
    Hash H;
    initHash(H);

    int n, x;cin >> n; // n la so luong gia tri can phai luu tru
    for (int i = 1; i <= n;i++)
    {
        cin >> x;
        cout << "\nInsert " << x;
        insertHash(H, x); // them 1 gia tri du lieu vao bang bam
    }
    cout << "\nCreated Hash:" << endl;
    traverseAllHash(H);

    return 0;
}



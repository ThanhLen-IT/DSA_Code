#include <iostream>
#include <vector>
using namespace std;



void countIn(vector<int>& count, int n, int M) {
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        int addr = key % M;
        count[addr]++;
    }
}

void printResult(vector<int> count) {
    int maxDungDo = -1;
    for (int i = 0; i < count.size(); i++) {
        if (count[i] >= 2) {
            maxDungDo = max(maxDungDo, count[i]);
        }
    }

    for (int i = 0; i < count.size(); i++) {
        if (count[i] == maxDungDo)
            cout << i << endl;
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, M, x;
    cin >> n >> M;
    vector<int> count(M, 0);

    countIn(count, n, M);

    printResult(count);



    return 0;
}

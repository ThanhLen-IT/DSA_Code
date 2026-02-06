#include <iostream>
#include <vector>
using namespace std;

void input(vector<int>& count, vector<bool>& collision, int n, int m) {
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        int addr = key % m;
        if (count[addr] > 0) {
            collision[i] = true;
        }
        else
           count[addr]++;
        
    }
}

void printResult(vector<bool>& collision, int n) {
    int count = 0;
    for (int i = 0; i < collision.size(); i++) {
        if (collision[i]) count++;
    }


    double ratio = double(count) / collision.size();
    if (ratio > 0.33) 
        cout << "BAD";
    else 
        cout << "GOOD";
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> count(m, 0);
    vector<bool> collision(n, false);

    input(count, collision, n, m);
    printResult(collision, n);
    return 0;
}

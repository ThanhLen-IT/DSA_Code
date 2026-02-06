/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
new
###End banned keyword*/

#include <iostream>

//###INSERT CODE HERE -

using namespace std;
void insertArray(int* a, int n, int x) {
    int i = 0;
    while (i < n && a[i] != -1 && a[i] < x) {
        i++;
    }
    for (int j = n; j > i; j--) {
        a[j] = a[j - 1];
    }
    a[i] = x;
}

int main() {
    int n, x;
    cin >> n;
    int chan[10000 + 1], le[10000 + 1];
    for (int i = 0; i <= n; i++) {
        chan[i] = -1;
        le[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 0) insertArray(chan, n, x);
        else insertArray(le, n, x);
    }

    int i = 0;
    while (chan[i] != -1) {
        cout << chan[i] << endl;
        i++;
    }
    i = 0;
    while (le[i] != -1) {
        cout << le[i] << endl;
        i++;
    }
}
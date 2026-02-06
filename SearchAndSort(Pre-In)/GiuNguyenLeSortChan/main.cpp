/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

void quickSort(int* b, int* c, int left, int right) {
    int x = b[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (b[i] < x) i++;
        while (b[j] > x) j--;

        if (i <= j) {
            swap(b[i], b[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(b, c, left, j);
    if (i < right) quickSort(b, c, i, right);
}

void sortArray(int* a, int n) {
    int* b = new int[n];
    int* c = new int[n];
    int nb = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            b[nb] = a[i];
            c[nb] = i;
            nb++;
        }
    }


    if (nb > 0) quickSort(b, c, 0, nb - 1);


    
    for (int i = 0; i < nb; i++) {
        a[c[i]] = b[i];
    }

    delete[] b;
    delete[] c;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int* a;
    int n; 
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sortArray(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

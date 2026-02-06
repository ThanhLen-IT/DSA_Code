/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>

using namespace std;

void QuickSort(int [] , int, int);

int main()
{
    int *ls = NULL;
    int n;
    cin >> n;
    ls = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> ls[i];
    }
    QuickSort(ls, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << ls[i] << ' ';
    }
    delete [] ls;
    return 0;
}

void QuickSort(int ls[], int b, int e) {

//###INSERT CODE HERE -
	 while (b < e) {
        int i = b, j = e;
        int m = (b + e) / 2;

        // median-of-three
        int p;
        if (ls[b] > ls[m]) swap(ls[b], ls[m]);
        if (ls[b] > ls[e]) swap(ls[b], ls[e]);
        if (ls[m] > ls[e]) swap(ls[m], ls[e]);
        p = ls[m];

        while (i <= j) {
            while (ls[i] < p) i++;
            while (ls[j] > p) j--;
            if (i <= j) {
                swap(ls[i], ls[j]);
                i++; j--;
            }
        }

        // sort mảng nhỏ trước
        if (j - b < e - i) {
            if (b < j) QuickSort(ls, b, j);
            b = i;
        } else {
            if (i < e) QuickSort(ls, i, e);
            e = j;
        }
    }

}

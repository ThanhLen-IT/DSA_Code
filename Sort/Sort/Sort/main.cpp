#include <iostream>
using namespace std;

//Quick Sort


void quickSort(int a[], int l, int r) {
    int x = a[(l + r) / 2];
    int i = l, j = r;

    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}


int main() {
	
}
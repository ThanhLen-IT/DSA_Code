/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
multiset
map
unordered_map
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;


//###INSERT CODE HERE -

void quickSort(vector<int>& v, int left, int right) {
    int i = left;
    int j = right;
    int x = v[(left + right) / 2];

    while (i <= j) {
        while (v[i] < x) i++;
        while (v[j] > x) j--;

        if (i <= j) {
            int t = v[i]; v[i] = v[j]; v[j] = t;
            i++;
            j--;
        }
    }

    if (left < j) quickSort(v, left, j);
    if (i < right) quickSort(v, i, right);
}


int MEX(vector<int> v, int i) {
    vector<int> t;

    for (int k = 0; k <= i; k++)
        t.push_back(v[k]);

    
    quickSort(t, 0, t.size() - 1);

    
    if (t[0] != 0) return 0;

    for (int k = 0; k < t.size() - 1; k++) {
        if (t[k + 1] != t[k] + 1)
            return t[k] + 1;
    }

 
    return t.back() + 1;
}

void printMEX(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << MEX(v, i) << " ";
    }
}

int main() {
	int n, x;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	printMEX(v);
	return 0;
}
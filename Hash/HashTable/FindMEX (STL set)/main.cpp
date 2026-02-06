/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
map
vector
###End banned keyword*/


#include<set>
#include<iostream>
using namespace std;

int main()
{
    set<int> b;
    //###INSERT CODE HERE -

    int n,x;
    cin >> n;
    set<int>::iterator it;
    for (int i = 0; i < n; i++) {
        cin >> x;
        b.insert(x);
    }

    int mex = 0;

    for (it = b.begin(); it != b.end(); ++it) {
        if (mex != *it) {
            cout << mex;
            return 0;
        }
        mex++;
    }

    cout << mex;
    return 0;

}




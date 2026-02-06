/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
set
vector
###End banned keyword*/


#include <map>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;

    map<int, bool> mp;
    for (int i = 0; i < n; i++) {
        cin >> x;
        mp[x] = true;
    }

    int mex = 0;


    for (auto it : mp) {
        if (mex != it.first) {
            cout << mex;
            return 0;
        }
        mex++;
    }

    cout << mex;

    return 0;
}

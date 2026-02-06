/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
map
set
[
]
###End banned keyword*/


#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{

    //###INSERT CODE HERE -
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n,x;
    cin >> n;
    vector<int> vt;
    for (int i = 0; i < n; i++) {
        cin >>x;
        vt.push_back(x);
    }

    sort(vt.begin(), vt.end());
    vt.erase(unique(vt.begin(), vt.end()), vt.end());
    
    if (vt.at(0) != 0) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < vt.size() - 1; i++) {
        if (vt.at(i) + 1 != vt.at(i + 1)) {
            cout << vt.at(i) + 1;
            return 0;
        }
    }

    cout << vt.back() + 1;
    return 0;

}




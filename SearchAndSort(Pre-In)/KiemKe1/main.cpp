/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
set
map
multi_set
unordered_map
merge
[
]
###End banned keyword*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//###INSERT CODE HERE -
int countUniqueItems(vector<string>& items) {
    vector<string> seen;  // lưu những mã đã gặp
    int count = 0;

    for (vector<string>::iterator it = items.begin(); it != items.end(); ++it) {
        bool isDuplicate = false;
        for (vector<string>::iterator jt = seen.begin(); jt != seen.end(); ++jt) {
            if (*it == *jt) {
                isDuplicate = true; 
                break;
            }
        }
        if (!isDuplicate) {
            seen.push_back(*it);  
            count++;              
    }

    return count;
}

int main() 
{
    int N;
    cin >> N;
    cin.ignore();  

    vector<string> items;
    for (int i = 0; i < N; i++) {
        string code;
        cin >> code;
        items.push_back(code);
    }

    int result = countUniqueItems(items);
    cout << result << endl;

    return 0;
}

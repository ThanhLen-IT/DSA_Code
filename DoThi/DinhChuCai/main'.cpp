/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Graph {
    vector<vector<int>> Matrix;
    vector<string> Dinh;
    map<string, int> toIndex;

public:
    void nhap(int v, int e) {
        Matrix.assign(v, vector<int>(v, 0));

        // Nhập tên đỉnh
        string x;
        for (int i = 0; i < v; i++) {
            cin >> x;
            Dinh.push_back(x);
            toIndex[x] = i;
        }

        // Nhập cạnh
        string u, vtx;
        for (int i = 0; i < e; i++) {
            cin >> u >> vtx;
            Matrix[toIndex[u]][toIndex[vtx]] = 1;  // KHÔNG TRỪ 1
        }
    }

    // Tìm tên đỉnh từ index
    string getKeyByValue(int value) {
        for (auto& p : toIndex) {
            if (p.second == value)
                return p.first;
        }
        return "";
    }

    void myProcess(int n) {
        int loai;
        for (int i = 0; i < n; i++) {
            cin >> loai;

            if (loai == 1) {
                string u, vtx;
                cin >> u >> vtx;
                if (Matrix[toIndex[u]][toIndex[vtx]])
                    cout << "TRUE";
                else
                    cout << "FALSE";
            }
            else if (loai == 2) {
                string u;
                cin >> u;
                int idx = toIndex[u];

                bool found = false;
                for (int j = 0; j < Dinh.size(); j++) {
                    if (Matrix[idx][j] == 1) {
                        if (found) cout << " ";
                        cout << getKeyByValue(j);
                        found = true;
                    }
                }

                if (!found) cout << "NONE";
            }

            cout << endl;
        }
    }
};

int main() {
    Graph G;
    int v, e, n;
    cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}

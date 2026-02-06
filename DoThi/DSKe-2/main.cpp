#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Graph {
    int e;
    map<string, set<string>> adj_list;

public:
    Graph(int edges) : e(edges) {}

    void inputGraph() {
        string x, y;
        for (int i = 0; i < e; i++) {
            cin >> x >> y;
            adj_list[y];           
            adj_list[x].insert(y);
        }
    }



    void process(int n) {
        int x;
        string u, v;
        for (int i = 0; i < n; i++) {
            cin >> x;
            switch (x) {
            case 1:
                cin >> u >> v;
                if (adj_list[u].count(v)) {
                    cout << "TRUE" << endl;
                }
                else {
                    cout << "FALSE" << endl;
                }
                break;
            case 2:
                cin >> u;
                cout << adj_list[u].size() << endl;
                break;
            }
        }
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int e, n;
    cin >> e >> n;
    Graph G(e);
    G.inputGraph();
    G.process();
}

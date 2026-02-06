#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

class Graph {
    map<string, set<string>> adj;

public:
    void inputGraph(int e) {
        string u, v;
        for (int i = 0; i < e; i++) {
            cin >> u >> v;
            adj[u].insert(v); 
            adj[v]; 
        }
    }

    bool isComplete() {
        int n = adj.size();
        for (const auto& p : adj) {
            if (p.second.size() != n - 1) 
                return false;
        }
        return true;
    }
};

int main() {
    int e;
    cin >> e;
    Graph G;
    G.inputGraph(e);
    if (G.isComplete())
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
}

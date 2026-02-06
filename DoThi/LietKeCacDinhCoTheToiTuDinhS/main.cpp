#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int m, n;
vector<vector<int>> adj;   


void inputGraph() {
    cin >> m >> n;
    adj.assign(m, {}); 

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}


void process() {
    vector<int> visited(m, 0);
    queue<int> q;

    visited[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i < m; i++) {
        if (visited[i]) cout << "CO\n";
        else cout << "KHONG\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    inputGraph();
    process();

    return 0;
}
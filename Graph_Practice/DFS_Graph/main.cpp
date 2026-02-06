#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;

bool DFS(int s, int g, map<int, set<int>>& adj, vector<int>& parent, int n)
{
    stack<int> open;
    vector<bool> close(adj.size(), -1);

    parent.assign(adj.size(), -1);

    open.push(s);

    while (!open.empty()) {
        int p = open.top(); open.pop();

        if (p == g) return 1;

        if (close[p]) continue;
        close[p] = 1;
        for (int q : adj[p]) {
            if (!close[q]) {
                open.push(q);
                parent[q] = p;
            }
        }
    }
    return false;
}

void printPath(int s, int g, vector<int>& parent)
{
    vector<int> path;
    for (int v = g; v != -1; v = parent[v])
        path.push_back(v);

    cout << "\nDuong di: ";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}

int main() {
    int n, m;
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m;

    map<int, set<int>> adj;

    cout << "Nhap cac canh u v:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u); // nếu đồ thị vô hướng
    }

    int s, g;
    cout << "Nhap dinh bat dau s: ";
    cin >> s;
    cout << "Nhap dinh ket thuc g: ";
    cin >> g;

    vector<int> parent;

    if (DFS(s, g, adj, parent, n))
        printPath(s, g, parent);
    else
        cout << "Khong tim thay duong di!\n";

    return 0;
}

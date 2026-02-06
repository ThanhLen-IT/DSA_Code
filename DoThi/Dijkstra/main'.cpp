#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

int v, n;
vector<string> Dinh;
map<string, int> id;
vector<vector<int>> w;

void inputGraph() {
    cin >> v >> n;
    Dinh.resize(v);
    for (int i = 0; i < v; i++) {
        cin >> Dinh[i];
        id[Dinh[i]] = i;
    }
    w.assign(v, vector<int>(v));
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            cin >> w[i][j];
}

void dijkstra(string s, string g) {
    vector<string> Open, Close;
    map<string, int> dist;
    map<string, string> parent;

    for (int i = 0; i < v; i++)
        dist[Dinh[i]] = INT_MAX;

    Open.push_back(s);
    dist[s] = 0;

    bool found = false;
    int expanded = 0;

    while (!Open.empty()) {
        int best = 0;
        for (int i = 1; i < (int)Open.size(); i++) {
            if (dist[Open[i]] < dist[Open[best]] ||
                (dist[Open[i]] == dist[Open[best]] && id[Open[i]] > id[Open[best]])) {
                best = i;
            }
        }

        string p = Open[best];
        Open.erase(Open.begin() + best);

        if (find(Close.begin(), Close.end(), p) != Close.end())
            continue;

        expanded++; // luôn tính khi chọn p

        if (p == g) {
            found = true;
            break;
        }

        Close.push_back(p);
        int pi = id[p];

        // duyệt kề ngược
        for (int i = v - 1; i >= 0; i--) {
            if (w[pi][i] != 0) {
                string q = Dinh[i];
                if (find(Close.begin(), Close.end(), q) != Close.end())
                    continue;

                int newd = dist[p] + w[pi][i];
                auto it = find(Open.begin(), Open.end(), q);
                if (it != Open.end()) {
                    if (newd < dist[q]) {
                        dist[q] = newd;
                        parent[q] = p;
                    }
                }
                else {
                    dist[q] = newd;
                    parent[q] = p;
                    Open.push_back(q);
                }
            }
        }
    }

    if (!found) {
        cout << "-unreachable-\n";
        cout << expanded << " 0\n";
    }
    else {
        vector<string> path;
        for (string cur = g; cur != s; cur = parent[cur])
            path.push_back(cur);
        path.push_back(s);
        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i + 1 < path.size()) cout << " ";
        }
        cout << "\n";
        cout << expanded << " " << dist[g] << "\n";
    }
}

void outputResult() {
    while (n--) {
        string s, g;
        cin >> s >> g;
        dijkstra(s, g);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    inputGraph();
    outputResult();
}

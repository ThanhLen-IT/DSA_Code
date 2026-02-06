#include <iostream>
#include <vector>
using namespace std;

void inputGraph(vector<vector<int>>& G, int n) {
	G.assign(n + 1, vector<int>());

	int x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (x == 1) {
				G[i+1].push_back(j+1);
			}
		}
	}
}

void outputGraph(vector<vector<int>> G){
	for (int i = 0; i < G.size(); i++) {
		if (G[i].size() != 0) {
			cout << i<<"->";
			for (int j = 0; j < G[i].size(); j++) {
				cout << G[i][j]<<" ";
			}
			cout << endl;
		}
		
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> G;
	inputGraph(G, n);

	outputGraph(G);
}
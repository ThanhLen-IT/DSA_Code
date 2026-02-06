/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
//###INSERT CODE HERE -

#include <iostream>
#include <vector>
using namespace std;


void inputGraph(vector<vector<int>>& G, int n, int m) {
	G = vector<vector<int>>(n, vector<int>(n, 0));
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		G[x][y] = 1;
		G[y][x] = 1;
	}

}

void process(vector<vector<int>> G) {
	int count = 0;
	for (int i = 0; i < G.size(); i++) {
		int tong = 0;
		for (int j = 0; j < G[i].size(); j++) {
			tong += G[i][j];
		}
		if (tong == 0) {
			count++;
		}
	}

	cout << count;
}
int main() {
	int n, m; //n: dinh. m: canh
	cin >> n >> m;
	vector<vector<int>> G;

	inputGraph(G, n, m);
	process(G);


}
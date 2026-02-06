/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
#include<vector>
using namespace std;

//###INSERT CODE HERE -

void inputGraph(vector<vector<int> >& G, int v, int e) {
	G = vector<vector<int>>(v, vector<int>(v, 0));
	int x, y;
	for (int i = 0; i < e; i++) {
		cin >> x >> y;
		G[x - 1][y - 1] = 1;
	}
}

void process(vector<vector<int> > G, int v, int n) {
	int loai;
	//Co n thao tca xu ly
	for (int i = 0; i < n; i++) {
		cin >> loai;
		if (loai == 1) {
			int x, y;
			cin >> x >> y;
			if (G[x - 1][y - 1])
				cout << "TRUE";
			else
				cout << "FALSE";
		}
		else if (loai == 2) {
			int u;
			cin >> u;
			bool found = false;
			for (int j = 0; j < v; j++) {
				if (G[u - 1][j]) { // Kiểm tra các đỉnh nối đến u
					if (found) cout << " ";
					cout << j + 1;
					found = true;
				}
			}
			if (!found) cout << "NONE";


		}
		cout << endl;
	}
}



int main()
{

	int v, e, n;
	cin >> v >> e >> n; //v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int> > G;

	inputGraph(G, v, e);
	process(G, v, n);

	return 0;
}

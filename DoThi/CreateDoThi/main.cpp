/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
using namespace std;

void inputGraph(bool* [], int);
void process(bool* [], int, int);
void outputGraph(bool* [], int);


int main()
{
	int v, e, n; //v: số đỉnh, e: số cạnh, n: số thao tác
	cin >> v >> e >> n;

	bool** G; // ma trận toàn số 0, 1 nên kiểu bool hay int đều được
	G = new bool* [v];

	//###INSERT CODE HERE -
	//Cap phat matran
	for (int i = 0; i < v; i++) {
		G[i] = new bool[v] {0};
	}



	inputGraph(G, e);


	process(G, v, n);
}

void inputGraph(bool** G, int e ) {
	
	int x, y;
	for (int i = 0; i < e; i++) {
		cin >> x >> y;
		G[x - 1][y - 1] = 1;
	}

}

void outputGraph(bool** G, int v) {
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
}

void process(bool** G, int v, int n) {

	int loai;
	//Co n thao tca xu ly
	for (int i = 0; i < n; i++) {
		cin >> loai;
		if (loai == 1) {
			int x, y;
			cin >> x >> y;
			if (G[x-1][y-1])
				cout << "TRUE";
			else
				cout << "FALSE";
		}
		else if (loai == 2) {
			int u;
			cin >> u;
			bool found = false;
			for (int j = 0; j < v; j++) {
				if (G[u-1][j]) { // Kiểm tra các đỉnh nối đến u
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
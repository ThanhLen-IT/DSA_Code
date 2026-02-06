#include <iostream>
#include <vector>
#include <map>

using namespace std;


struct Graph {
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
            Matrix[toIndex[vtx]][toIndex[u]] = 1;
        }
    }
    int bacCuaDinh(vector<int> dinh) {
        int count = 0;
        for (int i = 0; i < dinh.size(); i++) {
            if (dinh[i] == 1) {
                count++;
            }
        }
        return count;
    }

    void printBac() {
        for (int i = 0; i < Matrix.size(); i++) {
            cout << bacCuaDinh(Matrix[i]) << " ";
        }
    }
};
int main() {
	int v, e;
	cin >> v>>e;
    Graph G;
    G.nhap(v, e);
    G.printBac();
	
}
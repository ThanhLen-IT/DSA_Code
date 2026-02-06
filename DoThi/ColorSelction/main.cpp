#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Graph {
    vector<vector<int>> Matrix;
    vector<string> Dinh;
    vector<int> Mau;
    map<string, int> toIndex;
    map<int, string> toString;
public:
    void nhap(int v, int e) {
        Matrix.assign(v, vector<int>(v, 0));

        // Nhập tên đỉnh
        string x;
        for (int i = 0; i < v; i++) {
            cin >> x;
            Dinh.push_back(x);
            toIndex[x] = i;
            toString[i] = x;
        }

        // Nhập cạnh
        string u, vtx;
        for (int i = 0; i < e; i++) {
            cin >> u >> vtx;
            Matrix[toIndex[u]][toIndex[vtx]] = 1; 
            Matrix[toIndex[vtx]][toIndex[u]] = 1;
        }
    }
    void inputMau() {
        int x;
        for (int i = 0; i < Dinh.size();i++) {
            cin >> x;
            Mau.push_back(x);
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
    int minMau()

    void toMau(int n) {
        string str;
        int dem; //luu cac mau da to; 
        for (int i = 0; i < n; i++) {
            cin >> str;
            int index = toIndex[str];

        }

    }


};


int main() {
	int v,e,n;
	cin >> v>>e;

    Graph G;
    G.nhap(v, e);
    G.inputMau();
    G.toMau(n);
}
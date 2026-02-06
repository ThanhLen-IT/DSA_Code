/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>

using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};
void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
void OutputCompact(Hocsinh hs) {
    cout << hs.Hoten << "\n";
}

void OutputFull(Hocsinh hs) {
    cout << '[' << hs.Maso << "\t" << hs.Hoten << "\t" << hs.Gioitinh << "\t" << hs.Namsinh << "\t" << hs.TBK << "]\n";
}

void QuickSort(Hocsinh [] , int, int);

int main()
{
    Hocsinh *ls = NULL;
    int n;
    cin >> n;
    ls = new Hocsinh[n];
    for (int i = 0; i < n; i++) {
        Input(ls[i]);
    }
    QuickSort(ls, 0, n-1);
    for (int i = 0; i < n; i++) {
        OutputCompact(ls[i]);
    }
    delete [] ls;
    return 0;
}

void QuickSort(Hocsinh ls[], int b, int e) {

	while (b<=e){
		int i=b, j=e;
		int mid= (i+j)/2;
		Hocsinh pivot;
		if (ls[b].Hoten > ls[mid].Hoten) swap(ls[b],ls[mid]);
		if (ls[b].Hoten > ls[e].Hoten) swap(ls[b],ls[mid]);
		if (ls[mid].Hoten > ls[e].Hoten) swap(ls[mid],ls[e]);
		pivot = ls[mid];
		while (i<=j){
			while (ls[i].Hoten < pivot.Hoten) i++;
			while (ls[j].Hoten > pivot.Hoten) j--;

			if (i<=j){
				swap(ls[i],ls[j]);
				i++;
				j--;
			}
		}

		if (j-b < e-i){
			QuickSort(ls,b,j);
			b=i;
		}else{
			QuickSort(ls,i,e);
			e=j;
		}
	}

}

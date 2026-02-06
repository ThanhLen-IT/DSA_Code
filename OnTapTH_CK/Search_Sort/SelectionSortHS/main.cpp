/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;;
}

void Output(vector<Hocsinh> ls, int n) {
    cout << n << endl;
    for (int i = 0; i < ls.size(); i++) {
        OutputElement(ls[i]);
    }
}

void Input(vector<Hocsinh> &ls) {
    int n;
    cin >> n;
    Hocsinh hs;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        ls.push_back(hs);
    }
}

int SelectionSort(vector<Hocsinh> &ls);

int main()
{
    vector<Hocsinh> ls;
    Input(ls);
    int n = SelectionSort(ls);
    Output(ls, n);
    return 0;
}

//###INSERT CODE HERE -

bool nhoHon(Hocsinh a, Hocsinh b){
	if (a.Ten != b.Ten) return a.Ten<b.Ten;
	return a.Hodem<b.Hodem;
}



int SelectionSort(vector<Hocsinh> &ls){
	int dem=0;
	int n = ls.size();
	for(int i=0; i<n-1; i++){
		int minId = i;
		for(int j=i+1; j<n; j++){
			if (nhoHon(ls[j],ls[minId])){
				minId = j;
			}
		}
		if (nhoHon(ls[minId],ls[i])){
			dem++	;
			swap(ls[i],ls[minId]);
		}
	}
	return dem;
}

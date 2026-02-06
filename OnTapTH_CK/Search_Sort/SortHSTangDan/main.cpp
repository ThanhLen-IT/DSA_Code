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

void Output(vector<Hocsinh> ls) {
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

void Sort(vector<Hocsinh> &ls);

int main()
{
    vector<Hocsinh> ls;
    Input(ls);
    Sort(ls);
    Output(ls);
    return 0;
}

//###INSERT CODE HERE -
bool dungTruoc(Hocsinh a, Hocsinh b){
	double DTBa = (a.Toan + a.Ly + a.Hoa + a.Sinh + a.Anh + a.Van)/6;
	double DTBb = (b.Toan + b.Ly + b.Hoa + b.Sinh + b.Anh + b.Van)/6;

	if (DTBa != DTBb) return DTBa > DTBb;
	if (a.Nam != b.Nam) return a.Nam > b.Nam;
	if (a.Thang != b.Thang) return a.Thang>b.Thang;
	return a.Ngay > b.Ngay;
}

void Sort(vector<Hocsinh> &ls){
	for (int i=0; i<ls.size(); i++){
		Hocsinh p= ls[i];
		int j=i-1;
		while (j>=0 && dungTruoc(p,ls[j])){
			ls[j+1] = ls[j];
			j--;
		}
		ls[j+1]=p;
	}
}

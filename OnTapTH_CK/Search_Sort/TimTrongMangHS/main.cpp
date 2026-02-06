/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>

#define MAX 10000

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

int BSearch(Hocsinh [], int, Hocsinh);

int main()
{
    Hocsinh ds[MAX], hs;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        ds[i] = hs;
    }
    InputElement(hs);
    cout << BSearch(ds, n, hs) << endl;
    return 0;
}

//###INSERT CODE HERE -

bool nhoHon(Hocsinh a, Hocsinh b){
	if (a.Ten != b.Ten) return a.Ten<b.Ten;
	if (a.Hodem != b.Hodem) return a.Hodem<b.Hodem;
	if (a.Nam != b.Nam) return a.Nam>b.Nam;
	if (a.Thang != b.Thang) return a.Thang>b.Thang;
	return a.Ngay>b.Ngay;
}

bool bang(Hocsinh a, Hocsinh b){
	return (a.Ten == b.Ten && a.Hodem==b.Hodem && a.Nam ==b.Nam && a.Thang==b.Thang && a.Ngay==b.Ngay);
}

int BSearch(Hocsinh a[], int n, Hocsinh x){
	int left =0;
	int right =n-1;
	int dem=0;
	while (left<=right){
		int mid = (left+right) /2;
		Hocsinh pivot = a[mid];
		dem++;
		if(bang(x,pivot)){
			return dem;
		}
		if (nhoHon(x,pivot)){
			right = mid -1;
		}else{
			left =mid +1;
		}
	}
	return 0;
}

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>


#define MAX 10000
#define EMPTY 0
#define NIL 0
#define DELETED -1

using namespace std;

struct Hocsinh {
    int MSHS;
    string HoTen;
    int Namsinh;
    char Gioitinh;
    double Toan, Ly, Hoa, Anh;
};


struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh table[MAX];
};

void InputElement(Hocsinh &x) {
    cin >> x.MSHS;
    getline(cin>>ws, x.HoTen);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.Toan;
    cin >> x.Ly;
    cin >> x.Hoa;
    cin >> x.Anh;
}

void OutputElement(Hocsinh x) {
    cout << x.MSHS << endl << x.HoTen << endl << x.Namsinh << endl << x.Gioitinh << endl
            << x.Toan << endl << x.Ly << endl << x.Hoa << endl << x.Anh << endl;
}

void CreateHashtable(Hashtable &, int, Hocsinh[], int);

int main()
{
    Hashtable ht;
    Hocsinh ds[MAX];
    int m, n;

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        InputElement(ds[i]);
    }

    CreateHashtable(ht, m, ds, n);

    cout << ht.M << ' ' << ht.n << endl;
    for (int i = 0; i < ht.M; i++) {
        OutputElement(ht.table[i]);
    }

    return 0;
}

//###INSERT CODE HERE -
void init(Hocsinh &h){
	h.MSHS=EMPTY;
	h.HoTen ="";
	h.Gioitinh=' ';
	h.Namsinh=0;
	h.Anh=h.Hoa=h.Ly=h.Toan=0;
}

void CreateHashtable(Hashtable & ht, int m, Hocsinh ds[], int n){
	ht.M=m;
	ht.n=0;

	//khoi tao bang bam
	for (int i=0; i<m; i++){
		init(ht.table[i]);
	}

	//Them hs vao bang

	for (int j=0; j<n; j++){
		long long base = (long long)ds[j].MSHS % ht.M;

		int i=0;
		int cur = (int)base;
		while (ht.table[cur].MSHS!=EMPTY){
			i++;
			cur=(base + i*i) % ht.M;
			if (i>=ht.M) break;
		}

		if (ht.table[cur].MSHS == EMPTY) {
            ht.table[cur] = ds[j];
            ht.n++;
        }
	}
}



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
    if (x.MSHS > 0)
        getline(cin>>ws, x.HoTen);
    else {
        x.HoTen = "";
    }

    cin >> x.Namsinh;
    if (x.MSHS > 0)
        cin >> x.Gioitinh;
    else
        x.Gioitinh = ' ';

    cin >> x.Toan;
    cin >> x.Ly;
    cin >> x.Hoa;
    cin >> x.Anh;
}

void OutputElement(Hocsinh x) {
    cout << x.MSHS << endl << x.HoTen << endl << x.Namsinh << endl << x.Gioitinh << endl
            << x.Toan << endl << x.Ly << endl << x.Hoa << endl << x.Anh << endl;
}

int Search(Hashtable, int);

int main()
{
    Hashtable ht;
    int m, n;

    cin >> m >> n;
    ht.n = n;
    ht.M = m;
    for (int i = 0; i < m; i++) {
        InputElement(ht.table[i]);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        cout << m << ' ' << Search(ht, m) << endl;
    }

    return 0;
}

//###INSERT CODE HERE -

int Search(Hashtable ht, int x){


	long long base = (long long)x % ht.M;
	int i=0;
	int cur = (int) base;

	while (ht.table[cur].MSHS != x){
		i++;
		cur=(base + i*i) % ht.M;
		if (i>=ht.M) break;
	}

	if (ht.table[cur].MSHS == x){
		return abs(i+1);
	}else{
		return -abs(i);
	}


}



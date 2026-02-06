/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <fstream>

using namespace std;

struct Word {
	string Text;
	string Explanation;
};

void loadData(Word dictionary[], int &n) {
	string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        getline(cin>>ws, s);
        dictionary[i].Text = s;
        getline(cin>>ws, s);
        dictionary[i].Explanation = s;
    }
}
void saveData(Word dictionary[], int n) {
    for (int i = 0; i < n; i++) {
        cout << dictionary[i].Text << endl << dictionary[i].Explanation << endl;
    }
}
void Sort(Word [], int );

int main() {
    Word *dictionary = new Word[15000];
	int n;
	loadData(dictionary, n);
	Sort(dictionary, n);

	saveData(dictionary, n);
	delete [] dictionary;
	return 0;
}


//###INSERT CODE HERE -

void swapWord(Word &a, Word &b) {

    string tempT = a.Text;
    a.Text = b.Text;
    b.Text = tempT;

    string tempE = a.Explanation;
    a.Explanation = b.Explanation;
    b.Explanation = tempE;
}

void QuickSortUIT(Word *vt, int left, int right) {
    while (left < right) {

        int mid = left + (right - left) / 2;
        if (vt[mid].Text < vt[left].Text) swapWord(vt[mid], vt[left]);
        if (vt[right].Text < vt[left].Text) swapWord(vt[right], vt[left]);
        if (vt[right].Text < vt[mid].Text) swapWord(vt[right], vt[mid]);

        string pivot = vt[mid].Text;
        int i = left, j = right;

        while (i <= j) {
            while (vt[i].Text < pivot) i++;
            while (vt[j].Text > pivot) j--;
            if (i <= j) {
                swapWord(vt[i], vt[j]);
                i++;
                j--;
            }
        }


        if (j - left < right - i) {
            if (left < j) QuickSortUIT(vt, left, j);
            left = i;
        } else {
            if (i < right) QuickSortUIT(vt, i, right);
            right = j;
        }
    }
}

void Sort(Word w[], int n) {
    if (n <= 1) return;


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    QuickSortUIT(w, 0, n - 1);
}

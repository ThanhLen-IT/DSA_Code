/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;



//###INSERT CODE HERE -
void inputArray(int* &a, int& n) {
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}


int binarySearch2(int* a, int n, int x) {
    
    int left = 0, right = n - 1;
    int res = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x) {
            res = mid;        
            left = mid + 1;   
        }
        else if (a[mid] > x) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return res;

}


int main()
{
    int n, * a = NULL;
    inputArray(a, n); //Luu y van de tham chieu cho con tro a va n

    // nhap cac gia tri can tim, neu nhap -1 thi ket thuc viec tim kiem
    int x;
    while (1)
    {
        cin >> x;
        if (x == -1)break;
        cout << binarySearch2(a, n, x) << endl;

    }

    return 0;
}


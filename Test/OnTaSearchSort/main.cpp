#include <iostream>
#include <vector>
using namespace std;

void nhapMang(vector<int>& vt, int n) {
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vt.push_back(x);
    }
}

void xuatMang(vector<int> vt) {
    for (int i = 0; i < vt.size(); i++) {
        cout << vt[i];
    }
}

int linearSearch(vector<int> vt, int x) {
    for (int i = 0; i < vt.size(); i++) {
        if (vt[i] == x)
            return i;
    }
    return -1;
}

int  binarySearch(vector<int> vt, int x) {
    
    int right = vt.size() - 1;
    int left = 0;
    

    while (left <= right) {
        int mid = (left + right) / 2;
        if (vt[mid] == x) return mid;
        if (x < vt[mid]) {
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return -1;
}

void selectionSort(vector<int>& vt) {
    int n = vt.size();
    for (int i = 0; i < n-1; i++) {
        int minId = i;
        for (int j = i + 1; j < n; j++) {
            if (vt[j] < vt[minId])
                minId = j;
        }
        swap(vt[i], vt[minId]);
    }
}

void bubbleSort(vector<int>& vt) {
    int n = vt.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vt[j] < vt[i]) {
                swap(vt[j], vt[i]);
            }
        }
    }
}

void insertionSort(vector<int>& vt) {
    int n = vt.size();
    for (int i = 0; i < n; i++) {
        int key = vt[i];
        int j;
        for (j = i - 1; j >= 0 && vt[j] > key; j--) {
            vt[j+1] = vt[j];
        }
        vt[j + 1] = key;
    }
}

void quickSort(vector<int>& vt, int left, int right) {
    int mid = (left + right) / 2;
    int pivot = vt[mid];
    int i = left, j = right;

    while (i <= j) {
        while (vt[i] < pivot) i++;   
        while (vt[j] > pivot) j--;   // tăng dần (>)

        if (i <= j) {
            swap(vt[i], vt[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(vt, left, j);
    if (i < right) quickSort(vt, i, right);
}

void merge(vector<int>& vt, int left,int mid, int right) {
    vector<int> L, R;
    for (int i = left; i <= mid; i++) L.push_back(vt[i]);
    for (int i = mid + 1; i <= right; i++) R.push_back(vt[i]);

    int i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        vt[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    }

    while (i < L.size()) vt[k++] = L[i++];
    while (j < R.size()) vt[k++] = R[j++];
}

void mergeSort(vector<int>& vt, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;

    mergeSort(vt, left, mid);
    mergeSort(vt, mid + 1, right);
    merge(vt, left, mid, right);
}


void MENU(vector<int>& a) {
    int choice, n, x;

    while (true) {
        cout << "\n===== MENU SEARCH & SORT =====\n";
        cout << "1. Nhap mang\n";
        cout << "2. Xuat mang\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search (yeu cau mang da sap xep)\n";
        cout << "5. Selection Sort\n";
        cout << "6. Bubble Sort\n";
        cout << "7. Insertion Sort\n";
        cout << "8. Quick Sort\n";
        cout << "9. Merge Sort\n";
        cout << "10. Thoat\n";
        cout << "===============================\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        if (choice == 10) break;

        switch (choice) {
        case 1:
            cout << "Nhap so phan tu: ";
            cin >> n;
            cout << "Nhap mang: ";
            nhapMang(a, n);
            break;

        case 2:
            cout << "Mang: ";
            xuatMang(a);
            break;

        case 3:
            cout << "Nhap gia tri can tim: ";
            cin >> x;
            cout << "Vi tri: " << linearSearch(a, x) << endl;
            break;

        case 4:
            cout << "Nhap gia tri can tim: ";
            cin >> x;
            cout << "Vi tri (binary): " << binarySearch(a, x) << endl;
            break;

        case 5:
            selectionSort(a);
            cout << "Da sap xep (Selection Sort)\n";
            break;

        case 6:
            bubbleSort(a);
            cout << "Da sap xep (Bubble Sort)\n";
            break;

        case 7:
            insertionSort(a);
            cout << "Da sap xep (Insertion Sort)\n";
            break;

        case 8:
            quickSort(a, 0, a.size() - 1);
            cout << "Da sap xep (Quick Sort)\n";
            break;

        case 9:
            mergeSort(a, 0, a.size() - 1);
            cout << "Da sap xep (Merge Sort)\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }
    }
}

// =============================== MAIN ===============================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a;
    MENU(a);
    return 0;
}
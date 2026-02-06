#include <iostream>
#include <vector>
using namespace std;



void insertionSort(vector <int>& a, int n) {
    for (int i = 0; i < n; i++) {
        int key = a[i];
        int j;
        for (j = i - 1; j >= 0 && a[j] > key ; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
}
void selectionSort(vector <int>& a, int n) {
    for (int i = 0; i < n-1; i++) {
        int minId = i;
        for (int j = i + 1; j < n; j++) {
            if (a[minId] > a[j])
                minId = j;
        }
        swap(a[i], a[minId]);
    }
}

void quickSort(vector <int>& a, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    int i = left, j = right;
    int pivot = a[mid];
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    quickSort(a, left, j);
    quickSort(a, i, right);

}

void merge(vector<int>& a, int left,int mid, int right) {
    vector<int> L;
    vector<int> R;
    for (int i = left; i <= mid; i++) {
        L.push_back(a[i]);
    }
    for (int i = mid + 1; i <= right; i++) {
        R.push_back(a[i]);
    }
    int i = 0, j = 0, k=left;
    while (i < L.size() && j< R.size()) {
        if (L[i] <= R[j]) {
            a[k]= L[i++];
            k++;
        }
        else {
            a[k] = R[j++];
            k++;
        }
    }

    while (i < L.size()) a[k++] = L[i++];
    while (j < R.size()) a[k++] = R[j++];


}

void mergeSort(vector<int>& a, int left, int right) {

    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
    
}


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x;
    cin >> x;   // giá trị cần search

    // Copy mảng cho từng thuật toán
    vector<int> ins = a;
    vector<int> sel = a;
    vector<int> qui = a;
    vector<int> hea = a;
    vector<int> mer = a;

    // Sort
    insertionSort(ins, n);
    selectionSort(sel, n);
    quickSort(qui, 0, n - 1);
    //heapSort(hea, n);
    mergeSort(mer, 0, n - 1);

    // In kết quả
    auto print = [&](string name, vector<int>& v) {
        cout << name << ": ";
        for (int x : v) cout << x << " ";
        cout << '\n';
        };

    print("Insertion Sort", ins);
    print("Selection Sort", sel);
    print("Quick Sort", qui);
    //print("Heap Sort", hea);
    print("Merge Sort", mer);

    //// Search
    //cout << "Linear Search index: "
    //    << linearSearch(a.data(), n, x) << '\n';

    //cout << "Binary Search index (on Merge Sort): "
    //    << binarySearch(mer.data(), n, x) << '\n';

    return 0;
}

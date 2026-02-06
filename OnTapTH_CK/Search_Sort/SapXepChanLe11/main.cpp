/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <vector>

using namespace std;

void Sort(vector<int> &);

int main()
{
    int n, k;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        nums.push_back(k);
    }
    Sort(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}


//###INSERT CODE HERE -
void QuickSort(vector<int> & vt, int left, int right){
	if (left >= right) return;
	int mid = (left+right)/2;
	int pivot = vt[mid];
	int i=left, j=right;
	while (i<=j){
		while (vt[i] < pivot) i++;
		while (vt[j] > pivot) j--;

		if (i<=j){
			swap(vt[i],vt[j]);
			i++;
			j--;
		}
	}

	QuickSort(vt, left, j);
	QuickSort(vt, i, right);
}

void Sort(vector<int> & vt){
	vector<int> vt1;
	vector<int> vt2;
	for(int i=0; i<vt.size(); i++){
		if (vt[i]%2==0)
			vt1.push_back(vt[i]);
		else
			vt2.push_back(vt[i]);
	}
	QuickSort(vt1,0,vt1.size()-1);
	QuickSort(vt2,0,vt2.size()-1);
	vt.clear();
	int idx = 0;
    for (int x : vt1) vt[idx++] = x;
    for (int x : vt2)  vt[idx++] = x;
}

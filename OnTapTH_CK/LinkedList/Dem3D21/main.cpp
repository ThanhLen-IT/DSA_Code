/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
set
nth_element
priority_queue
sort_heap
multiset
map
multimap
###End banned keyword*/
//###INSERT CODE HERE -

#include <iostream>
#include <vector>

using namespace std;

struct Point3D{
	int x,y,z;
};

bool cmp3D(Point3D a, Point3D b){
    if (a.x != b.x) return a.x > b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.z > b.z;
}
void quickSort(vector<Point3D>& vt, int left, int right){
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    Point3D pivot = vt[mid];

    int i = left, j = right;
    while (i <= j){
        while (cmp3D(pivot, vt[i])) i++;
        while (cmp3D(vt[j], pivot)) j--;

        if (i <= j){
            swap(vt[i], vt[j]);
            i++; j--;
        }
    }

    if (left < j) quickSort(vt, left, j);
    if (i < right) quickSort(vt, i, right);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin>>N;

	vector<Point3D> vt;

	for (int i=0; i<N; i++ ){
		Point3D p;
		cin>> p.x >> p.y >>p.z;
		vt.push_back(p);
	}

	quickSort(vt, 0, N-1);

	for (int i=0; i<N; i++){
		cout<<vt[i].x <<" " <<vt[i].y<<" "<<vt[i].z<<"\n";
	}
}

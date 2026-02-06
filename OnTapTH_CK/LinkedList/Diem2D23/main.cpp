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
#include <algorithm>

using namespace std;

struct Point2D{
	int x,y;
};

bool cmp2D(const Point2D& a,const Point2D &b){
	if (a.x != b.x) return a.x < b.x;
	return a.y > b.y;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin>>N;

	vector<Point2D> vt;

	for (int i=0; i<N; i++){
		Point2D p;
		cin>>p.x>>p.y;
		vt.push_back(p);
	}

	sort(vt.begin(), vt.end(), cmp2D);


	for (int i=0; i<N; i++){
		cout<<vt[i].x<<" "<<vt[i].y<<"\n";
	}
}

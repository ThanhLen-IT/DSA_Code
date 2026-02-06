#include <iostream>
#include <vector>
using namespace std;

struct point3D{
	double x, y, z;
};

bool bang(point3D p, point3D q){
	return (p.x==q.x) && (p.y==q.y) && (p.z==q.z);
}
void input(point3D& p){
	cin>>p.x>>p.y>>p.z;
}

bool nhoHon(point3D a, point3D b){
	if (a.x != b.x) return a.x < b.x;
	if (a.y != b.y) return a.y < b.y;
	return a.z<b.y;
}

int search(point3D *p, int n,  point3D q){
	int left =0;
	int right = n-1;
	int dem=0;
	while (left<=right){
		int mid = (left+right)/2;
		point3D tmp= p[mid];
		dem++;
		if (bang(tmp,q)){
			return dem;
		}
		if (nhoHon(q,tmp)){
			right=mid -1;
		}else{
			left= mid+1;
		}
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin>> n;
	point3D *p= new point3D[n];
	for (int i=0; i<n; i++){
		input(p[i]);
	}

	cin>>m;
	for(int i=0; i<m; i++){
		point3D q;
		cin>>q.x>>q.y>>q.z;
		int dem= search(p,n,q);
		if (dem==-1){
			cout<<"KHONG"<<endl;
		}else{
			cout<<dem<<endl;
		}
	}
	return 0;

}

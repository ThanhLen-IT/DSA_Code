#include <iostream>
using namespace std;

struct Point3D {
    double x, y, z;
};

int compare(Point3D a, Point3D D) {
    if (a.x == D.x && a.y == D.y && a.z == D.z)
        return 0;

    if (a.x > D.x) return 1;
    if (a.x < D.x) return 2;

    if (a.y > D.y) return 1;
    if (a.y < D.y) return 2;

    if (a.z > D.z) return 1;
    if (a.z < D.z) return 2;

    return 0;
}

void BSort(Point3D* a, int left, int right, Point3D D) {
    int dem = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        dem++;

        int c = compare(a[mid], D);

        if (c == 0) {
            cout << dem << endl;
            return;
        }

        if (c == 1) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << "KHONG" << endl;
}

int main() {
    int n;
    cin >> n;
    Point3D* a = new Point3D[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }

    int m;
    cin >> m;
    Point3D* b = new Point3D[m];

    for (int i = 0; i < m; i++) {
        cin >> b[i].x >> b[i].y >> b[i].z;
        BSort(a, 0, n - 1, b[i]);
    }

    return 0;
}

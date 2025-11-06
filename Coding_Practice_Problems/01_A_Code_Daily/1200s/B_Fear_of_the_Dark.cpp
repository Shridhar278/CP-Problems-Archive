#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int px, py, ax, ay, bx, by;
        cin >> px >> py >> ax >> ay >> bx >> by;
        double ab = distance(ax, ay, bx, by);
        double ap = distance(ax, ay, px, py);
        double bp = distance(px, py, bx, by);
        double porg = distance(px, py, 0, 0);
        double aorg = distance(ax, ay, 0, 0);
        double borg = distance(bx, by, 0, 0);
        double final_dist = 0;
        bool intersect=true;
        if ((min(ap, aorg) >= max(bp, borg))||(min(bp, borg) >= max(ap, aorg))) {
            intersect=false;
        }
        if (intersect==false) {
            final_dist = min(max(ap, aorg), max(bp, borg));
        } else {
            final_dist = max({ab/2, min(ap, bp), min(aorg, borg)});
        }
        cout<<fixed<<setprecision(10)<<final_dist<<endl;
    }
    return 0;
}
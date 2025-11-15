#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n, alice, x; cin >> n >> alice;
        vector <int> marbles;
        for (int i=0;i<n;i++) {
            cin >> x; marbles.push_back(x);
        }
        sort(marbles.begin(), marbles.end());
        // remove similars
        vector<int> new_m = {marbles[0]}; int s=1;
        for (int i=1;i<n;i++) {
            if (marbles[i]!=marbles[i-1]) {
                new_m.push_back(marbles[i]); s++;
            }
        } n=s;
        int count=0, no_sol=1;
        if (n==1) {
            cout<<new_m[0]<<endl; continue;
        }
        while( count !=n ) {
            if (new_m[count] == alice) {
                no_sol=0;
                int y = count; int rev=0;
                int x1, x2;
                while (new_m[y] == new_m[count]) {
                    if (y==n-1) {
                        break;
                    }
                    if (y==0) {
                        rev=1;
                    }
                    if (rev) {
                        y++;
                    } else {
                        y--;
                    }
                }
                cout<<new_m[y]<<endl;
                break;
            }
            if (new_m[count] > alice) {
                no_sol=0;
                if (count==(n+1)/2) {
                    cout<<alice+1<<endl;
                } else if (count > (n+1)/2) {
                    cout<<alice-1<<endl;
                } else {
                    cout<<alice+1<<endl;
                }
                break;
            }
            count++;
        }
        if (no_sol) {
            cout<<new_m[0];
        }
    }
    return 0;
}
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
        int n, k, ele; cin >> n >> k;
        vector<int> modk(k, 0);
        for (int i=0; i<n;i++) {
            cin >> ele;
            modk[ele%k]++;
        }
        // going through each x mod k
        int count = 0;
        for (int i=0;i<=k/2;i++) { // going through to make the other cancel out
            if ((i==0 || (k%2==0 && i==k/2)) && modk[i]!=0) { // mod 0 , mod k (2k) and atlest one ele rqr.
                count++;
                continue;
            } else if (i!=0) { // cuz. 0 mod k can go to modk[k-i]->modk[k] #issues // covers everything but 0 mod k
                int extras = max(modk[i], modk[k-i])-min(modk[i], modk[k-i]);
                if (modk[i]!=0||modk[k-i]!=0) {
                    count++;
                if (extras > 1) { // ex. ax2 bx5 then babab (count++), b, b count+extras(3)-1
                    count+=extras-1;
                }
                } else {
                    // the zero zero case
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
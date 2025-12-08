#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// BOOM ! : FOUND an ALGORITHM :D
// runs at O(n log n) while since it was n <= 5000
// did better, i did it in O(n log n) only :D
/* skill unlocked: sort the array while retaining original indices :
do entity*INF + index then %INF to get INDEX */

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        int n; cin >> n;
        int og, fail=1;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (i == 0)
                og = arr[i];
            else if (arr[i] != og) {
                fail = 0;
            }
            arr[i] *= INF;
            arr[i] += i+1;
            // to retain original indices after sorting by diving by INF
        }
        if (fail) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        // # NEW ALGO keep element ONE hostage and move along the old ALGO
        sort(arr.begin(), arr.end());
        int p1 = 1, p2 = 1;
        while (true) {
            // cout<<"$"<<arr[p2-1]/INF<<" DEBUG: p1="<<p1<<" p2="<<p2<<"\n";
            if (p2 == n) {
                for (int i = p1; i < p2; i++) {
                    cout << (arr[i]%INF) << " " << (arr[0]%INF) << "\n";
                    // cout << (arr[i]/INF) << " " << (arr[0]/INF) << "\n";
                }
                break;
            }
            if (arr[p1]/INF == arr[p2]/INF) {
                p2++;
            } else {
                for (int i = p1; i < p2; i++) {
                    cout << (arr[i]%INF) << " " << (arr[p2]%INF) << "\n";
                    // cout << (arr[i]/INF) << " " << (arr[p2]/INF) << "\n";
                }
                p1 = p2;
                p2++;
            }
        }
    }
    return 0;
}
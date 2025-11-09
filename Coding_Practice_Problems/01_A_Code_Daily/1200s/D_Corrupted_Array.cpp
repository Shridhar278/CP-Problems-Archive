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
        int n; cin>>n; 
        int sum_arr=0; int num;
        vector <int> arr;
        for (int i=0;i<n+2;i++) {
            cin >> num;
            arr.push_back(num);
            sum_arr += num;
        }
        sort(arr.begin(), arr.end());
        int case1=0, case2=0;
        // case last ignore
        if (sum_arr - arr[n+1] == 2*arr[n]) {
            case1=1;
        }
        // case ignore in between LAST is BOSS
        int i;
        for (i=0;i<n+1;i++) {
            if (sum_arr - arr[i] == 2*arr[n+1]) {
                case2=1;
                break;
            }
        }

        if (case1) {
            for (int i=0;i<n;i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else if (case2) {
            for (int j=0;j<n+1;j++) {
                if (i!=j) {
                    cout << arr[j] << " ";
                }
            }
            cout << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
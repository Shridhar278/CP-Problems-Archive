#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9
#define modi 998244353

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int factorial(int n) {
    if (n==0) {
        return 1;
    } else {
        return (factorial(n-1)*n)%modi;
    }
}

int nCr(int n, int r) {
    float ans=1;
    for (float x=n;x>n-r;x--) {
        ans=((ans*x)/(n+1-x));
    }
    return ((int)ans)%modi;
}

// F off i don't CARE let's SEE where it is
// go to the other .cpp

void solve() {
    int n; cin >> n;
    vector<int> arr(n+1);
    for (int i=0;i<n+1;i++) {
        cin >> arr[i];
    }
    int help=0;
    sort(arr.begin()+1, arr.end());
    int i=1;
    for (;i<n+1;i++) {
        // cout<<arr[0]<<" "<<help<<" "<<arr[i]<<endl;
        if (arr[i]==arr[n]) {
            break;
        }
        help+=(arr[n]-arr[i]-1);
        if (help>arr[0]) {
            cout<<0<<endl;
            return;
        }
    }
    int last = n+1-i;
    int afford = arr[0]-help;
    if (afford+last > n) {
        afford = n-last;
    }
    // cout<<last<<" "<<afford<<endl;
    int ways = (factorial(last+afford)*nCr(n-last, afford))%modi;
    // last+afford TRULY arranged
    // cout<<ways<<endl;
    ways = (ways*factorial(n-last-afford))%modi;
    // rest arranged
    cout<<ways<<endl;
}

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
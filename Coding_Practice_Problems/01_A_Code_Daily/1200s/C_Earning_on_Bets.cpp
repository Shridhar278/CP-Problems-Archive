#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9+7
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// IT WORKS
// learnt about floating point precision issues

int32_t main() {
    fast_io();
    int test;
    cin >> test;
    while (test--) {
        vector <int> nums; int prod=1; int n; int k;
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> k;   
            // if product form works, then this ALSO do PROVABLE
            // just something to take stuff from, any multiple of lcm works
            prod = (prod*k)/__gcd(prod, k);
            nums.push_back(k);
        } double harmonic_sum = 0;
        for (int i=0;i<n;i++) {
            harmonic_sum += 1.0/nums[i];
        }
        // can be proved if sum of 1/k's over then contradicts the condition
        // use epsilon to handle floating point precision issues
        if (harmonic_sum >= 1.0 - EPS) {
            cout<<-1<<endl;
            continue;
        }
        for (int i=0;i<n;i++) {
            cout<<prod/nums[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
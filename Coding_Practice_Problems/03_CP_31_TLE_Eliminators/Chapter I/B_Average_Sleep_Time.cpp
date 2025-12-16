#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9 + 7
#define EPS (double)1e-9

inline void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// use DOUBLE as 53 binary bits == 16 decimal bits for precision
// this is more ACCURATE

// FLOAT has only 23 binary bits == 7 decimal bits for precision
// but since, its asked to CORRECT till 10^-6 precision FLOAT is ENOUGH
// use double only for self satisfaction

int32_t main()
{
    fast_io();
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int curr = 0, ttl = 0;
    float num = n - k + 1;
    for (int i = 0; i < k; i++) {
        curr += arr[i];
    }
    ttl += curr;
    for (int i = k; i < n; i++) {
        curr += arr[i];
        curr -= arr[i-k];
        ttl += curr;
    }
    cout<<fixed<<setprecision(10)<<ttl/num<<endl;
    return 0;
}
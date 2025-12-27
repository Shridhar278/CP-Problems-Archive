#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)(1e9+7)
#define EPS (double)1e-9

inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// screw IT

// void solve(map<int, vector<int>> primes, vector<int> p) {
//     int n, x; cin >> n;
//     int mx=1;
//     vector<int> nums(n);
//     vector<vector<int>> factors(n);
//     vector<int> colors(n);
//     for (int i=0;i<n;i++) {
//         cin >> x;
//     }
//     for (int i=0;i<n;i++) {
//         vector<int> current;
//         int none = 1;
//         for (int a=0;a<factors.size();a++) {
//             for (int b=0;b<factors[a].size();b++) {
//                 if (nums[i]%factors[a][b]==0) {
//                     none = 0;
//                     colors[i]=a;
//                 }
//             }
//         }
//         if (none) {
//             factors.push_back
//             for (int j=0;j<p.size();j++) {
//                 if (nums[i]%p[j]==0) {
                    
//                 }
//             }
//             colors[j] = ++mx;
//         }
//     }
//     cout<<mx<<endl;
//     for (int i=0;i<n;i++) {
//         cout<<colors[i]<<" ";
//     }
//     cout<<endl;
// }

// int32_t main() {
//     fast_io();
//     map<int, vector<int>> primes;
//     vector<int> p;
//     for (int n = 2; n < 1000; n++) {
//         bool prime = true;
//         for (int i = 2; i * i <= n; i++) {
//             if (n % i == 0) {
//                 prime = false;
//                 break;
//             }
//         }
//         if (prime) {
//             primes[prime]={};
//             p.push_back(prime);
//         }
//     }
//     int test;
//     cin >> test;
//     while (test--) {
//         solve(primes, p);
//     }
//     return 0;
// }

// WATCHING solutions